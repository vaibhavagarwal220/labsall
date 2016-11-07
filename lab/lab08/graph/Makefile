######################################################
#This Makefile is created to help IC250 students
#Created By:
#Aditya Nigam
#SCEE
#IIT Mandi
#Please modify according to your need 
######################################################



all: my_fun.o main.o
	gcc -o my_exe my_fun.o main.o -lm

main.o: main.c
	gcc -c main.c -lm

my_fun.o: my_lib.h my_fun.c
	gcc -c my_fun.c -lm
clean:
	rm -f *.o
