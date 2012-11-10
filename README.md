1-D Rubik’s Cube
#############
A one-dimensional variant of the [famous puzzle][wiki-rubik] created by Ernö Rubik. A matrix with 2 rows and 4 columns represents the “cube”. A unique number in the range of 1 to 8 represents an element within the cube. 

Example
-------

	[1 2 3 4 5 6 7 8]    String representation
	1 2 3 4              Matrix representation
	8 7 6 5

The cube can only be distorted by using a combination of transformations. In our version the transformations is:

* A: Switching the two rows with each other.
* B: Shifting the four columns one step to the right.
* C: Rotating the four central elements clockwise.

Given an initial cube and the end result the best sequence of transformations should be produced, which transforms the cube to the wanted configuration. The best sequence is the one with the least amount of transformations.

Given as an assignment in an introductory course of programming in C at [Chalmers University][chalmers] autumn 2012 (LEU480). 

[wiki-rubik]: http://en.wikipedia.org/wiki/Rubik's_Cube "Wikipedia article on the traditional Rubik's Cube"
[chalmers]: http://www.chalmers.se/ "Chalmers University website"