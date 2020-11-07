/*
*	Game Tree
*	Author: J.R.Dermoudy
*	Version: September 2019
*
*	This file holds the specification of the game_tree.
*
*	This file is complete.
*/

#ifndef _GAME_TREE
#define _GAME_TREE

#include <stdbool.h>
#include "queue.h"
#include "stack.h"

struct game_tree_int;
typedef struct game_tree_int *game_tree;

void init_game_tree(game_tree *gp, bool e, void *o, int l);
bool is_empty_game_tree(game_tree g);
void set_data(game_tree g, void *o);
void *get_data(game_tree g);
void set_level(game_tree g, int l);
int get_level(game_tree g);
void set_parent(game_tree g, game_tree p);
game_tree get_parent(game_tree g);
void set_child(game_tree g, game_tree c);
game_tree get_child(game_tree g);
void set_sibling(game_tree g, game_tree s);
game_tree get_sibling(game_tree g);
void generate_levelBF(game_tree g, queue q);
game_tree build_gameBF(game_tree g, queue q, int d);
void generate_levelDF(game_tree g, stack s);
game_tree build_gameDF(game_tree g, stack s, int d);
char *to_string_game_tree(game_tree g);

#endif