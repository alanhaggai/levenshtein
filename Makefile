all: liblevenshtein.so
	LD_LIBRARY_PATH=. gcc -Wall -L. -llevenshtein -o levenshtein main.c

liblevenshtein.so:
	gcc -c -Wall -Werror -fpic levenshtein.c
	gcc -shared -o liblevenshtein.so levenshtein.o
	rm -f levenshtein.o

clean:
	rm -f liblevenshtein.so levenshtein.o levenshtein
