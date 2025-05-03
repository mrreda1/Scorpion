cc = g++
debugFlags = -Wall -g

.PHONY : test
test :
	$(cc) testing/*.cpp $(debugFlags) -o test
