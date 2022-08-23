CC = g++

CFLAGS = -c

main: main.o quadraticUtils.o quadraticSolve.o utils.o
	$(CC) main.o quadraticUtils.o quadraticSolve.o utils.o -o main

debug: tests.o quadraticSolve.o testUtils.o utils.o
	$(CC) tests.o quadraticSolve.o testUtils.o utils.o -o debug

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

quadraticUtils.o: quadraticUtils.cpp
	$(CC) $(CFLAGS) quadraticUtils.cpp

quadraticSolve.o: quadraticSolve.cpp
	$(CC) $(CFLAGS) quadraticSolve.cpp

tests.o: tests.cpp
	$(CC) $(CFLAGS) tests.cpp

testUtils.o: testUtils.cpp
	$(CC) $(CFLAGS) testUtils.cpp

utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp

clean:
	rm -rf *.o main debug