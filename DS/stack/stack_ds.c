#include "stack_ds.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// A linked list node


void stack_push(struct stack_Node** top_ref, struct Node* new_data)
{
  struct stack_Node* new_node = (struct stack_Node*) malloc(sizeof(struct stack_Node));
  new_node->data = new_data;
  new_node->next = *top_ref;
  *top_ref = new_node;
}

void stack_pop(struct stack_Node** top_ref)
{
  struct stack_Node* node_stack_pop = *top_ref;
  *top_ref = node_stack_pop->next;
  free(node_stack_pop);
}

// void Print(struct stack_Node *node)
// {
//   while (node!=NULL) {
//     printf(" %d ", node->data);
//     node = node->next;
//   }
// }

bool isEmpty(struct stack_Node* top) {
  if (top==NULL) {
    return true;
  }
  else {
    return false;
  }
}

// int main(void) {
//   struct stack_Node* top = NULL;
//   printf("Empty:%d\n", isEmpty(top));
//   stack_push(&top, 1);
//   stack_push(&top, 2);
//   stack_push(&top, 3);
//   stack_pop(&top);
//   printf("Empty:%d\n", isEmpty(top));
//   printf("\nStack:");
//   Print(top);
//   printf("\n");
//
//   return 0;
// }
