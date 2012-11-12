#include <stdio.h>
#include <string.h>
#include "cube.h"

#define DEFAULT_CUBE "12345678"

const char* PROGRAM_NAME;

int main(int argc, char **argv) {
	char* initial_cube;
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
			if (sequence) {
				printf("Invalid argument, already got a sequence.\n");
				return -1;
			}
			sequence = *argv;
		} else if (is_valid_cube_data(*argv)) {
			if (initial_cube) {
				printf("Invalid argument, already got a initial cube.\n");
				return -1;
			}
			initial_cube = *argv;
			
		} else {
			printf("Invalid argument.\n");
			return -1;
		}
	}
	
	if (!sequence) {
		printf("Not enough arguments.\n");
		return -1;
	}
	
	if (!initial_cube) {
		initial_cube = DEFAULT_CUBE;
	}
	
	

	cube_t* cube = cube_create(initial_cube);
	
	cube_transform(cube, sequence);
	
	printf("%s\n", cube->data);
	
	cube_free(cube);
	
	return 0;
}