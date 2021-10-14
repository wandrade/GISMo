# G.I.S.Mo Firmware

This section of the repo is all about the firmware powering the board. Architecture, implementation decisions, methods and so on.

# Overall Structure
The firmware has a few main components:
- PWM position encoder reading
- Motor current reading
- Control algorithms
- Communications and interface

Each one will be detailed as they are developed
## Softwares and tools
CubeMX
CubeMonitor
CubeIDE

## I²C interface
To learn more about it and how to implemente it go to these articles:
* https://deepbluembedded.com/stm32-i2c-tutorial-hal-examples-slave-dma/
* https://visualgdb.com/tutorials/arm/stm32/i2c/

and have a look. It is very easy and well explained, starting from the theory then jumpping into the implementation used by STM32 MCUs

## PWM Encoder
### Choosing an encoder
This projects aims to use either the magnetic encoder [AS5600](https://www.mouser.co.uk/datasheet/2/588/AS5600_DS000365_5-00-1877365.pdf) or [AS5048x](https://ams.com/documents/20143/36005/AS5048_DS000298_4-00.pdf/910aef1f-6cd3-cbda-9d09-41f152104832). They both have the same PWM interface so it should be just a matter of choosing your preference and it will work.

They are part of a [family of magnetic absolute encoders](https://ams.com/angle-position-on-axis) that can read the orientation of a magnet with respect to the chip with high precision and speed.
The chips are robust to external magnetic fields, temperature changes and slight mechanical variations such as eccentricity and distance from the chip, making it a very robust and easy to use option. The downside? Cost, mor on that soon.


So I reckon that 12bits (that is down to 0.08789 degrees)it more than enough in terms of precision for a smart servo and the purposes that we are aiming for here, there are cheaper versions of such encoders that have a smaller precision such as 10bits but that is just not enough. of course if 14 and 16 and 22 bit would be awesome... but not so much when we have every intention of making at least 12 of these motors to build a nice robot spider.  So on that range there are a few choices as you can see in the links above, but two of them caught my attention and here is why:

- AS5600 - One of the cheapest ones, goes for around £2.50 a pop. downside is that you have to pre-configure the PWM output to run at a high frequency, and it only get to 920Hz.
- AS5048x - 3 Times the price of the above, but its slightly faster (1Khz) and come ready t go, you just solder it to the PCB and plug it in.

Arguably that is not fast enough for a position encoder, especially since we are deriving the speed out of it too. But for most applications that should be enough. If not then hey! this is open source! feel free to slightly change the pins you expose for the sensor and you can use something faster or with better precision such as the AS5048 SSI interface or any other encoder that suits you really.

### Reading it
While explaining how i have implemented the sensor reading, I assume you have the code open on the other half of the screen so you can actually know what im talking about.

Now on the datasheet there is a nice diagram of the PWM signal that you can expect out of the chip (just click on the link of the previous section of any of the encoders and search for 'PWM' you will find it in no time).

For reading a PWM without risking to loose any valuable readings due to bad implementation (and after much trial and error), I have found that the best way is to get a timer on the pin that has both direct and indirect capture on separate channels (Just open the CubeMX project and look at how timer 1 is configured).

This will allow me to start 2 interrupts on the same pin, one for the rising edge of the PWM and another for the falling edge.
As stated in the datasheet, the signal is not 100% information, you have in total 4119 clocks on each cycle, 12 are always high as a 'init' bit set, then there are 4 reserved for errors, then the next 4095 are the actual data and finally some more 8 clocks that are always low, as e 'exit' bit set.

The full duty cycle can vary a little bit, so its better to also read the period of each one to use in the calculations so we have a more precise measure. Right to continuing...

You set an interrupt at the falling edge (after the duty cycle is completed) but you don't need to set up a callback function for it. All we need to know is when that edge ocurred, and we don't need to waste CPU time putting that into a variable, since the chip already does that for us, we just have to access it like 'htim1.Instance.CCR#' where # is the number of the channel that got interrupted.

On the rising edge tho, we want to have a callback, but it has to be really fast (otherwise we wont have enough CPU for al the rest), in order to spent less CPU time on bullshit, I have disabled the code generation for timer1 (On cubeMX System Core->NVIC->Tim1 capture compare interrupt) because the HAL implementation of it that all tutorials tell you to use do LOADS of ifs and elses to check what sort of interrupt that is and that is just a waste of time, since we know what timer 1 is being used for. After disabling the code generation, all we have to do is define the 'void TIM1_CC_IRQHandler(void)' function on the main and that is our callback, simple as that. (look at the code for the other stuff you have to do in there).

Now that the callback is handled, what we need to do to fully read our position goes as follow (and you can see the full implementation just by following everything in void TIM1_CC_IRQHandler(void) on main.c):

- Reset timer - We want the timer count to start at the beginning of the cycle, and then finish at the end of it (obviously) and that will be your full period time.
- Save CCR3 and CCR4 (interupt times of rising and falling edges) ASAP - They get overwritten when another interrupt comes in, so we want to save that into another variable to be able to use it reliably all the way trough.
- Transform the timer count of our CPU (which is running at 64Mhz, so around 64K counts per period) to the clock timing of the sensor, which is 4119 per cycle.
- Process the data
    - Some error checking is always good (if there is not enough clock times that means that there is an error on the sensor, if there is too much it means there is no sensor at all).
    - Calculate the position of the encoder
    - (Optional) Count the number of turns that happened for multiturn applications.
    - Put both single turn position and multiturn count in one variable. why?
        - After the callback finishes, we need to read those values on lower priority threads to actually use it, so you want to be sure that you have read the whole thing before starting to process. If you have to read two variables, you might get interrupted after reading the first one, then another measures come in and then you read the second one of a different reading, so you get inconsistent data.
        - If you put them together like i did there, you have just one number that tells you the absolute position including multiturn, it just works nicely, and you only have to scale the thing once to transform from raw to readable angle.
- That is it!

The thread that does this will have the highest priority of the bunch for reasons that will be explained in the section appropriate for that. (You can set this priority on CubeMx under System Core->NVIC->Tim1 capture compare interrupt).

Maybe i'll put some diagrams and pictures here in the future to make this easier to understand, who knows?!

