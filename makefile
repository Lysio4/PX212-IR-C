main: sokoban.o main.o
	gcc -g -Wall -fsanitize=address -o main lecture.o main.o

sokoban.o: sokoban.c
	gcc -o sokoban.o -c sokoban.c -g -Wall -fsanitize=address

main.o: main.c sokoban.h
	gcc -o main.o -c main.c -g -Wall -fsanitize=address

main: fonctions.o main.o
        gcc -g -o main fonctions.o main.o -lm -fsanitize=address

fonctions.o: fonctions.c
        gcc -o fonctions.o -fcommon -c fonctions.c -g -Wall -fsanitize=address

main.o: main.c fonctions.h
        gcc -o main.o -c main.c -g -Wall -fsanitize=address
