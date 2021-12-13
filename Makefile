DiceGame: main.c
	gcc main.c -o DiceGame -Wall
	termux-elf-cleaner DiceGame

.PHONY: clean

clean:
	rm DiceGame
