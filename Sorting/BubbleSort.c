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

void bubbleSort(Node **head,int n)
{
    int cnt=0;

    while(cnt<n-1)
    {
        Node* curr=*head;
        Node* prev =*head;
        while(curr->next!=NULL)
        {
            Node* currNext=curr->next;

            if(currNext->data <curr->data)
            {
                if(curr==*head)
                {
                    curr->next=currNext->next;
                    currNext->next=curr;
                    prev =currNext;
                    *head =currNext;
                    
                }
                else{
                    curr->next =currNext->next;
                    currNext->next =curr;
                    prev->next =currNext;
                    prev=currNext;
                }
                continue;
            }
            prev =curr;
            curr=curr->next;
        }
        cnt++;
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

    bubbleSort(&head,newn);
   Node*temp1 =head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1 =temp1->next;
    }

}