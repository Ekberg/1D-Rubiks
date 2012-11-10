CC = clang
FILES = main.c
OUTPUT = rubiks1d

build: $(FILES)
	$(CC) -o $(OUTPUT) $(FILES)

debug: $(FILES)
	$(CC) -g -o $(OUTPUT) $(FILES)

clean:
	rm -rf *.o *.dSYM $(OUTPUT)