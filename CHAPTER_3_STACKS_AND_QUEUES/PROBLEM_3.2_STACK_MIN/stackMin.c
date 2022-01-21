/*
	Problem 3.2 STACK MIN
	How would you design a stack which, in addition to push and pop, has
    a function min() which returns the minimum element? Push, pop, and min
    should all operate in O(1) time.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void pop(node **StackTop) {
    node *temp = (*StackTop)->next;

    if (*StackTop == NULL) {
        printf("Nothing to pop!");
    }
    else {
        free(*StackTop);
        *StackTop = temp;
    }
}

void push(node **StackTop, int value) {
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    
    // If stack is empty, 
    if (*StackTop == NULL) {
        *StackTop = newNode;
    }
    else {
        if (value < (*StackTop)->data) {
            newNode->next = *StackTop;
            *StackTop = newNode;
        }
        else {
            node *prev = *StackTop;
            node *curr = (*StackTop)->next;
            
            while (1) {
                if ((curr == NULL) || (value < curr->data)) {
                    prev->next = newNode;
                    newNode->next = curr;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void Display(node *StackTop) {
    node *temp = StackTop;
    while (temp != NULL) {
        printf("Node address: %p. Node data: %3d. Point to node: %p\n",
            temp, temp->data, temp->next);
        temp = temp->next;
    }
}

int main() {
    node *StackTop = NULL;
    
    int i;
    for (i = 0 ; i < 10 ; i++) {
        push(&StackTop, rand() % 50);
    }
    
    Display(StackTop);
    
    return 0;
}
