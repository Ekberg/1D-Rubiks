#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cube.h"
#include "brute.h"

extern int MAX_SEQUENCE_SIZE;

void brute_cube(solutions_t* solutions, cube_t* cube, const char* wanted) {
	if (cube->sequence_size < MAX_SEQUENCE_SIZE) {
		brute_one_iteration(solutions, cube, wanted, &cube_transform_A);
		brute_one_iteration(solutions, cube, wanted, &cube_transform_B);
		brute_one_iteration(solutions, cube, wanted, &cube_transform_C);
	}
}

void brute_one_iteration(solutions_t* solutions, cube_t* cube, const char* wanted, cube_transform_fn transform) {
	brute_progress(solutions);
	
	cube_t* new_cube = cube_copy(cube);
	
	transform(new_cube);
	
	solutions->done++;
	if (strcmp(wanted, new_cube->data) == 0) { 
		brute_solution_insert(solutions, new_cube);
		brute_cube(solutions, new_cube, wanted);
	} else {
		brute_cube(solutions, new_cube, wanted);
		cube_free(new_cube);	
	}
}

solutions_t* brute_solutions_create(const size_t limit) {
	int i;
	solutions_t* solutions = malloc(sizeof(solutions_t));
	
	solutions->array = calloc(limit, sizeof(cube_t*));
	solutions->limit = limit;
	solutions->size  = 0;
	solutions->done  = 0;
	solutions->max   = 0;
	for (i = 0; i <= MAX_SEQUENCE_SIZE; i++) {
		solutions->max += pow(3, i);
	}
	
	return solutions;
}

void brute_solutions_free(solutions_t* solutions) {
	int i;
	for (i = 0; i < solutions->size; i++) {
		cube_free(solutions->array[i]);
	}
	free(solutions->array);
	free(solutions);
}

void brute_solution_insert(solutions_t* solutions, cube_t* cube) {
	if (solutions->size + 1 >= solutions->limit) {
		solutions->limit += 100; 
		solutions->array = realloc(solutions->array, solutions->limit * sizeof(cube_t*));
		brute_solution_insert(solutions, cube);
	} else {
		solutions->array[solutions->size++] = cube;
	}
}

void brute_solutions_sort(solutions_t* solutions) {
	qsort(solutions->array, solutions->size, sizeof(cube_t*), cube_compare_sequence_size);
}

void brute_progress(solutions_t* solutions) {
	float ratio;
	int i;
	
	if (solutions->max >= 100 && (solutions->done % (solutions->max / 100)) != 0) {
		return;
	}
	
	ratio = solutions->done / (float) solutions->max;
	
	printf("%3d%% [", (int) (ratio * 100));
	
	for (i = 0; i < 100; i++) {
		if (i < ratio * 100) {
			printf("=");
		} else {
			printf(" ");	
		}
	}
	printf("]\n\033[F\033[J");
}