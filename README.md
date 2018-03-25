# snes_linux
A USB controller driver for Ubuntu Linux 16.04

Built upon a sample USB driver found here : http://opensourceforu.com/2011/11/usb-drivers-in-linux-2/

<<<<<<< HEAD
To install:\ 
make\
sudo insmod snes_driver.ko\

To see the driver working effectively :\
*Ensure there is no other drivers capable of handling the device loaded*\
*Plug in and unplug the devices*\
Run "dmesg" to check the kernel log and see the device connecting and disconnecting]\

To uninstall:\
sudo rmmod snes_driver\
=======
To install: 
make
sudo insmod snes_driver.ko

To see the driver working effectively :
*Ensure there is no other drivers capable of handling the device loaded*
*Plug in and unplug the devices*
Run "dmesg" to check the kernel log and see the device connecting and disconnecting

To uninstall:
sudo rmmod snes_driver
>>>>>>> eb3bf70af7d5e7bfa3791f3357a453a67908b246
