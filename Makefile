CC=gcc
CFLAGS=

all: clean ResistanceCalculator.c
	$(CC) -o rc ResistanceCalculator.c $(CFLAGS)

clean:
	rm -f rc
