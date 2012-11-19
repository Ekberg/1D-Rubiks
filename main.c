#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cube.h"
#include "brute.h"

#define DEFAULT_CUBE "12345678"
#define SOLUTION_LIMIT 100

const char* PROGRAM_NAME;
const int MAX_SEQUENCE_SIZE = 15;

static void usage() {
	printf("usage: %s [options] [-l <limit>] [initial cube] sequence|wanted cube\n", PROGRAM_NAME);
	printf("Options:\n");
	printf("  -h, --help\t\tPrint this message and quits.\n");
	
	printf("  -b, --best\t\tOnly output the best solution.\n");
	printf("  -a, --all\t\tOutput all correct solutions.\n");
	printf("  -l, --limit\t\tLimit the output.\n");
	
	exit(1);
}

static void error(const char* message) {
	fprintf(stderr, "%s: %s. See --help for usage.\n", PROGRAM_NAME, message);
	exit(-1);
}

int is_option(const char* arg, const char short_option, const char* long_option) {
	if (arg[0] == '-') {
		if (arg[1] == short_option) {
			return 1;
		}
		if (arg[1] == '-' && strcmp(arg + 2, long_option) == 0) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv) {
	char* initial_cube = NULL;
	char* target_cube = NULL;
	char* sequence = NULL;
	
	int i;
	int output_limit = -1;
	
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
				error("Invalid argument, already got a sequence");
			}
			sequence = *argv;
		} else if (is_valid_cube_data(*argv)) {
			if (!initial_cube) {
				initial_cube = *argv;
			} else if (!target_cube) {	
				target_cube = *argv;
			} else {
				error("Invalid argument, too many cube arguments");
			}
		} else if (is_option(*argv, 'h', "help")) {
			usage();
		} else if (is_option(*argv, 'l', "limit")) {
			if ((output_limit = atoi(*++argv)) <= 0) {
				output_limit = -1;
			}
			argc--;
		} else if (is_option(*argv, 'b', "best")) {
			output_limit = 1;
		} else if (is_option(*argv, 'a', "all")) {
			output_limit = -1;
		} else {
			error("Invalid argument");
		}
	}
	
	if (!sequence && initial_cube && !target_cube) {
		target_cube = initial_cube;
		initial_cube = DEFAULT_CUBE;
	} else if (sequence && !initial_cube) {
		initial_cube = DEFAULT_CUBE;
	}
	
	if (!sequence && !initial_cube && !target_cube) {
		error("No arguments given");
	}
	
	cube_t* cube = cube_create(initial_cube);
	
	if (sequence) {
		cube_transform(cube, sequence);
		printf("%s\n", cube->data);
	} else {
		
		solutions_t* solutions = brute_solutions_create(SOLUTION_LIMIT);
		
		brute_cube(solutions, cube, target_cube);
		
		brute_solutions_sort(solutions);
		
		if (output_limit < 0 || output_limit > solutions->size) {
			output_limit = solutions->size;
		}
		
		for(i = 0; i < output_limit; i++) {
			printf("%s\n", solutions->array[i]->sequence);
		}
		
		brute_solutions_free(solutions);
	}
	cube_free(cube);
	
	return 0;
}