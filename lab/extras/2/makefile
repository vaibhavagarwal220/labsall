all:func.o rev_stack.o
	gcc -o rev_stack func.o rev_stack.o
rev_stack:rev_stack.c 
		gcc -c rev_stack.c
func:lib.h func.c
	gcc -c func.c
clean:
	rm -f *.o
