#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int id;
    int critical;
    struct node *next;
} Node;

Node *newnode(int id, int critical)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->id = id;
    temp->critical = critical;
    temp->next = NULL;
    return temp;
}

void insertAtEnd(Node **head, int id, int critical)
{
    if (*head == NULL)
    {
        *head = newnode(id, critical);
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode(id, critical);
    }
}

int check(int *arr, int *ind, int n, int id)
{
    for (int i = 0; i < (*ind); i++)
    {
        if (arr[i] == id)
        {
            return -1;
        }
    }

    arr[*ind] = id;
    (*ind)++;
    return 1;
}

void sort(Node **head, int id, int critical, int n)
{

    int cnt = 0;
    while (cnt < n)
    {
        Node *temp = *head;
        Node *prev = *head;

        while (temp->next != NULL)
        {
            Node *tempNext = temp->next;
            if (tempNext->critical < temp->critical)
            {
                if (temp == *head)
                {
                    temp->next = tempNext->next;
                    tempNext->next = temp;
                    *head = tempNext;
                    prev = tempNext;
                }
                else
                {
                    temp->next = tempNext->next;
                    tempNext->next = temp;
                    prev->next = tempNext;
                    prev = tempNext;
                }
                continue;
            }
            prev = temp;
            temp = temp->next;
        }

        cnt++;
    }
}
int main()
{
    Node *head = NULL;
    int n;
    int newn;
    int id;

    char str[100];
    int critical;
    scanf("%d", &n);
    newn = n;
    int arr[n];

    int ind = 0;
    while (n)
    {
        printf("Enter the patient id:");
        scanf("%d", &id);
        printf("\n");
        if (check(arr, &ind, newn, id) == -1)
        {
            printf("id already exist");
            continue;
        }
        printf("enter seriousness:");
        scanf("%s", str);
        printf("\n");
        if (strcmp(str, "high") == 0)
        {
            critical = 0;
        }
        else if (strcmp(str, "mid") == 0)
        {
            critical = 1;
        }
        else if (strcmp(str, "low") == 0)
        {
            critical = 2;
        }
        else
        {
            arr[--ind] = 0;
            printf("Invalid input , enter valid input\n");
            continue;
        }

        insertAtEnd(&head, id, critical);
        n--;
    }

    sort(&head, id, critical, newn);

    Node *curr = head;
    while (curr != NULL)
    {
        printf("patient id: %d     seriousness:%d\n", curr->id, curr->critical);
        curr = curr->next;
    }
}