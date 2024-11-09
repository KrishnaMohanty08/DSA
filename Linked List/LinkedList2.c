#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

int countNodes(struct node *ptr){
    int count =0;
    while(ptr!=NULL){
        ptr=ptr->link;
        count ++;
    }printf("\ncount =%d",count);
}
int insertingEnd(struct node *ptr){
    struct node *temp ;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter value1 :");
    scanf("%d",&(temp->data));
    temp->link=NULL;
    ptr->link=temp;
    
}
int insertingStart(struct node **ptr){
    struct node *temp ;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter value at 1st position:");
    scanf("%d ",&temp->data);
    temp->link=*ptr;
    *ptr=temp;
    
}
int delStart(struct node **head){
    if(*head==NULL)
        printf("The Linked list is empty");
    else {
        struct node *temp=*head;
        *head=(*head)->link;
        free(temp);
        temp=NULL;
    }return head;
}
int delLast(struct node *head){
    if(head==NULL)
        printf("The Linked node is null");
        
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head,*temp2=head;
        while(temp-> link!=NULL){
            temp2 =temp;
            temp =temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }return head;
}
int delLast2(struct node *head){
    if(head==NULL)
        printf("The Linked node is null");
        
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
    struct node *temp=head;
    while(temp->link->link!=NULL){
        temp=temp->link;
        }
    free(temp->link);
    temp->link=NULL;
    }
}
int insertAtPos(struct node *head){
    struct node *new,*ptr;
    int pos;
    ptr=malloc(sizeof(struct node));
    ptr=head;
    //exception case for null
    if(ptr==NULL){
        printf("The List is Null");
    }else {
        
        //new node creation and data input
        new=malloc(sizeof(struct node));
        printf("Enter value of new node :");
        scanf("%d",&(new->data));

        // position to at which the new node need to be inserted
        printf("Enter position");
        scanf("%d",&pos);
        for(int i=0;i<pos-1;i++){
            ptr=ptr->link;
        }new->link = ptr->link;
        ptr->link = new;
    }
}
int delAtPos(struct node *head){
    int pos;
    if(head==NULL){
        printf("The Linked node is null");
    }else {
        struct node *now,*next;
        now=head;
        next=head->link;
        printf("Enter the position :");
        scanf("%d",&pos);
        int i=1;
        while(i<pos)
        {
            if(pos==1){
                printf("done alr");
                i++;
            }else
            {
                next=next->link;
                now=now->link;
                i++;
              }
        }
        now->link=next->link;
        free(next);
        next=NULL;
        }
    } 
int reverse(struct node *head){
    struct node *prev=NULL;
    struct node *next=NULL;
    while (head!=NULL){
        next =head->link;
        head->link=prev;
        prev=head;
        head=next;
    }head=prev;
    
}
void swap(struct node *ptr1,struct node *ptr2){
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data=temp;
}
int sorting(struct node *head){
    if((head==NULL||head->link==NULL||
    (head->data<=head->link->data))&&sorting(head->link)){
      return ;
    }int swapped;
    do{
        swapped=0;
        struct node *ptr1,*ptr2;
        ptr1=head;
        ptr2=head->link;
        while (ptr2!=NULL){
            if(ptr1->data>ptr2->data){
                swap(ptr1,ptr2);
                swapped=1;
            }
            ptr2=ptr2->link;
            ptr1=ptr1->link;
        }
      
    }while(swapped);
}
int searchElement(struct node *head){
    struct node *temp=head;
    int key,count=1;
    printf("Enter the KEY");
    scanf("%d",&key);
    if(head==NULL){
        printf("Linked list is empty");
    }else{
        if(head->data==key){
            printf("The key found at index %d",count);
        }
        temp=temp->link;
        count++;
    }
}

/*--------------------main--------------------*/
int main(){
    struct node *head ,*current,*prev;
    head =(struct node*)malloc(sizeof(struct node));
    
    printf("enter value :");
    scanf("%d",&(head->data));
    head->link=NULL;
    prev=head;
    int i=5;
    do{
        current =(struct node*)malloc(sizeof(struct node));
        printf("enter value :");
        scanf("%d",&(current->data));
        current->link=NULL;
        prev->link=current;
        prev=current;
        i--;
        }while(i>0);
    
    
    //countNodes(head);
    //insertingEnd(current);
    //insertingStart(&head);
    //delStart(&head);
    //head=delLast(head);
    //delLast2(head);
    //delAtPos(head);
    //insertAtPos(head);
    //reverse(head);
    //sorting(head);
    searchElement(head);

    current = head;
    while(current!=NULL){
        printf("\n%d ",current->data);
        current=current->link;
    }

}