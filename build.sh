#!/bin/sh

generate_include() {
	for var in "$@"
	do
		echo "#include \"$var\""
	done
}

mkdir build
cd build

generate_include ../raytracer/*.cpp > _all.cpp

c++ -std=c++11 -Ofast -o raytracer _all.cpp

rm _all.cpp

echo Look into \"build\" folder for build result
