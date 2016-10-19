#Assignment2 makefile
CC = g++
#	-g adds debugging information to executable
#	-Wall shows most warnings
CFLAGS = -g -Wall
TARGET = assignment2.out

default: $(TARGET)

$(TARGET): pa2.o linkedlist.o
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(TARGET) *.o

