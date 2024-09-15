sudo tar xjf gcc-arm-none-eabi-YOUR-VERSION.bz2 -C /usr/share/

sudo ln -s /usr/share/gcc-arm-none-eabi-YOUR-VERSION/bin/arm-none-eabi-gcc /usr/local/bin/arm-none-eabi-gcc 
sudo ln -s /usr/share/gcc-arm-none-eabi-YOUR-VERSION/bin/arm-none-eabi-g++ /usr/local/bin/arm-none-eabi-g++
sudo ln -s /usr/share/gcc-arm-none-eabi-YOUR-VERSION/bin/arm-none-eabi-gdb /usr/local/bin/arm-none-eabi-gdb
sudo ln -s /usr/share/gcc-arm-none-eabi-YOUR-VERSION/bin/arm-none-eabi-size /usr/local/bin/arm-none-eabi-size
sudo ln -s /usr/share/gcc-arm-none-eabi-YOUR-VERSION/bin/arm-none-eabi-objcopy /usr/local/bin/arm-none-eabi-objcopy

sudo apt install libncurses-dev
sudo ln -s /usr/lib/x86_64-linux-gnu/libncurses.so.6 /usr/lib/x86_64-linux-gnu/libncurses.so.5
sudo ln -s /usr/lib/x86_64-linux-gnu/libtinfo.so.6 /usr/lib/x86_64-linux-gnu/libtinfo.so.5

install USBIP Connect vscode extention in wsl
install the client on windows host
(follow instructions on extention page)

sudo apt install openocd

install extension VsCode Action Buttons