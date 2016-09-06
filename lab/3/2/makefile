all:my_fun.o my_assign.o
	gcc -o my_out my_fun.o my_assign.o
assign:my_assign.c 
		gcc -c my_assign.c
fun:my_lib.h my_fun.c
	gcc -c my_fun.c
clean:
	rm -f *.o
