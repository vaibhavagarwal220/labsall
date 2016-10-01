all:func.o sparse.o
	gcc -o sparse func.o sparse.o
sparse:sparse.c 
		gcc -c sparse.c
func:lib.h func.c
	gcc -c func.c
clean:
	rm -f *.o
