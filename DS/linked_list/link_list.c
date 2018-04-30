// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};


void reverse(struct Node** head_ref) {
  struct Node* curr_node = *head_ref;
  struct Node* prev_node = NULL;
  struct Node* next_node = NULL;
  while (curr_node!=NULL) {
    next_node = curr_node->next;
    curr_node->next = prev_node;
    prev_node = curr_node;
    curr_node = next_node;
  }
  *head_ref = prev_node;
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

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void Delete(struct Node** head_ref, int n)
{
  struct Node* prev_node = *head_ref;
  if (n==1) {
    *head_ref = prev_node->next;
    free(prev_node);
    return;
  }
  for (int i = 0; i < n-2; i++) {
    prev_node = prev_node->next;
  }
  struct Node* curr_node = prev_node->next;
  if(curr_node==NULL){
    return;
  }
  prev_node->next = curr_node->next;
  free(curr_node);

}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  struct Node* last_node = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = new_node;
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

  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);

  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7);
  //
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push(&head, 1);
  //
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
  //
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);

  reverse(&head);
  // Delete(&head, 6);

  printf("\nCreated Linked list is: ");
  printList(head);
  printf("\n");

  return 0;
}
