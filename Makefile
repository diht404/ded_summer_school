CC = g++

CFLAGS = -c

main: main.o utils.o
	$(CC) main.o utils.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp

clean:
	rm -rf *.o main debug