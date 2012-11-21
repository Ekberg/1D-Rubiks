CC = clang
FILES = cube.c brute.c main.c
OUTPUT = rubiks1d

build: $(FILES)
	$(CC) -o $(OUTPUT) $(FILES) -lm

debug: $(FILES)
	$(CC) -g -o $(OUTPUT) $(FILES) -lm

clean:
	rm -rf *.o *.dSYM $(OUTPUT)