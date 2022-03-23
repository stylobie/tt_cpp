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


test: test.o nports.o
	$(CC) $(CFLAGS) -o test test.o nports.o
	./test

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp




clean:
	$(RM) *.o
	$(RM) $(TARGET)
	$(RM) test

