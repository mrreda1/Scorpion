cc = g++
debugFlags = -Wall -g

test : testing/*
	$(cc) testing/* $(debugFlags) -o test
