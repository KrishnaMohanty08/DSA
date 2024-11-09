#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void main()
{
    struct node *head,*second,*third ,*fourth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth =(struct node*)malloc(sizeof(struct node));
    //Linking first and second nodes
    head->data=7;
    head->next=second;

    //Linking second and third node
    second->data=11;
    second->next=third;

    //Linking third and null node
    third->data=9;
    third->next=fourth;
    
    fourth->data=33;
    fourth->next=NULL;

    //traversing(head);
    countOfNodes(head);
}