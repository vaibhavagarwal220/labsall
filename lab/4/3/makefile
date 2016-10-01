all:queue.o stackq.o
	gcc -o stackq queue.o stackq.o
stackq:stackq.c 
		gcc -c stackq.c
queue:lib.h queue.c
	gcc -c queue.c
clean:
	rm -f *.o
