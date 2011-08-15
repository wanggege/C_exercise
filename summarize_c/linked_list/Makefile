main:main.o linkedlist.o
	gcc main.o linkedlist.o -o main
main.o:main.c linkedlist.h
	gcc -Wall -c main.c -o main.o
linkedlist.o:linkedlist.c linkedlist.h
	gcc -Wall -c linkedlist.c -o linkedlist.o

clean:
	-rm -f main.o linkedlist.o
	-rm -f main
