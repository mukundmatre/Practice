#ifndef __STACK_DS_H__
#define __STACK_DS_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack_Node
{
  struct Node* data;
  struct stack_Node *next;
};

void stack_push(struct stack_Node** top_ref, struct Node* new_data);
void stack_pop(struct stack_Node** top_ref);
void Print(struct stack_Node *node);
bool isEmpty(struct stack_Node* top);
#endif
