# Flags placed after the g++ compiler
opt= -Wall -Werror -ansi -pedantic

compiler= "g++"

all:
	mkdir -p bin
	g++ $(opt) src/main.cpp -o bin/rshell	        	

rshell:
	mkdir -p bin
	g++ $(opt) src/main.cpp -o bin/rshell
