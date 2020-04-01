#!/bin/zsh

if [[ -d build/ ]]; then
  echo "Deleting previous build folder";
  rm -rf build/
fi

mkdir build; cd ./build; 
cmake .. && cmake --build .;
# make -j4;
