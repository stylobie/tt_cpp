CC = g++
CFLAGS = -Wall -g -std=c++17
TARGET = myprogram
RM = rm -f

$(TARGET): main.o nports.o resistance.o capacitor.o coil.o ground.o tensionsource.o circuitreader.o circuit.o mat.o ij.o mataij.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o nports.o resistance.o capacitor.o coil.o ground.o tensionsource.o circuitreader.o circuit.o mat.o ij.o mataij.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

nports.o: nports.cpp nports.h
	$(CC) $(CFLAGS) -c nports.cpp

resistance.o: nports.o resistance.cpp resistance.h
	$(CC) $(CFLAGS) -c resistance.cpp

capacitor.o: nports.o capacitor.cpp capacitor.h
	$(CC) $(CFLAGS) -c capacitor.cpp

coil.o: nports.o coil.cpp coil.h
	$(CC) $(CFLAGS) -c coil.cpp

ground.o: nports.o ground.cpp ground.h
	$(CC) $(CFLAGS) -c ground.cpp

tensionsource.o: nports.o tensionsource.cpp tensionsource.h
	$(CC) $(CFLAGS) -c tensionsource.cpp


circuitreader.o: circuitreader.h circuitreader.cpp
	$(CC) $(CFLAGS) -c circuitreader.cpp

circuit.o: circuit.h circuit.cpp
	$(CC) $(CFLAGS) -c circuit.cpp

mat.o: mat.h mat.cpp
	$(CC) $(CFLAGS) -c mat.cpp

ij.o: ij.h ij.cpp
	$(CC) $(CFLAGS) -c ij.cpp

mataij.o: ij.h mat.h mataij.h mataij.cpp
	$(CC) $(CFLAGS) -c mataij.cpp

test: test.o nports.o resistance.o capacitor.o coil.o ground.o tensionsource.o circuitreader.o circuit.o mat.o ij.o mataij.o
	$(CC) $(CFLAGS) -v -o test nports.o resistance.o capacitor.o coil.o ground.o tensionsource.o circuitreader.o circuit.o mat.o ij.o mataij.o test.o
	./test

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp



clean:
	$(RM) *.o
	$(RM) $(TARGET)
	$(RM) main
	$(RM) test
