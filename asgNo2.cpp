#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int angka;
    node *next;
} *head, *tail;

node *createNode (int score)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->angka = score;
    newNode->next = NULL;
    return newNode;
}


void pushTail (int score) {
    node *temp = createNode(score);
    if(!head)
        head = tail = temp;
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

int max()
{
    int max = 0;
    node *curr = head;
    while(curr)
    {
        if (max < curr->angka)
        {
            max = curr->angka;
        }
        curr = curr->next;
    }
    return max;
}
int min()
{
    int min = 100000;
    node *curr = head;
    while(curr)
    {
        if (min > curr->angka)
        {
            min = curr->angka;
        }
        curr = curr->next;
    }
    return min;
}

int main()
{

    int arr[10]={202, 303, 404, 321, 213, 345, 123, 6787, 234, 345};
    for(int i=0; i<10; i++)
    {
        pushTail(arr[i]);
    }
    printf("max: %d\n",max());
    printf("min: %d\n",min());
    printf("range: %d\n",max() - min());
    return 0;
}