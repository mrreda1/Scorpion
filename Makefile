cc = g++
debugFlags = -Wall -g

.PHONY : test
test :
	$(cc) testing/*.cpp $(debugFlags) -o test

.PHONY : build
build :
	$(cc) src/*.cpp $(debugFlags) -o run
