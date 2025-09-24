all: main clean

main: Input.o main.o Output.o SortLib.o Comparators.o
	gcc Input.o main.o Output.o SortLib.o Comparators.o -fsanitize=address

Input.o: Input.c
	gcc -c Input.c

main.o: main.c
	gcc -c main.c

Output.o: Output.c
	gcc -c Output.c

SortLib.o: SortLib.c
	gcc -c SortLib.c

Comparators.o: Comparators.c
	gcc -c Comparators.c

clean:
	rm *.o