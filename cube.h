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

#endif 