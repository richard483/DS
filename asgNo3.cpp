#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int value;
    node *next;
} *head, *tail;

int count = 0;

node *createNode (int score){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = score;
    newNode->next = NULL;
    return newNode;
}


void pushTail (int score) {
    node *temp = createNode(score);
    if(!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}



int midSearch()
{
    int mid=0;
    node *curr = head;
    while(curr)
    {curr = curr->next;
        mid++;
    }mid = mid/2;
    return mid;
}

void print(int a)
{
    int b=1;
    node *curr = head;
    while(b<a)
    {
        curr = curr->next;
        b++;
    }
    printf("%d\n",curr->value);
}
void printList()
{
    node* curr = head;
    while(curr)
    {
        printf("%d ",curr->value);
        curr = curr->next;
    }printf("\n");
}

int main()
{
    int arr[10]={2020, 2012, 2010, 2002, 2005, 2009, 2007, 2007, 1, 2};
    for(int i=0; i<10; i++)
    {
        pushTail(arr[i]);
    }
    printf("Letak nilai tengah:\n");
    printf("%d\n",midSearch());
    printf("Nilai tengan:\n");
    print(midSearch());

    
    return 0;
}