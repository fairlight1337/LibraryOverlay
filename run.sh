#!/bin/bash

mkdir -p build
cd build
cmake ..
make
cd -

LD_PRELOAD=lib/libX11.so $1
