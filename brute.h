#ifndef BRUTE_H
#define BRUTE_H

//! \breif Alias for one of the callback functions used in brute-forceing
typedef int (*brute_callback_fn)(cube_t* cube);

/** \breif Brute-force all solutions to transform a cube to the desired cube

	\param cube the cube to start the search at
	\param wanted the wanted cube in string representation
	\param callback a callback function which will be called on each hit
	\sa brute_one_iteration
**/
void brute_cube(cube_t* cube, const char* wanted, brute_callback_fn callback);

/** \breif Helper function which transforms a cube and checks if its correct

	\param cube the cube to start the search at
	\param wanted the wanted cube in string representation
	\param transform which transformation that should be used
	\param callback a callback function which will be called on each hit
	\sa brute_cube
**/
void brute_one_iteration(const cube_t* cube, const char* wanted, cube_transform_fn transform, brute_callback_fn callback);

/** \breif Callback function which prints all solutions

	\param cube a correct cube which contains the sequence which transformed it
	\sa brute_cube
**/
int brute_all_unsorted_print(cube_t* cube);

#endif