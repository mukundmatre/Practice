#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct bstNode {
  int data;
  struct bstNode* left;
  struct bstNode* right;
}bstNode_t;

bstNode_t* Insert(bstNode_t* rootptr, int new_data);
bstNode_t* newNode(int new_data);
bool Search(bstNode_t* rootptr, int data);
bstNode_t* findptr(bstNode_t* rootptr, int data);
int FindMin(bstNode_t* rootptr);
int FindMax(bstNode_t* rootptr);
int FindHeight(bstNode_t* rootptr);
bool isSubTreeLesser(bstNode_t* rootptr, int value);
bool isSubTreeGreater(bstNode_t* rootptr, int value);
bool isBST(bstNode_t* rootptr);
bstNode_t* FindMinptr(bstNode_t* rootptr);
bstNode_t* Delete(bstNode_t* rootptr, int data);
bstNode_t* inorder_successor(bstNode_t* rootptr, int data);


bstNode_t* newNode(int new_data) {
  bstNode_t* new_node = (bstNode_t*) malloc(sizeof(bstNode_t));
  new_node->data = new_data;
  return new_node;
}

bstNode_t* Insert(bstNode_t* rootptr, int new_data) {
  if (rootptr==NULL) {
    rootptr = newNode(new_data);
  } else if (new_data <= rootptr->data) {
    rootptr->left = Insert(rootptr->left, new_data);
  } else {
    rootptr->right = Insert(rootptr->right, new_data);
  }
  return rootptr;
}

bool Search(bstNode_t* rootptr, int data) {
  if (rootptr==NULL) {
    return false;
  } else if (rootptr->data == data) {
    return true;
  } else if (data < rootptr->data) {
    return Search(rootptr->left, data);
  } else {
    return Search(rootptr->right, data);
  }
}


bstNode_t* findptr(bstNode_t* rootptr, int data) {
  if (rootptr==NULL) {
    return NULL;
  } else if (rootptr->data == data) {
    return rootptr;
  } else if (data < rootptr->data) {
    return findptr(rootptr->left, data);
  } else {
    return findptr(rootptr->right, data);
  }
}



int FindMin(bstNode_t* rootptr) {
  if (rootptr==NULL) {
    printf("Empty Tree\n");
    return -1;
  } else if (rootptr->left == NULL) {
    return rootptr->data;
  } else {
    return FindMin(rootptr->left);
  }
}

int FindMax(bstNode_t* rootptr) {
  if (rootptr==NULL) {
    printf("Empty Tree\n");
    return -1;
  } else if (rootptr->right == NULL) {
    return rootptr->data;
  } else {
    return FindMax(rootptr->right);
  }
}

int FindHeight(bstNode_t* rootptr) {
  int leftHeight;
  int rightHeight;
  if (rootptr == NULL) {
    return -1;
  } else {
    leftHeight = FindHeight(rootptr->left);
    rightHeight = FindHeight(rootptr->right);
    return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
  }
}

bool isSubTreeLesser(bstNode_t* rootptr, int value) {
  if (rootptr == NULL) {
    return true;
  }
  if ((rootptr->data < value) && isSubTreeLesser(rootptr->left, value) &&
  isSubTreeLesser(rootptr->right, value)) {
    return true;
  } else {
    return false;
  }
}
bool isSubTreeGreater(bstNode_t* rootptr, int value) {
  if (rootptr == NULL) {
    return true;
  }
  if ((rootptr->data > value) && isSubTreeGreater(rootptr->left, value) &&
  isSubTreeGreater(rootptr->right, value)) {
    return true;
  } else {
    return false;
  }
}
bool isBST(bstNode_t* rootptr) {
  if (rootptr == NULL) {
    return true;
  }
  if (isSubTreeLesser(rootptr->left, rootptr->data) &&
  isSubTreeGreater(rootptr->right, rootptr->data) &&
  isBST(rootptr->left) && isBST(rootptr->right)) {
    return true;
  } else {
    return false;
  }
}

bstNode_t* FindMinptr(bstNode_t* rootptr) {
  if (rootptr==NULL) {
    printf("Empty Tree\n");
    return NULL;
  } else if (rootptr->left == NULL) {
    return rootptr;
  } else {
    return FindMinptr(rootptr->left);
  }
}

bstNode_t* Delete(bstNode_t* rootptr, int data) {
  if (rootptr == NULL) {
    return rootptr;
  } else if (data < rootptr->data) {
    rootptr->left = Delete(rootptr->left, data);
  } else if (data > rootptr->data) {
    rootptr->right = Delete(rootptr->right, data);
  } else {
    if ((rootptr->left == NULL) && (rootptr->right == NULL)) {
      free(rootptr);
      rootptr = NULL;
    } else if (rootptr->left == NULL) {
      bstNode_t* temp = rootptr;
      rootptr = rootptr->right;
      free(temp);
    } else if (rootptr->right == NULL) {
      bstNode_t* temp = rootptr;
      rootptr = rootptr->left;
      free(temp);
    } else {
      bstNode_t* temp = FindMinptr(rootptr->right);
      rootptr->data = temp->data;
      rootptr->right =  Delete(rootptr->right, temp->data);
    }
  }
  return rootptr;
}

// IMPORTANT: Remember that Inorder means left->root->right, so if current node
// is right of some node than that node has already been visited.
bstNode_t* inorder_successor(bstNode_t* rootptr, int data) {
  bstNode_t* current = findptr(rootptr, data);
  if (current==NULL) {
    return NULL;
  }
  if (current->right !=NULL) {
    return FindMinptr(current->right);
  }
  else {
    bstNode_t* successor = NULL;
    bstNode_t* ancestor = rootptr;
    while (ancestor!=current) {
      if (current->data <= ancestor->data) {
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else {
        ancestor = ancestor->right;
      }
    }

    return successor;
  }
}


int main(void) {
  bstNode_t* rootptr = NULL;
  rootptr = Insert(rootptr, 15);
  rootptr = Insert(rootptr, 10);
  rootptr = Insert(rootptr, 20);
  rootptr = Insert(rootptr, 25);
  rootptr = Insert(rootptr, 8);
  rootptr = Insert(rootptr, 12);
  rootptr = Insert(rootptr, 11);
  rootptr = Insert(rootptr, 19);
  rootptr = Insert(rootptr, 29);
  rootptr = Insert(rootptr, 57);
  rootptr = Insert(rootptr, 16);
  rootptr = Insert(rootptr, 13);
  if (Search(rootptr, 20)) {
    printf("Found\n");
  }
  else {
    printf("Not Found\n");
  }
  printf("Minimum value in tree: %d\n", FindMin(rootptr));
  rootptr = Delete(rootptr, 57);
  printf("Maximum value in tree: %d\n", FindMax(rootptr));
  printf("Height of tree: %d\n", FindHeight(rootptr));
  printf("%d\n", isBST(rootptr));
  // rootptr = Delete(rootptr, 20);
  if (Search(rootptr, 20)) {
    printf("Found\n");
  }
  else {
    printf("Not Found\n");
  }
  return 0;
}
