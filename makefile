CC=gcc
CFLAGS= *.o

# rule to build ouput executable
output: main.o modify.o
	$(CC) main.o modify.o -o output

main.o: main.c
	$(CC) -c main.c

modify.o: modify.c modify.h
	${CC} -c modify.c

# rule to delete object files and executable file
clean:
	rm ${CFLAGS} output