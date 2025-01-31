
/*
Description: Implement stack using two queues.
time complexity: O(n) for push operation in worst case. O(1) for all other operations.
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
        printf("Stack is overflow\n");
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
        printf("Stack underflow\n");
    }
    else{
       q->front++;
    }
}
void peek(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Stack is empty\n");
    }
    else{
        printf("top element is:%d\n",q->arr[q->front+1]);
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

typedef struct stack{
    Queue q1,q2;
}Stack;

void initiateStack(Stack*stk,int size)
{
    stk->q1.size=size;
    stk->q1.arr=(int*)malloc(stk->q1.size*sizeof(int));
    stk->q1.front=-1;
    stk->q1.rear=0;

    stk->q2.size=size;
    stk->q2.arr=(int*)malloc(stk->q2.size*sizeof(int));
    stk->q2.front=-1;
    stk->q2.rear=0;
}

void push(Stack* stk,int data)
{
    if(isFull(&stk->q1))
    {
        printf("Stack overflow\n");
    }
    else{
        enqueue(&stk->q2,data);
        while(!isEmpty(&stk->q1))
        {
            enqueue(&stk->q2,stk->q1.arr[stk->q1.front+1]);
            dequeue(&stk->q1);
        }
        Queue temp =stk->q1;
        stk->q1= stk->q2;
        stk->q2=temp;

        stk->q2.front = -1;
        stk->q2.rear = 0;

    }
}

void pop(Stack* stk)
{
    if(isEmpty(&stk->q1))
    {
        printf("stack underflow");
    }
    else{
        dequeue(&stk->q1);
    }
}

void stackPeek(Stack* stk)
{
    peek(&stk->q1);
}
void stackSize(Stack* stk)
{
    size(&stk->q1);
}
int main()
{
    Stack stk;
    initiateStack(&stk,10);
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

            case 3: stackPeek(&stk);
                    break;
            case 4: stackSize(&stk);
                    break;
            default:
                    printf("invalid code\n");
                    continue;
                    
        }
        n--;
    }
    int cnt =stk.q1.front+1;
    while(cnt!=stk.q1.rear)
    {
        printf("%d ",stk.q1.arr[cnt]);
        cnt++;
    }
    
    

}