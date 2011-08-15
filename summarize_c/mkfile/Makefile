main:main.o add.o sub.o mul.o
	gcc add.o sub.o mul.o main.o -o main

add.o:add.c add.h
	gcc -c add.c -o add.o

sub.o:sub.c add.h
	gcc -c sub.c -o sub.o

mul.o:mul.c add.h
	gcc -c mul.c -o mul.o

main.o:main.c add.h
	gcc -c main.c -o main.o

clean:
	-rm -f add.o main.o sub.o mul.o
	-rm -f main
