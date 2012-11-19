CC = clang
FILES = cube.c brute.c main.c
OUTPUT = rubiks1d

build: $(FILES)
	$(CC) -lm -o $(OUTPUT) $(FILES)

debug: $(FILES)
	$(CC) -g -lm -o $(OUTPUT) $(FILES)

clean:
	rm -rf *.o *.dSYM $(OUTPUT)