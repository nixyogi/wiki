// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node *next; 
};

void push(struct Node **head_ref, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; 
    newNode->next = *(head_ref); 
    *(head_ref) = newNode;
}

void append(struct Node **head_ref, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data; 
    newNode->next = NULL;
    // Traverse till the end of the linked list
    struct Node *last;
    last = *(head_ref);
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void printList(struct Node *node){
    while(node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node *reverseList(struct Node **head_ref) {
    struct Node *prev = NULL;
    struct Node *current = *(head_ref); 
    struct Node *next = NULL; 
    
    while(current != NULL) {
        // Reverse current node 
        next = current->next;
        current->next = prev;
        // Move to next poin
        prev = current; 
        current = next; 
    }
    return prev;
}

int main() {
    struct Node *head = NULL;
    
    push(&head, 1); 
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    printf("\nOriginal list: ");
    printList(head);
    head = reverseList(&head); 
    printf("\nReverse list: ");
    printList(head);

    return 0;
}