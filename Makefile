# Variables
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

# Cibles
all: Cy_crush

Cy_crush: save.o game.o menu.o main.o
	$(CC) $(LDFLAGS) $^ -o $@

save.o: save.c
	$(CC) $(CFLAGS) -c $< -o $@

game.o: game.c
	$(CC) $(CFLAGS) -c $< -o $@

menu.o: menu.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o Cy_crush
