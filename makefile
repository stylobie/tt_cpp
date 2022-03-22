CC = g++
CFLAGS = -Wall -g -std=c++17
TARGET = myprogram
RM = rm

$(TARGET): main.o helloworld.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o helloworld.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

helloworld.o: helloworld.cpp helloworld.h
	$(CC) $(CFLAGS) -c helloworld.cpp


test: test.o
	$(CC) $(CFLAGS) -o test test.o helloworld.o
	./test

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp




clean:
	$(RM) $(TARGET)
	$(RM) *.o

