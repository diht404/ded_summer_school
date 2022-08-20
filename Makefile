CC = g++

CFLAGS = -c

quadratic: quadratic.o solve.o
	$(CC) quadratic.o solve.o -o quadratic

debug: tests.o solve.o
	$(CC) tests.o solve.o -o debug

quadratic.o: quadratic.cpp
	$(CC) $(CFLAGS) quadratic.cpp

solve.o: solve.cpp
	$(CC) $(CFLAGS) solve.cpp

tests.o: tests.cpp
	$(CC) $(CFLAGS) tests.cpp

clean:
	rm -rf *.o quadratic debug