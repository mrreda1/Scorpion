cc = g++
debugFlags = -Wall -g

.PHONY : build
build :
	$(cc) src/**.cpp $(debugFlags) -o run

.PHONY : test
test :
	$(cc) testing/**.cpp $(debugFlags) -o test
