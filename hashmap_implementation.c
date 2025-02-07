#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node {
    int id;
    char name[50];
    struct node* next;
} Node;

Node* hashTable[100];

void initialiseHashTable() {
    for(int i = 0; i < 100; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int id) {
    return ((id + id) * id) % 100;
}

bool insertInTable(Node* p) {
    if(p == NULL) return false;
    int index = hashFunction(p->id);
    if(hashTable[index] != NULL) {
        Node* temp = hashTable[index];
        while(temp->next != NULL) {
            if(temp->id == p->id) {
                strcpy(temp->name, p->name);
                return true;
            }
            temp = temp->next;
        }
        temp->next = p;
    } else {
        hashTable[index] = p;
    }
    return true;
}

Node* search(int id) {
    int index = hashFunction(id);
    Node* temp = hashTable[index];
    while(temp) {
        if(temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

Node* deleteKey(int id) {
    int index = hashFunction(id);
    Node* temp = hashTable[index];
    Node* prev = NULL;
    while(temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Key not found\n");
        return NULL;
    }
    if(prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }
    return temp;
}

void displayTable() {
    printf("Hash Table Contents:\n");
    for(int i = 0; i < 100; i++) {
        if(hashTable[i] != NULL) {
            Node* temp = hashTable[i];
            printf("Index %d: ", i);
            while(temp) {
                printf("(ID: %d, Name: %s) -> ", temp->id, temp->name);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    initialiseHashTable();
    int n, op, id;
    char name[50];
    printf("Enter number of operations: ");
    scanf("%d", &n);
    while(n--) {
        printf("Enter operation (1: Insert, 2: Search, 3: Delete, 4: Display, 5: Exit): ");
        scanf("%d", &op);
        switch(op) {
            case 1: {
                Node* newNode = (Node*)malloc(sizeof(Node));
                printf("Enter ID and Name: ");
                scanf("%d %s", &newNode->id, newNode->name);
                newNode->next = NULL;
                if(insertInTable(newNode)) {
                    printf("Insertion Successful\n");
                } else {
                    printf("Insertion Failed\n");
                }
                break;
            }
            case 2: {
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                Node* result = search(id);
                if(result) {
                    printf("Found: ID=%d, Name=%s\n", result->id, result->name);
                } else {
                    printf("Not Found\n");
                }
                break;
            }
            case 3: {
                printf("Enter ID to Delete: ");
                scanf("%d", &id);
                Node* deletedNode = deleteKey(id);
                if(deletedNode) {
                    printf("Deleted: ID=%d, Name=%s\n", deletedNode->id, deletedNode->name);
                    free(deletedNode);
                }
                break;
            }
            case 4: {
                displayTable();
                break;
            }
            case 5: {
                printf("Exiting.\n");
                return 0;
            }
            default:
                printf("Invalid Operation\n");
        }
    }
    return 0;
}
