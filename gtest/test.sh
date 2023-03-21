#bin/bash

if [ -d "build" ]; then
	rm -r build/
	echo Remove build directory...
fi
cmake -DCMAKE_BUILD_TYPE=Debug -S ./ -B ./build &&\
cmake --build ./build &&\
./build/runtest;

