// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>
#include "../DS/stack/stack_ds.h"

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

void reverse_iter(struct Node** head_ref);
void reverse_rec(struct Node** head_ref, struct Node* p);
void reverse_stack(struct Node** head_ref);


void reverse_iter(struct Node** head_ref) {
  struct Node* prev_node = NULL;
  struct Node* curr_node = *head_ref;
  struct Node* next_node = NULL;
  while (curr_node!=NULL) {
    next_node = curr_node->next;
    curr_node->next = prev_node;
    prev_node = curr_node;
    curr_node = next_node;
  }
  *head_ref = prev_node;
}

void reverse_rec(struct Node** head_ref, struct Node* p) {
  if (p->next==NULL) {
    *head_ref = p;
    return;
  }
  reverse_rec(head_ref, p->next);
  struct Node* q = p->next;
  q->next = p;
  p->next = NULL;
}

void reverse_stack(struct Node** head_ref) {
  struct Node* temp = *head_ref;
  if (temp==NULL) {
    return;
  }
  struct stack_Node* top;
  while (temp!=NULL) {
    stack_push(&top, temp);
    temp = temp->next;
  }
  temp = top->data;
  *head_ref = temp;
  stack_pop(&top);
  while (!isEmpty(top)) {
    temp->next = top->data;
    stack_pop(&top);
    temp = temp->next;
  }
  temp->next = NULL;
}


/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}


// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  while (node!=NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

/* Driver program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;
  push(&head, 6);
  //
  push(&head, 5);

  push(&head, 4);
  //
  push(&head, 3);

  push(&head, 2);
  //
  push(&head, 1);
  //
  push(&head, 6);
  //
  push(&head, 5);

  push(&head, 4);
  //
  push(&head, 3);

  push(&head, 2);
  //
  push(&head, 1);
  //
  // reverse_iter(&head);
  // Delete(&head, 6);
  reverse_rec(&head, head);
  // reverse_stack(&head);
  printf("\nCreated Linked list is: ");
  printList(head);
  printf("\n");

  return 0;
}
