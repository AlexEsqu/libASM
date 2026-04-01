#!/usr/bin/env bash

#Criterion Installer for ubuntu dump 42
# Honteusement volé à Rokerjea, voir:
# https://github.com/RoKerjea/Criterion-demo-42/blob/main/criterion_install.sh

#check if Criterion is already installed
if [ -d "$HOME/Criterion" ] && [ -f "$HOME/Criterion/build/src/libcriterion.so" ]; then
    exit 0
fi

if pkg-config --exists criterion 2>/dev/null; then
    exit 0
fi

#installation of meson and ninja to build criterion
pip3 install --user meson
python3 -m pip install ninja

#creation of new PATH variable to find meson and ninja
export "PATH=$HOME/.local/bin:$PATH"

#dowloading criterion on a usable folder at the home level
cd ~

git clone --recursive git@github.com:Snaipe/Criterion.git

cd Criterion

meson build

ninja -C build

#now you should be able to use criterion library by compiling like this:
#gcc -o "binary name" "files"
#-I$HOME/Criterion/include/criterion
#-Wl,-rpath=$HOME/Criterion/build/src -L$HOME/Criterion/build/src
#-W -Wall -Wextra -Werror -lcriterion
