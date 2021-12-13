DiceGame: main.c
	gcc main.c -o DiceGame -Wall
	termux-elf-cleaner dg

.PHONY: clean

clean:
	rm dg
