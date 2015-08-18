CC=gcc
CFLAGS=-Wall -ggdb -g3
OBJECTS=con4.o board.o game.o helpers.o player.o scoreboard.o

con4: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o con4

clean:
	rm $(OBJECTS) con4
