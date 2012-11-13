#include <stdio.h>
#include <string.h>
#include "cube.h"
#include "brute.h"

#define DEFAULT_CUBE "12345678"

const char* PROGRAM_NAME;

int main(int argc, char **argv) {
	char* initial_cube;
	char* target_cube;
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
			if (!initial_cube) {
				initial_cube = *argv;
			} else if (!target_cube) {	
				target_cube = *argv;
			} else {
				printf("Invalid argument, too many cube arguments.\n");
				return -1;
			}
		} else {
			printf("Invalid argument.\n");
			return -1;
		}
	}
	
	if (!sequence && initial_cube && !target_cube) {
		target_cube = initial_cube;
		initial_cube = DEFAULT_CUBE;
	} else if (sequence && !initial_cube) {
		initial_cube = DEFAULT_CUBE;
	}
	
	if (!sequence && !initial_cube && !target_cube) {
		printf("No arguments given.\n");
		return -1;
	}
	
	cube_t* cube = cube_create(initial_cube);
	
	if (sequence) {
		cube_transform(cube, sequence);
		printf("%s\n", cube->data);
	} else {
		
		brute_cube(cube, target_cube, &brute_all_unsorted_print);
	
	}
	cube_free(cube);
	
	return 0;
}