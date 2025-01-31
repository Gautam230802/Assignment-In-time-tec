/*Description: Implementing Queue using array
Time complexity: O(1) for all operations. 
space complexity: O(n)

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int* arr;
    int front;
    int rear;
    int size;
}Queue;

int isEmpty(Queue *q)
{
     return (q->front ==q->rear-1);
}

int isFull(Queue *q)
{
    return (q->rear ==q->size);
}

void enqueue(Queue *q,int data)
{
    if(isFull(q))
    {
        printf("Queue is overflow\n");
    }
    else{
        q->arr[q->rear]=data;
        q->rear++;
    }
}

void dequeue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else{
       q->front++;
    }
}
void peek(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else{
        printf("front element is:%d\n",q->arr[q->front+1]);
    }
}
void size(Queue *q)
{
    int size =0;
    int cnt=q->front;
    while(cnt!=q->rear-1)
    {
        cnt++;
        size++;
    }
    printf("size is:%d\n",size);
    
}
int main()
{
    Queue q;
    q.front =-1;
    q.rear =0;
    q.size =10;
    q.arr=(int*)malloc(q.size*sizeof(int));

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
    

    int cnt=q.front;
    printf("Queue elements are:");
    while(cnt!=q.rear-1)
    {
        cnt++;
        printf("%d ",q.arr[cnt]);

    }
    
}