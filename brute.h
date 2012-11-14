#ifndef BRUTE_H
#define BRUTE_H
 
//! \breif Alias for a struct containing all solutions found in the brute-force
typedef struct {
	cube_t** array;
	size_t size;
	size_t limit;
} solutions_t;

/** \breif Brute-force all solutions to transform a cube to the desired cube

	\param solutions output for all correct transformations
	\param cube the cube to start the search at
	\param wanted the wanted cube in string representation
	\sa brute_one_iteration
**/
void brute_cube(solutions_t* solutions, cube_t* cube, const char* wanted);

/** \breif Helper function which transforms a cube and checks if its correct

	\param solutions output for all correct transformations
	\param cube the cube to start the search at
	\param wanted the wanted cube in string representation
	\param transform which transformation that should be used
	\sa brute_cube
**/
void brute_one_iteration(solutions_t* solutions, cube_t* cube, const char* wanted, cube_transform_fn transform);

/** \breif Creates a new placeholder for solutions produced by the brute-force
	
	\param limit initial size of array, not fixed but will be resized on demand.
	\return pointer to the solutions
	\sa brute_solutions_free, brute_solution_insert
**/
solutions_t* brute_solutions_create(const size_t limit);

/** \breif Deallocates memory used by a solution

	\param solutions the solutions to free
	\sa brute_solutions_create, brute_solution_insert
**/
void brute_solutions_free(solutions_t* solutions);

/** \breif Inserts a cube to a solutions array

	\param solutions array to insert into 
	\param cube pointer to a cube
	\sa brute_solutions_create, brute_solution_insert
**/
void brute_solution_insert(solutions_t* solutions, cube_t* cube);

#endif