CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

EXEC = ws

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $<

clean:
	rm -f $(EXEC) $(OBJECTS)
