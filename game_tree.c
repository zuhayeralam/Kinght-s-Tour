/*
 *	Game Tree ADT Implementation
 *	Author: Zuhayer Alam
 *	Version: 1 October 2019
 *	
 *	This file holds the game_tree ADT which is a
 *	general game tree.  The game_tree is built using
 *	t_node ADTs.  A game_tree variable consists of a
 *	"root" field which refers to a t_node variable
 *	which has a "data" field, "parent" and "child" and
 *	"sibling" references, and a "level" value.
 *	
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
*/


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "t_node.h"
#include "game_state.h"
#include "game_tree.h"
#include "assig_three219.h"


struct game_tree_int
{
	t_node root;			// the node at the top of the tree
};


/*
	*	init_game_tree
	*	initialiser function.
	*	Pre-condition: none
	*	Post-condition: if the parameter value (e) is true then the 
	*					game_tree variable's "root" field is set to NULL
	*					otherwise the game_tree variable's "root" field
	*					refers to a new t_node variable containing the
	*					parameter value (o) of level with parameter 
	*					value (l) with a NULL parent and child, and a 
	*					NULL sibling
	*	Informally: creates either an empty tree or a leaf node as
	*				required
*/
void init_game_tree(game_tree *tp,bool e,void *o,int l)
{
	trace("game_tree: initialiser starts");
	
	t_node n; //new node of the tree where data will be stored and the root will point to where this points at

	*tp = (game_tree)malloc(sizeof(struct game_tree_int));
	if (e)
	{
		(*tp)->root = NULL;
	}
	else
	{
		init_t_node(&n, o, l);
		(*tp)->root = n;
	}
		
	trace("game_tree: initialiser ends");
}
	
	
/*
	*	is_empty_game_tree
	*	Emptiness test.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: true is returned if the game_tree variable is
	*					empty, false is returned otherwise
	*	Informally: indicate if the game_tree contains no nodes
	*
	*	return boolean whether or not the game tree is empty
*/
bool is_empty_game_tree(game_tree t)
{
	trace("is_empty_game_tree: is_empty_game_tree starts and ends");
		
	return (t->root == NULL);
}


/**
	*	get_data
	*	Get function for "root" instance variable's data value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field is returned
	*	Informally: return the value within the root node
	*
	*	return void * the data item of the root node
*/
void *get_data(game_tree t)
{
	trace("get_data: get_data starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr,"get_data: empty game tree");
		exit(1);
	}

	trace("get_data: get_data ends");
	return get_t_node_data(t->root);
}
	
	
/*
	*	get_level
	*	Get function for "root" instance variable's level value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's data
	*					field's level is returned
	*	Informally: return the level value within the root node
	*
	*	return int the level number of the root node
*/
int get_level(game_tree t)
{
	trace("get_level: get_level starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_level: empty game tree");
		exit(1);
	}
	trace("get_level: get_level ends");
	return get_t_node_level(t->root);
}	
	

/*
*	get_parent
*	Get function for "root" instance variable's parent value.
*	Pre-condition: the game_tree variable is defined and valid
*	Post-condition: the value of the game_tree variable's parent
*					field is returned in a newly constructed
*					game_tree variable
*	Informally: return the game_tree variable's parent
*
*	return game_tree the parent of the current node
*/
game_tree get_parent(game_tree t)
{
	game_tree p; //the tree to store the parent of given tree

	trace("get_parent: get_parent starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_parent: empty game tree");
		exit(1);
	}

	init_game_tree(&p, true, NULL, -1);
	p->root = get_t_node_parent(t->root);

	trace("get_parent: get_parent ends");
	return p;
}


/*
*	get_child
*	Get function for "root" instance variable's child value.
*	Pre - condition: the game_tree variable is defined and valid
*	Post - condition : the value of the game_tree variable's child
*					field is returned in a newly
*					constructed game_tree variable
*	Informally : return the game_tree variable's child
*
*	return game_tree the eldest child of the current node
*/
game_tree get_child(game_tree t)
{
	game_tree c; //the tree to store the child of given tree

	trace("get_child: get_child starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_child: empty game tree");
		exit(1);
	}

	init_game_tree(&c, true, NULL, -1);
	c->root = get_t_node_child(t->root);

	trace("get_child: get_child ends");
	return c;
}


/*
	* 	get_sibling
	*	Get function for "root" instance variable's sibling value.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the value of the game_tree variable's sibling
	*					field is returned in a newly constructed 
	*					game_tree variable
	*	Informally: return the game_tree variable's sibling
	*
	*	return game_tree the next sibling of the current node
*/
game_tree get_sibling(game_tree t) 
{
	game_tree s; //the tree to store the sibling of given tree
		
	trace("get_sibling: get_sibling starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "get_sibling: empty game tree");
		exit(1);
	}

	init_game_tree(&s, true, NULL, -1);
	s->root = get_t_node_sibling(t->root);

	trace("get_sibling: get_sibling ends");
	return s;
}


/*
	*	set_data
	*	Set function for "root" instance variable's data field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's data field is altered to
	*					hold the given (o) value
	*	Informally: store the given value in the root node of the
	*				game_tree variable
	*
	*	param o void * to install as data for root node
*/
void set_data(game_tree t,void *o)
{
	trace("set_data: set_data starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr,"set_data: empty game tree");
		exit(1);
	}
		
	set_t_node_data(t->root,o);
		
	trace("set_data: set_data ends");
}
		
	
/*
	*	set_level
	*	Set function for "root" instance variable's level field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's level field is altered
	*					to hold the given (l) value
	*	Informally: assign the given value as the level of the
	*				game_tree variable
	*
	*	param l level number for root of current game tree
*/
void set_level(game_tree t,int l)
{
	trace("set_level: set_level starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_level: empty game tree");
		exit(1);
	}

	set_t_node_level(t->root, l);
		
	trace("set_level: set_level ends");
}
	
	
/*
	*	set_parent
	*	Set function for "root" instance variable's parent field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's parent field is altered
	*					to hold the given (p) value
	*	Informally: assign the given value as the parent of the
	*				game_tree variable
	*
	*	param p game_tree to be set as parent of current game tree
*/
void set_parent(game_tree t, game_tree p)
{
	trace("set_parent: set_parent starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_parent: empty game tree");
		exit(1);
	}

	set_t_node_parent(t->root, p->root);

	trace("set_parent: set_parent ends");
}


/*
	*	set_child
	*	Set function for "root" instance variable's child field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's child field is altered
	*					to hold the given (c) value
	*	Informally: assign the given value as the child of the
	*				game_tree variable
	*
	*	param c game_tree to be set as eldest child of current game tree
*/
void set_child(game_tree t, game_tree c)
{
	trace("set_child: set_child starts");

	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_child: empty game tree");
		exit(1);
	}

	set_t_node_child(t->root, c->root);

	trace("set_child: set_child ends");
}


/*
	*	set_sibling
	*	Set function for "root" instance variable's sibling field.
	*	Pre-condition: the game_tree variable is defined and valid
	*	Post-condition: the t_node variable's sibling field is altered
	*					to hold the given (s) value
	*	Informally: assign the given value as the sibling of the
	*				game_tree variable
	*
	*	param s game_tree to be set as next sibling of current game tree
*/
void set_sibling(game_tree t,game_tree s)
{
	trace("set_sibling: set_sibling starts");
		
	if (is_empty_game_tree(t))
	{
		fprintf(stderr, "set_sibling: empty game tree");
		exit(1);
	}

	set_t_node_sibling(t->root, s->root);

	trace("set_sibling: set_sibling ends");
}
	
	
/*
*	generate_levelBF
*	Generate the next level of the tree in a breadth-first manner
*	Pre-condition: the given tree is defined, the given queue
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the queue.
*	Informally: generate the next level of the game tree
*
*	param q Queue of reachable but unexpanded game trees
*/
void generate_levelBF(game_tree t, queue q)
{
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves
	int new_row; //the new row of game_state because of the possible vertical(row works up/down) knight move
	int new_column; //the new column of game_state because of the possible horizontal(left/right) knight move
	int new_level; //this is the new_level of the tree we are going to create
	game_tree new_tree; //the new tree to keep track of the new level we create
	game_tree sibling_tree; //for keeping track of the sibling to which we connect our new tree
	game_state original_state; //original game_state of the game_tree
	game_state clone_state; //this stores the clone of the original game_state 

	trace("generate_levelBF: generate_levelBF starts");

	original_state = (game_state)(get_data(t));
	new_level = get_level(t) + 1;

	//In this loop we are going through every possible horizontal and vertical knight moves
	for (int i = 0; i < MOVE_COUNT; i++)
	{
		clone_state = clone_game_state(original_state);
		//show_game_state(clone_state); //this code must can be executed to see the boards of all possible moves in the console
		new_row = get_row(clone_state) + VERT_MOVES[i];
		new_column = get_column(clone_state) + HORIZ_MOVES[i];
		

		if (valid(original_state, new_row, new_column) && (!taken(original_state, new_row, new_column)))
		{
			land(clone_state, new_row, new_column);
			init_game_tree(&new_tree, false, clone_state, new_level);
			set_parent(new_tree, t);

			if (is_empty_game_tree(get_child(t)))
			{
				set_child(t, new_tree);
				sibling_tree = new_tree;
			}

			else
			{
				set_sibling(sibling_tree, new_tree);
				sibling_tree = new_tree;
			}

			add(q, new_tree);
		}
	}

	trace("generate_levelBF: generate_levelBF ends");
}


/*
*	build_gameBF
*	Generate the game tree in a breadth-first manner
*	Pre-condition: the given queue and game tree are defined, and
*				   the given int value represents the desired depth
*				   of the tree
*	Post-condition: If the given tree isn't already deep enough, an
*					additional level of possible moves is added to
*					the given game tree and each tree node of the
*					new level also is added to the queue.
*					Finally, the next tree is determined by removing
*					the front of the queue and the process continues
*					until the queue is empty
*	Informally: generate the game tree from the current point
*				in a breadth-first manner until it is "d" levels
*				deep
*
*	param q Queue of reachable but unexpanded game trees
*	param d desired depth (length of tour) that game tree should be built to
*	return	the game tree with the first found solution, or an empty game
*			tree if there is no solution
*/
game_tree build_gameBF(game_tree t, queue q, int d)
{
	game_tree first_solution; //the game_tree with the first solution
	
	trace("build_gameBF: build_gameBF starts");
	
	if (is_empty_game_tree(t))
	{
		return t;
	}

	if (get_level(t) < d)
	{
		generate_levelBF(t, q);
		//if there is no solution then an empty tree will be returned
		if (is_empty_queue(q))
		{
			init_game_tree(&first_solution, true, NULL, -1);
			return first_solution;
		}
		else
		{
			first_solution = front(q);
			rear(q);
			return build_gameBF(first_solution, q, d);
			
		}
	}

	return t;

	trace("build_gameBF: build_gameBF ends");
}


/*
*	generate_levelDF
*	Generate the next level of the tree in a depth-first manner
*	Pre-condition: the given tree is defined, the given stack
*				   is defined
*	Post-condition: an additional level of possible moves has
*					been added to the given game tree and each
*					tree node of the new level also has been
*					added to the stack.
*	Informally: generate the next level of the game tree
*
*	param k Stack of reachable but unexpanded game trees
*/
void generate_levelDF(game_tree t, stack k)
{
	const int HORIZ_MOVES[] = { -2, -1, +1, +2, +2, +1, -1, -2 };	// moves left/right
	const int VERT_MOVES[] = { -1, -2, -2, -1, +1, +2, +2, +1 };	// moves up/down
	const int MOVE_COUNT = 8;										// number of potential moves
	int new_row; //the new row of game_state because of the possible vertical(row works up/down) knight move
	int new_column; //the new column of game_state because of the possible horizontal(left/right) knight move
	int new_level; //this is the new_level of the tree we are going to create
	game_tree new_tree; //the new tree to keep track of the new level we create
	game_tree sibling_tree; //for keeping track of the sibling to which we connect our new tree
	game_state original_state; //original game_state of the game_tree
	game_state clone_state; //this stores the clone of the original game_state 

	trace("generate_levelDF: generate_levelDF starts");

	original_state = (game_state)(get_data(t));
	new_level = get_level(t) + 1;

	//In this loop we are going through every possible horizontal and vertical knight moves
	for (int i = 0; i < MOVE_COUNT; i++)
	{
		clone_state = clone_game_state(original_state);
		//show_game_state(clone_state); //this code must can be executed to see the boards of all possible moves in the console
		new_row = get_row(clone_state) + VERT_MOVES[i];
		new_column = get_column(clone_state) + HORIZ_MOVES[i];


		if (valid(original_state, new_row, new_column) && (!taken(original_state, new_row, new_column)))
		{
			land(clone_state, new_row, new_column);
			init_game_tree(&new_tree, false, clone_state, new_level);
			set_parent(new_tree, t);

			if (is_empty_game_tree(get_child(t)))
			{
				set_child(t, new_tree);
				sibling_tree = new_tree;
			}

			else
			{
				set_sibling(sibling_tree, new_tree);
				sibling_tree = new_tree;
			}

			push(k, new_tree);
		}
	}

	trace("generate_levelDF: generate_levelDF ends");
}


/*
*	build_gameDF
*	Generate the game tree in a depth-first manner
*	Pre-condition: the given queue and game tree are defined, and
*				   the given int value represents the desired depth
*				   of the tree
*	Post-condition: If the given tree isn't already deep enough, an
*					additional level of possible moves is added to
*					the given game tree and each tree node of the
*					new level also is added to the stack.
*					Finally, the next tree is determined by removing
*					the top of the stack and the process continues
*					until the stack is empty
*	Informally: generate the game tree from the current point
*				in a depth-first manner until it is "d" levels
*				deep
*
*	param s Stack of reachable but unexpanded game trees
*	param d desired depth (length of tour) that game tree should be built to
*	return	the game tree with the first found solution, or an empty game
*			tree if there is no solution
*/
game_tree build_gameDF(game_tree t, stack s, int d)
{
	game_tree first_solution; //the game_tree with the first solution

	trace("build_gameDF: build_game starts");
	
	if (is_empty_game_tree(t))
	{
		return t;
	}

	if (get_level(t) < d)
	{
		generate_levelDF(t, s);
		//if there is no solution then an empty tree will be returned
		if (is_empty_stack(s))
		{
			init_game_tree(&first_solution, true, NULL, -1);
			return first_solution;
		}
		else
		{
			first_solution = top(s);
			pop(s);
			return build_gameDF(first_solution, s, d);

		}
	}
	return t;

	trace("build_gameDF: build_gameDF ends");
}


/*
	*	to_string_game_tree
	*	String conversion for tree
	*	Pre-condition: none
	*	Post-condition: a string variable is returned consisting of the
	*				string representation of all items in the game_tree,
	*				from top to bottom in depth-first order, separated by
	*				" " and contained within "<" and ">"
	*	Informally: produce a string representation of the game tree
	*
	*	return (char *) printable contents of game tree
*/
char *to_string_game_tree(game_tree t)
{
	game_tree c;
	char *s; //printable contents of game tree

	trace("to_string_game_tree: to_string_game_tree starts");
		
	if (is_empty_game_tree(t))
	{
		trace("to_string_game_tree: to_string_game_tree ends");
		return "<>";
	}
	else
	{
		s=(char *)malloc(200*5*sizeof(char));

		sprintf(s,"%s (%d,%d) ",s,get_row(get_data(t)),get_column(get_data(t)));
		c=get_child(t);
		if (! is_empty_game_tree(c))
		{
			sprintf(s,"%s %s ",s,to_string_game_tree(c));
		}
		c=get_sibling(t);
		if (! is_empty_game_tree(c))
		{
			sprintf(s,"%s %s ",s,to_string_game_tree(c));
		}
	}

	trace("to_string_game_tree: to_string_game_tree ends");

	return s;
}

