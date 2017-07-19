#This is a guide to get cmake and opencd working with the TM4C123

## STEP ONE ##

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

