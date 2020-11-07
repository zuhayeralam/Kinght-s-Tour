/*
	*	Harness File
	*	Author: J.R.Dermoudy
	*	Version: September 2019
	*	
	*	This file drives the solution.  
	*
	*	The file is complete.
*/


#include <stdio.h>
#include <stdbool.h>
#include "assig_three219.h"
#include "game_tree.h"
#include "game_state.h"
#include "queue.h"
#include "stack.h"


/*
	*	trace
	*	Provide trace output.
	*	Pre-condition: none
	*	Post-condition: if trace output is desired then the given String
	*					parameter is shown on the console
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
	printf("Knight's Tour\n");
	printf("=============\n");
	printf("Welcome to the Knight's Tour.  This is played on a(n) %d x %d board.  The\n",DIMENSION,DIMENSION);
	printf("knight must move %d times without landing on the same square twice.\n",TOUR_LENGTH);
	printf("\n");
}


/*
*	main
*	Program entry point.
*	Pre-condition: none
*	Post-condition: the solution to the Knight's Tour will be found
*					and displayed
*	Informally: solve the Knight's Tour
*/
int main(int argc, char *argv[])
{
	game_tree g,a;	// whole game tree and solution game tree
	game_state s;	// initial game state
	queue q;		// intermediate traversal use
	stack k;		// intermediate traversal use
	stack r;		// re-tracing solution path

	// give introduction
	intro();

	// initialise data structures
	init_stack(&r);
	init_queue(&q);
	init_stack(&k);
	init_game_state(&s);
	land(s, 1, 1);	// start at top left-hand corner: (1,1)

	// show initial board
	printf("\nStarting board:\n");
	show_game_state(s);
	printf("\n");
	
	// solve
	init_game_tree(&g, false, s, 1);
	if (BREADTH_FIRST)
	{
		a = build_gameBF(g, q, TOUR_LENGTH);
	}
	else
	{
		a = build_gameDF(g, k, TOUR_LENGTH);
	}
	// show results
	if (is_empty_game_tree(a))
	{
		printf("No solution!\n");
	}
	else
	{
		// re-trace solution from leaf to root
		do
		{
			push(r, a);
			a = get_parent(a);
		} while (!is_empty_game_tree(a));

		// display move list
		while (!is_empty_stack(r))
		{
			a = (game_tree)top(r);
			s = (game_state)get_data(a);
			printf("Move %d: (%d,%d)\n", get_level(a), get_row(s), get_column(s));
			pop(r);
		}

		// display final path
		printf("\nFinal board:\n");
		show_game_state(s);
	}
}
