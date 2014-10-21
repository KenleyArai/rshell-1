# Flags placed after the g++ compiler
opt= -Wall -Werror -ansi -pedantic

compiler= "g++"

all:
	mkdir -p bin
	g++ $(opt) src/main.cpp -o bin/rshell
	top
	ls -a
	ls -l	        	

rshell:
	mkdir -p bin
	g++ $(opt) src/main.cpp -o bin/rshell
	top
	ls -a
	ls -l
