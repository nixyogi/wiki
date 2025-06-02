// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; 
  struct Node *next;
};

void push(struct Node **head_ref, int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = *(head_ref);
    *(head_ref) = newnode;
}

void printlist(struct Node *head) {
    while(head != NULL) {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("\n");
}

void freelist(struct Node *head) {
    struct Node *tmp; 
    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

struct Node *reverselist(struct Node **head_ref) {
    struct Node *prev = NULL; 
    struct Node *current = *(head_ref);
    struct Node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next;
    }
    return prev;
}

int main() {
    struct Node *head = NULL; 
    
    // Init 
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    printf("Original List: ");
    printlist(head); 
    reverselist(&head);
    printf("Rev List: ");
    printlist(head); 
    printf("\n");
    //freelist(head);
    
    return 0;
}
