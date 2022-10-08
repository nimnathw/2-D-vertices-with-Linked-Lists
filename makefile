CC=gcc
CFLAGS= -g -Wall -lm
OBJECTS= *.o


# Link command
output: main.o modify.o bubble_sort.o
	$(CC) main.o modify.o bubble_sort.o -o output ${CFLAGS}

# Compilation commands
main.o: main.c
	$(CC) -c main.c

modify.o: modify.c modify.h
	${CC} -c modify.c

bubble_sort.o: bubble_sort.c bubble_sort.h modify.h
	${CC} -c bubble_sort.c

# rule to delete object files and executable file
clean:
	rm ${OBJECTS} output