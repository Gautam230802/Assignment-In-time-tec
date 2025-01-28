#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* newnode(int data)
{
    Node* temp =(Node*)malloc(sizeof(Node));
    temp->data =data;
    temp->next =NULL;
    return temp;
}
void insertAtEnd(Node**head, int data)
{
    if(*head==NULL)
    {
        *head=newnode(data);
    }
    else{
        Node*temp =*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next =newnode(data);
    }
}

void selectionSort(Node **head,int n)
{
    Node* curr =*head;
    while(curr!=NULL)
    {
        Node* mini=curr;
        Node*temp=curr->next;
        while(temp!=NULL)
        {
            if(mini->data > temp->data)
            {
                mini=temp;
            }
            temp=temp->next;
        }
        int tempi =mini->data;
        mini->data =curr->data;
        curr->data =tempi;

        curr=curr->next;
    }
    
}
int main()
{
    Node* head=NULL;
    printf("Enter numbers of Node");
    int n,value;
    scanf("%d",&n);
    int newn =n;
    while(n)
    {
        printf("enter node vaue ");
        scanf("%d",&value);
        insertAtEnd(&head,value);
        n--;
    }

    Node* temp =head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp =temp->next;
    }

    selectionSort(&head,newn);
   Node*temp1 =head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1 =temp1->next;
    }

}