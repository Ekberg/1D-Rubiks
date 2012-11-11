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

void cube_transform_A(cube_t* cube) {
	char buffer[CUBE_SIZE];
	int i;
	for (i = 0; i < 8; i++) {
		buffer[i] = cube->data[7 - i];
	}
	__cube_transform_save(cube, 'A', buffer);
}

void cube_transform_B(cube_t* cube) {
	char buffer[CUBE_SIZE];
	int i;
	for (i = 0; i < 3; i++) {
		buffer[i + 1] = cube->data[i];
		buffer[i + 4] = cube->data[i + 5];	
	}
	buffer[0] = cube->data[3];
	buffer[7] = cube->data[4];
	__cube_transform_save(cube, 'B', buffer);
}

void cube_transform_C(cube_t* cube) {
	char buffer[CUBE_SIZE];
	buffer[0] = cube->data[0];
	buffer[7] = cube->data[7];
	buffer[3] = cube->data[3];
	buffer[4] = cube->data[4];
	buffer[1] = cube->data[6];
	buffer[2] = cube->data[1];
	buffer[5] = cube->data[2];
	buffer[6] = cube->data[5];
	__cube_transform_save(cube, 'C', buffer);
}

void __cube_transform_save(cube_t* cube, const char id, const char buffer[CUBE_SIZE]) {
	strcpy(cube->data, buffer);
	cube->sequence[cube->sequence_size++] = id;
}