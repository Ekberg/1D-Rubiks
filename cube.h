#ifndef CUBE_H
#define CUBE_H

#ifndef CUBE_SIZE
#define CUBE_SIZE 9
#endif

//! \brief Alias for an struct containing cube data
typedef struct {
	char data[CUBE_SIZE]; //!< Cube data in string representation.
	size_t sequence_size; //!< Size of sequence string, used alot to check
						  //!< overflow in bruteforce. Faster than strlen().
	char* sequence;       //!< Pointer to the sequence of transformations
						  //!< that have been done on this cube.
} cube_t;

/** \brief Creates a new cube with provided initial data

	Allocates new memory for a cube and initializes it with data. The pointer
	that is returned must be deallocated with cube_free since it contains
	another pointer.
	
	\param data initial data to 
	\return Pointer to newly created cube.
	\sa cube_free
**/
cube_t* cube_create(const char data[CUBE_SIZE]);

/** \breif Deallocates memory used by a cube

	\param cube cube to free
	\sa cube_free
**/
void cube_free(cube_t* cube);

/** \breif Switches the rows of the cube
 
	\param cube cube to transform
	\sa cube_transform_B, cube_transform_C
**/
void cube_transform_A(cube_t* cube);

/** \breif Shifting the columns of the cube to the right
 
	\param cube cube to transform
	\sa cube_transform_A, cube_transform_C
**/
void cube_transform_B(cube_t* cube);

/** \breif Rotating the central elements of the cube
 
	\param cube cube to transform
	\sa cube_transform_A, cube_transform_B
**/
void cube_transform_C(cube_t* cube);

/** \breif Transforms a cube with multiple transformations

	\param cube cube to transform
	\param sequence string of all transformations to perform i.e. "ABC"
	\sa cube_transform_A, cube_transform_B, cube_transform_C
**/
void cube_transform(cube_t* cube, const char* sequence);

/** \breif Helper function for cube transformations
	
	\param cube cube to transform
	\param id which transformation that have been used
	\param buffer new data for the cube after transformation
	\sa cube_transform_A, cube_transform_B, cube_transform_C
**/
void __cube_transform_save(cube_t* cube, const char id, const char buffer[CUBE_SIZE]);

//! \breif Alias for one of the transformation functions
typedef void (*cube_transform_fn)(cube_t* cube);

/** \breif Checks if a string is valid as cube data
	
	\param data string to be validated
	\return Non-zero if data is valid, 0 otherwise
	\sa cube_create
**/
int is_vaid_cube_data(char* data);

/** \breif Checks if a string is a valid sequence of transformations

	\param sequence string to be validated
	\return Non-zero if data is valid, 0 otherwise
**/
int is_valid_sequence(char* sequence);

#endif 