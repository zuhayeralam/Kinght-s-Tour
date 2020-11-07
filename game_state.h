/*
*	Game State
*	Author: J.R.Dermoudy
*	Version: September 2019
*
*	This file holds the specification of the game_state.
*
*	This file is complete.
*/

#ifndef _GAME_STATE
#define _GAME_STATE

#include <stdbool.h>
#include "square_state.h"

struct game_state_int;
typedef struct game_state_int *game_state;

void init_game_state(game_state *gp);
square_state get_square(game_state g, int r, int c);
void set_square(game_state g, square_state s);
int get_row(game_state g);
void set_row(game_state g, int r);
int get_column(game_state g);
void set_column(game_state g, int c);
int get_moves(game_state g);
void set_moves(game_state g, int m);
bool valid(game_state g, int r, int c);
bool taken(game_state g, int r, int c);
void land(game_state g, int r, int c);
game_state clone_game_state(game_state g);
void show_game_state(game_state g);

#endif