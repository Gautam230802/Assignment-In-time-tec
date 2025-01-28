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
void insertAtEnd(Node** head, int value)
{
    if(*head==NULL)
    {
        *head =newnode(value);
    }
    else{
    Node* temp =*head;
    while(temp->next!=NULL)
    {
        temp =temp ->next;
    }
    temp->next=newnode(value);
    }
}
Node* sort(Node* curr)
{
    Node* temp =curr;
    while(temp!=NULL)
    {
        Node* mini =temp;
        Node* tempNext =temp->next;
        while(tempNext!=NULL)
        {
            if(mini->data > tempNext->data)
            {
                mini=tempNext;
            }
            tempNext=tempNext->next;
        }
        int tempi =mini->data;
        mini->data =temp->data;
        temp->data=tempi;

        temp =temp->next;
    }

    return curr;
}

Node* printfAns(Node* oddHead,Node* evenHead)
{
    Node* oddPart =oddHead;
    if(oddHead==NULL)
    {
        return evenHead;
    }
    while(oddPart->next!=NULL)
    {
        oddPart=oddPart->next;
    }
    oddPart->next=evenHead;
    return oddHead;
    

}

Node* separateEvenOdd(Node* head)
{
    Node*dummyEven =newnode(-1);
    Node*even =dummyEven;
    Node*dummyOdd=newnode(-1);
    Node* odd =dummyOdd;

    Node*temp =head;
    while(temp!=NULL)
    {
        if((temp->data)%2==0)
        {
            even->next=temp;
            even =even->next;
        }
        else{
            odd->next =temp;
            odd =odd->next;
        }
        temp =temp->next;
    }
    even->next =NULL;
    odd->next =NULL;

    Node*tempOdd =dummyOdd->next;
    tempOdd=sort(dummyOdd->next);

    Node*tempEven =dummyEven->next;
    tempEven=sort(dummyEven->next);
    
    return printfAns(tempOdd,tempEven);

}

int main()
{
    Node* head =NULL;

    int n,value;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);

    while(n)
    {
        printf("Enter Node Value: ");
        scanf("%d",&value);
        insertAtEnd(&head,value);
        n--;
    }
    Node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

    head =separateEvenOdd(head);

    Node*temp1=head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
}