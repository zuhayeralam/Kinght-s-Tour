/*
	*	Harness File
	*	Author: J.R.Dermoudy
	*	Version: May 2019
	*	
	*	This file drives the solution.  
	*
	*	The file is complete.
*/


#include <stdio.h>
#include <string.h>
#include "assig_three119.h"
#include "game_tree.h"
#include "game_state.h"
#include "queue.h"
#include "stack.h"


/*
	*	trace
	*	Provide trace output.
	*	Pre-condition: none
	*	Post-condition: if trace output is desired (based on TRACING symbol)
	*					then the given String parameter is shown on the console
	*	Informally: show the given message for tracing purposes
	*
	*	param s the String to be displayed as the trace message
*/
void trace(char *s)
{
	if (TRACING)
	{
		printf("%s\n",s);
	}
}


/*
*	intro
*	Provide introductory output.
*	Pre-condition: none
*	Post-condition: an introduction to the progrm has been displayed
*	Informally: give the user some information about the program
*/
void intro()
{
	char title[20];	// string to build the title within

	// build and print title
	sprintf(title, "%d-Queens", DIMENSION);
	printf("%s\n",title);
	for (int i = 1; i <= (int)(strlen(title)); i++)
	{
		printf("=");
	}
	printf("\n");

	// print introductory information
	printf("Welcome to N-Queens.  This is played on a(n) %d x %d board.  The\n",DIMENSION,DIMENSION);
	printf("board must contain %d Queens which are on different rows, columns\n",DIMENSION);
	printf("and diagonals.  The game tree will be generated %s first.\n",(BREADTH_FIRST?"breadth":"depth"));
	printf("\n");
}


/*
*	main
*	Program entry point.
*	Pre-condition: none
*	Post-condition: the solution to N-Queens will be found
*					and displayed
*	Informally: solve the N-Queens problem
*/
int main(int argc, char *argv[])
{
	game_tree t,a;	// whole game tree and solution game tree
	game_state g;	// the initial game
	queue q;		// intermediate traversal used in Breadth First
	stack s;		// intermediate traversal used in Depth First

	// give introduction
	intro();

	// initialise data structures
	init_stack(&s);
	init_queue(&q);
	init_game_state(&g);

	// solve
	init_game_tree(&t, false, g, 0);
	if (BREADTH_FIRST)
	{
		a = build_gameBF(t, q, DIMENSION);
	}
	else
	{
		a = build_gameDF(t, s, DIMENSION);
	}

	// show results
	if (is_empty_game_tree(a))
	{
		printf("\bNo solution!\n");
	}
	else
	{
		printf("\bSolution:\n");
		show_game_state((game_state)get_data(a));
	}
}
