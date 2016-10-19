#Assignment2 makefile
CC = g++
#	-g adds debugging information to executable
#	-Wall shows most warnings
CFLAGS = -g -Wall
TARGET = assignment2

default: $(TARGET)

$(TARGET): $(TARGET).cpp linkedlist.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp linkedlist.o

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -o linkedlist.o linkedlist.cpp

clean:
	$(RM) $(TARGET) *.o

