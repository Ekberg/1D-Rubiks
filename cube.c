#include <stdlib.h>
#include <string.h>
#include "cube.h"

cube_t* cube_create(const char data[CUBE_SIZE]) {
	cube_t* cube = malloc(sizeof(cube_t));
	cube->sequence = calloc(10, sizeof(char));
	cube->sequence_size = 0;
	strcpy(cube->data, data);
	return cube;
}

void cube_free(cube_t* cube) {
	free(cube->sequence);
	free(cube);
}