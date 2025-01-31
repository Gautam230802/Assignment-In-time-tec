/*
Descri[ption: Implementing stack using linked list
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

void insertAtBegin(Node** head,int data)
{
    if(*head==NULL)
    {
        *head =newnode(data);
    }
    else
    {
        Node* curr=newnode(data);
        curr->next =*head;
        *head = curr;
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
int isempty(Node** stk)
{
    return (*stk ==NULL);
}

void push(Node** stk,int data)
{
   insertAtBegin(stk,data);
}

void pop(Node** stk)
{
    if(isempty(stk))
    {
        printf("Stack underflow\n");
    }
    else{
    deleteAtBegin(stk);
    }
}

void size(Node **stk)
{
    int size=0;
    Node *curr=*stk;
    while(curr!=NULL)
    {
        curr=curr->next;
        size++;
    }
    printf("Size is :%d\n",size);
}

void peek(Node** stk)
{
    if(*stk==NULL)
    {
        printf("Stack empty\n");
    }
    else{
    printf("stack top is: %d\n",(*stk)->data);
    }
}

int main()
{
    Node *stk =NULL;
    int n;
    printf("No. of operations :");
    scanf("%d",&n);

    int op;
    while(n)
    {
        printf("Enter the eoperation: ");
        scanf("%d",&op);
        int data;
        switch(op)
        {
            case 1: printf("Enter the data to push\n");
                    scanf("%d",&data);
                    push(&stk,data);
                    break;

            case 2: pop(&stk);
                    break;

            case 3: peek(&stk);
                    break;
            
            case 4: size(&stk);
                    break;
            default:
                    printf("invalid code\n");
                    continue;
                    
        }
        n--;
    }
    
    printf("elements in stack are:");
    Node* temp =stk;
    while(temp !=NULL)
    {
        printf("%d ",temp->data);
        temp =temp->next;
    }
}
