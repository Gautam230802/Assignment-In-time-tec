#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *newnode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void deleteAtBegin(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Invalid\n");
    }
    else
    {
        struct Node *temp = *head;
        *head = temp->next;
        temp->next = NULL;
    }
}

void deleteAtEnd(struct Node **head)
{
    if((*head)->next==NULL)
    {
        *head =NULL;
    }
    else if(*head==NULL)
    {
        printf("Invalid\n");
    }
    else{
    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    }
}

void deleteAtpostion(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("Invalid");
    }
    else if(position==1)
    {
        deleteAtBegin(head);
    }
    else if((*head)->next==NULL)
    {
        deleteAtEnd(head);
    }
    else{
    struct Node *prev = *head;

    int count = 1;
    while (prev && count < position - 1)
    {
        prev = prev->next;
        count++;
    }
    if (prev != NULL && prev->next != NULL)
    {
        struct Node *temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }
    }
}

void insertAtEnd(struct Node **head, int data)
{

    if (*head == NULL)
    {
        *head = newnode(data);
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode(data);
    }
}
int insertAtBegin(struct Node **head, int data)
{
    if (*head == NULL)
    {
        *head = newnode(data);
    }
    else
    {
        struct Node *temp = newnode(data);
        temp->next = *head;
        *head = temp;
    }
}

void insertAtposition(struct Node **head, int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid");
        return;
    }

    if (position == 1)
    {
        insertAtBegin(head, data);
    }
    struct Node *prev = *head;
    int cnt = 1;
    while (prev && position - 1 > cnt)
    {
        prev = prev->next;
        cnt++;
    }
    if (prev != NULL)
    {
        struct Node *temp = newnode(data);
        temp->next = prev->next;
        prev->next = temp;
    }
}
void dispaly(struct Node *head)
{
    if (head == NULL)
    {
        printf("Empty Linked List\n");
    }
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void updated(struct Node **head, int pos, int value)
{
    if (head == NULL)
    {
        printf("Invalid\n");
    }
    struct Node *temp = *head;
    int count = 1;
    while (temp && pos - 1 > count)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
    {
        temp->next->data = value;
    }
}
int main()
{
    printf("Enter the operation to performed");
    printf("1. Add element to the end\n");
    printf("2. Add element to the beginning\n");
    printf("3. Add element to the position\n");
    printf("4. Display Linkedlist\n");
    printf("5. update element at pos\n");
    printf("6. Delete first element\n");
    printf("7. Deletre last element\n");
    printf("8. Delete element at pos\n");
    struct Node *head = NULL;

    printf("enter the no. of operation:\n");
    int no_operation, ele, position;
    ;
    scanf("%d", &no_operation);

    while (no_operation)
    {
        printf("Enter the operation:\n");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter element :");
            scanf("%d", &ele);
            getchar();
            printf("element %d:\n", ele);
            insertAtEnd(&head, ele);
            break;

        case 2:
            printf("Enter element");
            scanf("%d", &ele);
            getchar();
            printf("element %d\n", ele);
            insertAtBegin(&head, ele);
            break;

        case 3:
            printf("Enter element and position");

            scanf("%d %d", &ele, &position);
            getchar();
            printf("element %d %d", ele, position);
            insertAtposition(&head, ele, position);
            break;

        case 4:
            printf("Linked List ");
            dispaly(head);
            break;

        case 5:
            printf("enter position and element to be updated");
            int pos, upd;
            scanf("%d %d", &pos, &upd);
            getchar();
            printf("Element and position are %d %d\n", pos, upd);
            updated(&head, pos, upd);
            break;

        case 6:
            deleteAtBegin(&head);
            break;

        case 7:
            deleteAtEnd(&head);
            break;

        case 8:
            printf("enter the position");
            scanf("%d", &position);
            getchar();
            printf("position is %d\n", position);
            deleteAtpostion(&head, position);
            break;
        default:
            printf("Invalid Operation\n");
        }
        no_operation--;
    }
}