all:func.o pal_stack.o
	gcc -o pal_stack func.o pal_stack.o
pal_stack:pal_stack.c 
		gcc -c pal_stack.c
func:lib.h func.c
	gcc -c func.c
clean:
	rm -f *.o
