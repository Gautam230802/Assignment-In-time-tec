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

void insertionSort(Node **head,int n)
{
    Node* curr =*head;
    Node* already =NULL;

    while(curr!=NULL)
    {
        if(already==NULL || already->data >= curr->data)
        {
            curr->next=already;
            already =curr;
        }
        else{
            Node*temp =already;
            while(temp->next!=NULL && temp->next->data < curr->data)
            {
                temp =temp->next;
            }
            curr->next=temp->next;
            temp->next =curr;

        }
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

    insertionSort(&head,newn);
   Node*temp1 =head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1 =temp1->next;
    }

}