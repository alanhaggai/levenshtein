all: liblevenshtein.so
	gcc -Wall main.c -L. -llevenshtein -Wl,-rpath=. -o levenshtein

liblevenshtein.so:
	gcc -c -Wall -Werror -fpic levenshtein.c
	gcc -shared -o liblevenshtein.so levenshtein.o
	rm -f levenshtein.o

clean:
	rm -f liblevenshtein.so levenshtein.o levenshtein
