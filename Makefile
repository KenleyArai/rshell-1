opt= -Wall -Werror -ansi -pedantic
compiler= "g++"

all:
	mkdir -p bin
	g++ $(opt) src/main.cpp -o bin/rshell
	ls
	ls -l
	ls -a
        	

rshell:
	mkdir -p bin
	g++ $(opt) src/main.cpp -o bin/rshell
	ls 
	ls -l
	ls -a
