CC = g++

CFLAGS = -c

main: main.o quadraticUtils.o quadraticSolve.o
	$(CC) main.o quadraticUtils.o quadraticSolve.o -o main

debug: tests.o quadraticSolve.o
	$(CC) tests.o quadraticSolve.o -o debug

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

quadraticUtils.o: quadraticUtils.cpp
	$(CC) $(CFLAGS) quadraticUtils.cpp

quadraticSolve.o: quadraticSolve.cpp
	$(CC) $(CFLAGS) quadraticSolve.cpp

tests.o: tests.cpp
	$(CC) $(CFLAGS) tests.cpp

clean:
	rm -rf *.o main debug