#This is a WIP guide to get cmake and lm4flash working for the TM4C123

## STEP ONE ##

#Get make and cmake if you don't already have
pacman -S make cmake 
#Get arm gcc toolchain from package manager
pacman -S arm-none-eabi-gcc arm-none-eabi-newlib

## STEP TWO ##

#Download TivaWare for C, google SW-TM4C
#Go to your projects or whatever folder
cd $HOME/Documents/tiva-projects
mkdir tivaware
cd tivaware
mv ~/Downloads/SW-TM4C-2.1.4.178.exe .
unzip SW-TM4C-2.1.3.178.exe
make

## STEP THREE ##

#Install lm4flash from AUR or manually from github

#This is how my directory is setup
.
├── build
├── CMakeLists.txt
├── inc
│   └── tm4c123gh6pm.h
├── src
│   ├── blinky.c
│   └── startup.c
├── tiva.specs
├── tm4c123g.cmake
└── tm4c123g.ld


## STEP FOUR ##

#We can now build our project
cd build
cmake ..
make
sudo make flash

#Our blinky progam should now be on the board, woohoo!
