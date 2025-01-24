#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct  node* next;
}Node;

Node*  newnode(int value)
{
    Node* temp =(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->next =NULL;
    return temp;

}

void insertAtEnd(Node** head,int data)
{
    if(*head ==NULL)
    {
        *head =newnode(data);
    }
    else{
        Node*temp =*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode(data);
    }
}
void removeDuplicate(Node **head)
{
   Node* temp =*head;
   
   while(temp!=NULL && temp->next!=NULL)
   {
    
    if(temp->data == temp->next->data)
    {
        temp->next =temp->next->next;
    }
    else{
    
    temp=temp->next;
    }
   }
}
int main()
{
Node* head =NULL;
int n;
    int value;
    scanf("%d",&n);
    while(n)
    {
        printf("Enter node data ");
        scanf("%d",&value);
        insertAtEnd(&head,value);
        n--;
    }
Node *trav=head;
while(trav!=NULL)
{
    printf("%d ",trav->data);
    trav =trav->next;
}
printf("\n");
removeDuplicate(&head);
printf("After\n");
Node *trav1=head;

while(trav1!=NULL)
{
    printf("%d ",trav1->data);
    trav1 =trav1->next;
}
}