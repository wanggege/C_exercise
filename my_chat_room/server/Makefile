server:server.o msg_link.o wrap.o creat_link.o 
	gcc -o server server.o msg_link.o wrap.o creat_link.o
server.o:server.c msg_link.h wrap.h creat_link.h
	gcc -c server.c
msg_link.o:msg_link.c msg_link.h
	gcc -c msg_link.c
wrap.o:wrap.c wrap.h
	gcc -c wrap.c
creat_link.o:creat_link.c creat_link.h
	gcc -c creat_link.c
clean:
	rm -f *.o
