all: mystring.o main.o
	gcc -o main main.o mystring.o

mystring.o: mystring.c
	gcc -c mystring.c

main.o: main.c mystring.h
	gcc -c main.c

run:
	./main
