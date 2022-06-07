main: sokoban.o main.o
	gcc -g -Wall -fsanitize=address -o main lecture.o main.o

sokoban.o: sokoban.c
	gcc -o sokoban.o -c sokoban.c -g -Wall -fsanitize=address

main.o: main.c header.h
	gcc -o main.o -c main.c -g -Wall -fsanitize=address

main: Fonctions.o main.o
  gcc -g -o main Fonctions.o main.o -lm -Wall -fsanitize=address

Fonctions.o: Fonctions.c
	gcc -o Fonctions.o -fcommon -c Fonctions.c -g -Wall -fsanitize=address

main.o: main.c header.h
  gcc -o main.o -c main.c -g -Wall -fsanitize=address

touches.o: touches.c io.c header.h
	gcc -o main.o -c main.c -g -Wall -fsanitize=address
