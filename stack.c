/*
 * Implementation for Stack using linked-list
 *	Author:  Zuhayer Alam
 *	Version: 1 October 2019
 *
 *	This file holds the stack ADT.  It comprises
 *	a top-of-stack field (tos).
 *
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"


// types
struct stack_int {
	node tos;
};


/*
*	init_stack
*	initialiser function.
*	Pre-condition: none
*	Post-condition: create a new stack variable with a NULL tos
*					field and the address of it assigned to the
*					parameter (sp)
*	Informally: creates an empty stack
*/
void init_stack(stack *sp)
{
	*sp = (stack)malloc(sizeof(struct stack_int));
	(*sp)->tos = NULL;
}


/*
*	is_empty_stack
*	Emptiness test.
*	Pre-condition: the stack variable is defined and valid
*	Post-condition: true is returned if the stack variable is
*					empty, false is returned otherwise
*	Informally: indicate if the stack contains no nodes
*
*	return boolean whether or not the stack is empty
*/
bool is_empty_stack(stack s)
{
	return (s->tos == NULL);
}


/*
*	top
*	Find value at top of stack.
*	Pre-condition: the stack variable is defined and valid
*	Post-condition: the value at the top of stack is returned
*	Informally: find the value at the top of stack
*
*	return (void *) the value on top of the stack
*/
void *top(stack s)
{
	if (is_empty_stack(s))
	{
		fprintf(stderr, "Stack is empty.");
		exit(1);
	}

	return get_data_node(s->tos);
}


/*
*	pop
*	Remove top of the stack
*	Pre-condition: the stack variable is defined and valid
*	Post-condition: the value at the top of stack is deleted updating
*					the "tos" field accordingly
*	Informally: delete the top of the stack
*/
void pop(stack s)
{
	if (is_empty_stack(s))
	{
		fprintf(stderr, "Stack is empty.");
		exit(1);
	}
	
	else 
	{
		s->tos = get_next_node(s->tos);
	}
}


/*
*	push
*	Add item to top of stack
*	Pre-condition: the stack variable is defined and valid
*	Post-condition: a new node is created containing the parameter
*					value (o) in the data field and the existing
*					stack in the next field and this is inserted 
*					at the front of the linked list with the tos 
*					field of the stack parameter (s) set to point
*					to it
*
*	Param o value to be added to top of stack
*/
void push(stack s,void *o)
{
	node n; //new node where the data will be stored and then the node to be put in the stack

	init_node(&n, o);
	set_next_node(n, s->tos);
	s->tos = n;
}


/*
*	to_string_stack
*	String conversion for stack
*	Pre-condition: none
*	Post-condition: a string variable is returned consisting of the
*				string representation of all items in the stack,
*				from left to right, separated by " " and contained
*				within "<" and ">"
*	Informally: produce a string representation of the stack
*
*	return (char *) printable contents of stack
*/
char *to_string_stack(stack k, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s=(char *)malloc(100*10*sizeof(char));
	
	if (is_empty_stack(k))
	{
		s = "<>";
	}
	else 
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = k->tos;
		while (c != NULL)
		{
			sprintf(s, fmt, s,*(int *)(get_data_node(c)));
			if (get_next_node(c) != NULL)
			{
				sprintf(s, "%s, ", s);
			}
			c = get_next_node(c);
		}
	}
	return s;
}
