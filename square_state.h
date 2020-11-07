/*
*	Square State
*	Author: J.R.Dermoudy
*	Version: September 2019
*
*	This file holds the specification of the square_state.
*
*	This file is complete.
*/

#ifndef _SQUARE_STATE
#define _SQUARE_STATE

#include <stdbool.h>

struct square_state_int;
typedef struct square_state_int *square_state;

void init_square_state(square_state *sp, int r, int c);
void set_row_num(square_state s, int r);
void set_column_num(square_state s, int c);
int get_row_num(square_state s);
int get_column_num(square_state s);
int get_count(square_state s);
bool occupied(square_state s);
void occupy(square_state s, int m);
square_state clone_square_state(square_state s);
void show_square_state(square_state s);

#endif