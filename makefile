CC = gcc
CFLAGS = -Wall -g -fsanitize=address
OBJECTS = doit.o io.o utils.o gestion_plateau.o pile.o sokoban.o
BIN = main
RM = rm

all: $(OBJECTS)
	@$(CC) -o $(BIN) $(OBJECTS) $(CFLAGS)

doit.o: doit.c io.h gestion_plateau.h utils.h
	@$(CC) -o $@ -c $< $(CFLAGS)

io.o: io.c io.h
	@$(CC) -o $@ -c $< $(CFLAGS)

utils.o: utils.c utils.h sokoban.h
	@$(CC) -o $@ -c $< $(CFLAGS)

gestion_plateau.o: gestion_plateau.c gestion_plateau.h
	@$(CC) -o $@ -c $< $(CFLAGS)

pile.o: pile.c pile.h
	@$(CC) -o $@ -c $< $(CFLAGS)

sokoban.o: sokoban.c sokoban.h gestion_plateau.h
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@$(RM) -f $(OBJECTS) $(BIN)
