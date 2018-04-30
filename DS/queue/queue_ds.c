#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

void enqueue(struct Node** front_ref, struct Node** rear_ref, int new_data);
void dequeue(struct Node** front_ref, struct Node** rear_ref);
void printList(struct Node *node);

void enqueue(struct Node** front_ref, struct Node** rear_ref, int new_data) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;
  if ((*front_ref==NULL) && (*rear_ref==NULL)) {
    *rear_ref = new_node;
    *front_ref = new_node;
    return;
  }
  struct Node* last = *rear_ref;
  last->next = new_node;
  *rear_ref = new_node;
}

void dequeue(struct Node** front_ref, struct Node** rear_ref) {
  struct Node* first = *front_ref;
  if (*front_ref==NULL) {
    return;
  }
  if (*front_ref==*rear_ref) {
    *front_ref = *rear_ref = NULL;
  }
  *front_ref = first->next;
  free(first);
}

void printList(struct Node *node)
{
  while (node!=NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main(void) {
  struct Node* front = NULL;
  struct Node* rear = NULL;
  enqueue(&front, &rear, 1);
  enqueue(&front, &rear, 2);
  // dequeue(&front, &rear);
  //dequeue(&front, &rear);
  printf("Queue is:");
  printList(front);
  printf("\n");
  return 0;
}
