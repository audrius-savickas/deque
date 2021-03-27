CC = gcc
CFLAGS= -g

all: mainapp

mainapp: main.o deque.o
	$(CC) $(CFLAGS) main.o deque.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

deque.o: deque.c
	$(CC) $(CFLAGS) -c deque.c

clean:
	rm main *.o mainapp
