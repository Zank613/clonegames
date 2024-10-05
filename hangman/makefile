CC = gcc
CFLAGS = -Wall -std=c99
OBJ = main.o
TARGET = hangman

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c hangman.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJ) $(TARGET)