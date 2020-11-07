/*
*	Square State ADT Implementation
*	Author: J.R.Dermoudy
*	Version: 1 October 2019
*
*	This file holds the square_state ADT.  It comprises
*	the coordinate of square (as "row" and "column"),
*	and whether or not the square is occupied.
*
*	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdio.h>
#include <stdlib.h>
#include "square_state.h"
#include "assig_three219.h"


// types
struct square_state_int {
	int row; //the row of a specific square on the board
	int column; //the column of a specific square on the board
	bool visited; //if the specific square has been visited or not
	int move; //number of required move to reach the square
};


/*
*	init_square_state
*	initialiser function.
*	Pre-condition: none
*	Post-condition: a square_state variable is created and pointed
*					to by the first parameter.  Its row field
*					is set to r, its column field is set to c,
*					and it is set to unoccupied.
*	Informally: creates an unoccupied square space
*
*	Param r int intended row number for square
*	Param c int intended column number for square
*/
void init_square_state(square_state *sp, int r, int c)
{
	trace("init_square_state: init_square_state starts");

	*sp = (square_state)malloc(sizeof(struct square_state_int));
	(*sp)->row = r;
	(*sp)->column = c;
	(*sp)->visited = false;
	(*sp)->move = 0;

	trace("init_square_state: init_square_state ends");
}


/*
* 	get_row_num
*	Get function for row field.
*	Pre-condition: none
*	Post-condition: the value of the square_state variable's row
*					field is returned
*	Informally: return the square_state variable's row
*
*	return int the current row number of the square
*/
int get_row_num(square_state s)
{
	trace("get_row_num: get_row_num starts and finishes");

	return (s->row);
}


/*
* 	get_column_num
*	Get function for column field.
*	Pre-condition: none
*	Post-condition: the value of the square_state variable's column
*					field is returned
*	Informally: return the square_state variable's column
*
*	return int the current column number of the square
*/
int get_column_num(square_state s)
{
	trace("get_column_num: get_column_num starts and finishes");

	return (s->column);
}


/*
* 	set_row_num
*	Set function for row field.
*	Pre-condition: the given square_state is defined 
*	Post-condition: the value of the square_state variable's row
*					field is updated to the given int value
*	Informally: update the square_state variable's row
*
* Param r int value to be placed into the square_state's row field
*/
void set_row_num(square_state s, int r)
{
	trace("set_row_num: set_row_num starts");

	s->row = r;

	trace("set_row_num: set_row_num ends");
}


/*
* 	set_column_num
*	Set function for column field.
*	Pre-condition: the given square_state is defined 
*	Post-condition: the value of the square_state variable's column
*					field is updated to the given int value
*	Informally: update the square_state variable's column
*
*	Param c int value to be placed into the square_state's column field
*/
void set_column_num(square_state s, int c)
{
	trace("set_column_num: set_column_num starts");

	s->column = c;

	trace("set_column_num: set_column_num ends");
}


/*
*	get_count
*	Return the move number of the given square_state
*	Pre-condition: the given square_state is defined
*	Post-condition: the value of the square_state's move field is
*					returned
*	Informally: look up the move number of the given square_state
*
*	return int the number of the move of the given square_state
*/
int get_count(square_state s)
{
	trace("get_count: get_count starts and finishes");

	return s->move;
}


/*
* 	occupied
*	Check whether the square_state has already been occupied
*	Pre-condition: the given square_state is defined 
*	Post-condition: true is returned if the square has been visited
*					(i.e. is true, and false is returned otherwise)
*	Informally: Return whether or not a square has been taken
*/
bool occupied(square_state s)
{
	trace("occupied: visit starts and finishes");

	return s->visited;
}


/*
* 	occupy
*	Set function for visited field.
*	Pre-condition: the given square_state is defined
*	Post-condition: the value of the square_state variable's visited
*					field is updated to true and move is updated to
*					the given value
*	Informally: visit this square_state variable
*
*	Param c int the number of this move
*/
void occupy(square_state s, int c)
{
	trace("occupy: occupy starts");

	s->visited = true;
	s->move = c;

	trace("occupy: occupy ends");
}


/*
*	clone_square_state
*	Clone a square state
*	Pre-condition: the given square_state is defined
*	Post-condition: a deep clone of the given square_state
*	variable is returned
*	Informally: Copy a square state
*
*	return square_state the copy
*/
square_state clone_square_state(square_state s)
{
	square_state n; //variable to store the clone of given square state

	trace("clone_square_state: clone_square_state starts");

	init_square_state(&n, get_row_num(s), get_column_num(s));
	if (occupied(s))
	{
		trace("clone_square_state: occupying square on copy");
		occupy(n, get_count(s));
	}

	trace("clone_square_state: clone_square_state finishes");

	return n;
}


/*
* 	show_square_state
*	Display a game state
*	Pre-condition: the given square_state is defined
*	Post-condition: the given square_state has been displayed on
*					the standard output stream
*	Informally: Print the square
*/
void show_square_state(square_state s)
{
	trace("show_square_state: show_square_state starts");

	if (occupied(s))	// knight is there
	{
		printf("%3d",s->move);
	}
	else				// empty
	{
		printf("   ");
	}

	trace("show_square_state: show_square_state ends");
}
