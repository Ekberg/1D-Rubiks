#include <stdio.h>
#include <string.h>
#include "cube.h"
#include "brute.h"

void brute_cube(cube_t* cube, const char* wanted, brute_callback_fn callback) {
	if (cube->sequence_size < 4) {
		brute_one_iteration(cube, wanted, &cube_transform_A, callback);
		brute_one_iteration(cube, wanted, &cube_transform_B, callback);
		brute_one_iteration(cube, wanted, &cube_transform_C, callback);
	}
}

void brute_one_iteration(const cube_t* cube, const char* wanted, cube_transform_fn transform, brute_callback_fn callback) {
	cube_t* new_cube = cube_copy(cube);
	
	transform(new_cube);
	
	if (strcmp(wanted, new_cube->data) == 0) { 
		if (callback(new_cube) != 0) {
			cube_free(new_cube);
			return;
		}
	}
	brute_cube(new_cube, wanted, callback);
	cube_free(new_cube);
}

int brute_all_unsorted_print(cube_t* cube) {
	printf("%s\n", cube->sequence);
	return 0;
}