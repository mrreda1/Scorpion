cc = g++
debugFlags = -Wall -g
main = src/main.cpp
scanner = src/scanner/*.cpp
parser = src/parser/*.cpp
src_files = $(main) $(scanner) $(parser)

.PHONY : build
build :
	$(cc) $(src_files) $(debugFlags) -o run

.PHONY : test
test :
	$(cc) $(src_files) $(debugFlags) -o test
