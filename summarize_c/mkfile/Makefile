src = $(wildcard *.c)
obj = $(patsubst %.c,%.o,$(src))
CC = gcc
CFLAGS = -Wall -g
#LDFLAGS	

main:$(obj)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) $< -c

.PHONY:clean

clean:
	rm -rf *.o
	rm -rf main
