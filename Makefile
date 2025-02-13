CFLAGS = -ggdb -Wall -Wextra -pedantic -std=c11

main: src/main.c registers.o
	gcc src/main.c registers.o -o gbce $(CFLAGS)

registers.o: src/registers.c src/registers.h
	gcc src/registers.c -c -o registers.o $(CFLAGS)

clean:
	rm -rf gbce registers.o
