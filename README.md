GISMo

# Introduction
After a long search, I have failed to find a servo motor that does everything I need for my projects that is also cheap(ish) and fully programmable (say no to closed source stuff whenever you can).

Well, thus was born the idea of G.I.S.Mo (Greatly Inteligent Servo Motor). This project aims to develop a board that can be used to replace the vanilla servo driver boards that comes with cheaper ones such as MG995 and MG996R, giving it more power and making it more usefull for distributed controll projects:

Amongst the desired dream come true features we have the following:
* Embedded MCU for controll loops (with multiple modes to choose from)
** Simple position PID loop
** MISO controller for speed and position simultaniously (Probably a state space controller)
** Torque controll loop
* I2C interface (or if you please, just change a bit the circuit to use whatever interface you want)
* Current sensing (for torque controll and power management features)
* Programable LED's (because they are cool)
* Absolute magnetic encoder (at least 12bits)
* Free range of movement (180 degrees is just not enough)

# FAQ
I have barely started this project and everytime I tell somebody about it, I get the same questions, so here we go:

* Why not use a normal DC motor with drivers tailored for each project:
** Cause I like modular! It saves time and you dont have to do everything multiple times. Plus, a lot of the stuf you find online if you are 3D printing, is already made for this size motor. Plus Plus, sorting out motor specifications, gearboxes, making gears (when necessary) is all just a pain, this one can do a lot of the stuff I need for anyway (robotic arms and legged robots).

* Why not just buy a smart servo? this one will probably cost almost the same as the comercial ones.
** For one, i Hope to make it at least the same price as the "cheap" smart servos. But really, mainly, so I can have full power over its features and its firmware. Also cause its fun!

For now that is it, lets see what comes next :)

# License
Everything under this repository is free to use unless it is used to generate profit. The license states that it CAN be used for comercial puproses, however an agreement have to be reached between the original creator of this project (Werner Thomassen Andrade) and the interested parties before that can happens.