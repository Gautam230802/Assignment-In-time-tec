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

void insertAtEnd(Node**last,int value,int n)
{
    if(*last==NULL)
    {
        *last=newnode(value);
        (*last)->next =(*last);
    }
    else{
        Node* temp=newnode(value);
        temp->next =(*last)->next;
        (*last)->next =temp;
        (*last)=temp;
    }
}
void rotate(Node** last,int value,int n)
{
    
    value=value%n;
    int cnt =0;
    Node* temp =*last;
    while(cnt!=value)
    {
        temp =temp->next;
        cnt++;
    }
    *last =temp;
}
int main()
{
    Node* last=NULL;
    int n;
    int value;
    int newn=n;
    scanf("%d",&n);
    while(n)
    {
        printf("Enter node data: ");
        scanf("%d",&value);
        insertAtEnd(&last,value,n);
        n--;
    }
    
    Node* curr =last->next;
    while(1)
    {
        
        printf("%d ",curr->data);
        curr=curr->next;
        if(curr==(last->next))
        {
            break;
        }
    }
    int k;
    printf("Enter no. of shift: ");
    scanf("%d",&k);
    k=k%newn;
    rotate(&last,k,newn);
    Node* curr1 =last->next;
    printf("\n");
    printf("After rotate\n");
    while(1)
    {
        
        printf("%d ",curr1->data);
        curr1=curr1->next;
        if(curr1==(last->next))
        {
            break;
        }
    }


    
}