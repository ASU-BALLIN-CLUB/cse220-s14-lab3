scanner: main.o scanner.o print.o
	gcc -o scanner main.o scanner.o print.o
scanner.o: scanner.c scanner.h
	gcc -c scanner.c
print.o: print.c print.h
	gcc -c print.c
main.o: main.c common.h 
	gcc -c main.c
clean:
	rm scanner main.o scanner.o print.o
