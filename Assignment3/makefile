#Assignment2 makefile
CC = g++
#	-g adds debugging information to executable
#	-Wall shows most warnings
CFLAGS = -g -Wall
TARGET = assignment3.out
SOURCES = $(wildcard *.cpp)
#Objects will just be all the sources files
OBJECTS = $(patsubtr %.cpp,%.o,$(SOURCES))

default: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(TARGET) *.o

