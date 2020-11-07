/*
*	Tree Node
*	Author: J.R.Dermoudy
*	Version: September 2019
*
*	This file holds the specification of the game tree nodes.
*
*	This file is complete.
*/

#ifndef _TREE_NODE
#define _TREE_NODE

#include <stdbool.h>

struct t_node_int;
typedef struct t_node_int *t_node;

void init_t_node(t_node *tp, void *o, int l);
void set_t_node_data(t_node t, void *o);
void *get_t_node_data(t_node t);
void set_t_node_level(t_node t, int l);
int get_t_node_level(t_node t);
void set_t_node_parent(t_node t, t_node n);
t_node get_t_node_parent(t_node t);
void set_t_node_child(t_node t, t_node n);
t_node get_t_node_child(t_node t);
void set_t_node_sibling(t_node t, t_node n);
t_node get_t_node_sibling(t_node t);

#endif