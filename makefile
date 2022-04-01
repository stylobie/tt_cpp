CC = g++
CFLAGS = -Wall -g -std=c++17
TARGET = myprogram
RM = rm -f

$(TARGET): main.o nports.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o nports.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

nports.o: nports.cpp nports.h
	$(CC) $(CFLAGS) -c nports.cpp

resistance.o: nports.o resistance.cpp resistance.h
	$(CC) $(CFLAGS) -c resistance.cpp

circuitreader.o: circuitreader.h circuitreader.cpp
	$(CC) $(CFLAGS) -c circuitreader.cpp


test: test.o nports.o resistance.o circuitreader.o
	$(CC) $(CFLAGS) -o test test.o nports.o resistance.o circuitreader.o
	./test

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp



clean:
	$(RM) *.o
	$(RM) $(TARGET)
	$(RM) main
	$(RM) test
