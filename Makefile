CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -fsanitize=address -O0
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lm -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
