#include <stdio.h>
#include <string.h>
#include "cube.h"

const char* PROGRAM_NAME;

int main(int argc, char **argv) {
	char* sequence;

	if (argc) {
		if (argv[0][0] == '.' && argv[0][1] == '/') {
			PROGRAM_NAME = &argv[0][2];
		} else {
			PROGRAM_NAME = argv[0];
		}
	}
	
	while (argc-- > 1) {
		argv++;
		
		if (is_valid_sequence(*argv)) {
			sequence = *argv;
		} else {
			printf("Invalid argument.\n");
			return -1;
		}
	}

	cube_t* cube = cube_create("12345678");
	
	cube_transform(cube, sequence);
	
	printf("%s\n", cube->data);
	return 0;
}