all: main clean

main: Input.o main.o Output.o StringsSort.o StringFunctions.o
	gcc Input.o main.o Output.o StringsSort.o StringFunctions.o -fsanitize=address

Input.o: Input.c
	gcc -c Input.c

main.o: main.c
	gcc -c main.c

Output.o: Output.c
	gcc -c Output.c

StringsSort.o: StringsSort.c
	gcc -c StringsSort.c

StringFunctions.o: ../MyStringLib/StringFunctions.c
	gcc -c ../MyStringLib/StringFunctions.c

clean:
	rm *.o