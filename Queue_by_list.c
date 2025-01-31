/*Description: Implementing Queue using linked list
Time complexity: O(1) for all operations. 
space complexity: O(n)
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
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

void insertAtEnd(Node** head,int data)
{
    if(*head==NULL)
    {
        *head =newnode(data);
    }
    else
    {
        Node* curr=*head;
        while(curr->next!=NULL)
        {
            curr =curr->next;
        }
        curr->next=newnode(data);
    }
}

void deleteAtBegin(Node** head)
{
    if(*head!=NULL)
    {
        Node* curr =*head;
        *head =curr->next;
        curr->next =NULL;
    }
}
int isempty(Node** q)
{
    return (*q ==NULL);
}

void enqueue(Node** q,int data)
{
        insertAtEnd(q,data);
    
}

void dequeue(Node** q)
{
    if(isempty(q))
    {
        printf("Empty Queue\n");
    }
    else{
        deleteAtBegin(q);
    }
}

void peek(Node** q)
{
    if(isempty(q))
    {
        printf("empty queue\n");
    }
    else{
        printf(" front element is :%d\n",(*q)->data);
    }
}

void size(Node **q)
{
    Node* temp =*q;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp =temp->next;
    }
    printf("size of queue:%d\n",cnt);
}
int main()
{
    Node * q=NULL;
    int op;
     int n;
    printf("No. of operations :");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the eoperation: ");
        scanf("%d",&op);
        int data;
        switch(op)
        {
            case 1: printf("Enter the data to push\n");
                    scanf("%d",&data);
                    enqueue(&q,data);
                    break;

            case 2: dequeue(&q);
                    break;

            case 3: peek(&q);
                    break;
            
            case 4: size(&q);
                    break;
            default:
                    printf("invalid code\n");
                    continue;
                    
        }
        n--;
    }
    
   

    Node *temp =q;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }


}