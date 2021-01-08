
CC = g++

all: core/json.hpp core/json.cpp
	g++ --std=c++14 -Icore/ core/json.cpp 
