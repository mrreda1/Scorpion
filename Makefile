cc = g++
debugFlags = -Wall -g

.PHONY : test
test :
	$(cc) testing/* $(debugFlags) -o test
