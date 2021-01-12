#include<stdio.h> 
#include<stdlib.h> 
#include <string.h>

struct Node 
{ 
    int angka; 
    struct Node* next; 
}; 

void MoveNode(struct Node** destRef, struct Node** sourceRef); 

struct Node* SortedMerge(struct Node* a, struct Node* b)
{ 
    struct Node dummy; 
    struct Node* tail = &dummy; 
    dummy.next = NULL; 
    while (1)
    { 
        if (a == NULL)
        { 
            tail->next = b; 
            break; 
        } 
        else if (b == NULL) 
        { 
            tail->next = a; 
            break; 
        } 
        if (a->angka <= b->angka) 
            MoveNode(&(tail->next), &a); 
        else
            MoveNode(&(tail->next), &b); 
        tail = tail->next; 
    } 
    return(dummy.next); 
} 
  
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{ 
    struct Node* newNode = *sourceRef; 
    *sourceRef = newNode->next; 
    newNode->next = *destRef; 
    *destRef = newNode; 
} 
void push(struct Node** head_ref, int new_angka)
{ 
    struct Node* new_node = 
    (struct Node*) malloc(sizeof(struct Node)); 
    new_node->angka  = new_angka; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  

void printList(struct Node *node)
{ 
    while (node!=NULL)
    { 
        printf("%d ", node->angka); 
        node = node->next; 
    } 
} 
  

int main() 
{ 
    struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL; 

    push(&a, 312); push(&a, 302); push(&a, 50); 
    push(&b, 10); push(&b, 32); push(&b, 22); 
    
    res = SortedMerge(a, b); 
    printf("Merged Linked List is: \n"); 
    printList(res); 
    return 0; 
} 