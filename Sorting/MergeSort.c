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
Node* merge(Node* first,Node* second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;
    Node* dummy =newnode(-1);
    Node*temp =dummy;
    while(first!=NULL && second!=NULL)
    {
        if(first->data <=second->data)
        {
            temp->next =first;
            first =first->next;
            temp =temp->next;
        }
        else{
            temp->next =second;
            second=second->next;
            temp =temp->next;
        }
        
    }
    if(first) {temp->next =first;
       }

        if(second)
        {temp->next =second;
        }
    return dummy->next;
}
Node* middle(Node* head)
{
    if(head ==NULL || head->next==NULL) return head;
    Node* slow = head;
    Node*fast =head;
    while(fast->next!=NULL && fast->next ->next !=NULL)
    {
        fast =fast->next->next;
        slow =slow->next;
    }
    return slow;
}

Node* mergeSort(Node *head)
{
    if(head ==NULL || head->next ==NULL) return head;

    Node* mid =middle(head);
    
    Node* secondHead =mid->next;
    mid->next =NULL;
    Node* firstHead =head;
    firstHead=mergeSort(firstHead);
    secondHead=mergeSort(secondHead);
    return merge(firstHead,secondHead);

    
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

    head =mergeSort(head);
   Node*temp1 =head;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->data);
        temp1 =temp1->next;
    }

}