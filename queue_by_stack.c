/* description: Implementing queue using two stacks. 
    1. Enqueue operation: 
        a. Push the element to stack1.
    2. Dequeue operation:
        a. Pop all the elements from stack1 and push them to stack2.
        b. Pop the top element from stack2.
    3. Peek operation:
        a. Peek the top element of stack1.
    4. Size operation:
        a. Return the size of stack1.

    time complexity: O(n) for dequeue operation in worst case. O(1) for all other operations.
    space complexity: O(n)
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
}Stack;

int isEmpty(Stack *stk)
 {
    if(stk->top==-1)
    {
        printf("empty\n");
    }
    else{
        printf("Not Empty\n");
    }
    return stk->top ==-1;
 }

int isFull(Stack *stk )
 {
    return stk->top ==stk->size-1;
 }

void push(Stack *stk,int data)
 {
    if(isFull(stk))
    {
        printf("Stack is Full \n");
    }
    else{
        (stk->top)++;
        stk->arr[stk->top]=data;
    }
 }

void pop(Stack *stk)
 {
    if(isEmpty(stk))
    {
        printf("Stack is Empty \n");
    }
    else{
        (stk->top)--;
    }
 }

void peek(Stack*stk)
{
    if(isEmpty(stk))
    {
        printf("stack is empty\n");
    }
    else{
      int ele =stk->arr[stk->top];
      printf("Front element is %d \n",ele);
    }
}

int size(Stack*stk)
{
    
    return stk->top+1;
}

typedef struct queue{
    Stack s1,s2;
}Queue;

void initiate(Queue*q,int size)
{
    q->s1.size=10;
    q->s1.top=-1;
    q->s1.arr=(int*)malloc(q->s1.size*sizeof(int));

    q->s2.size=10;
    q->s2.top=-1;
    q->s2.arr=(int*)malloc(q->s2.size*sizeof(int));
}

void enqueue(Queue*q,int value)
{
    if(isFull(&q->s1))
    {
        printf("Queue overflow\n");
    }
    else{
        
        while(!isEmpty(&q->s1))
        {
            push(&q->s2,q->s1.arr[q->s1.top]);
            pop(&q->s1);
        }
        push(&q->s1,value);
        while(!isEmpty(&q->s2))
        {
            push(&q->s1,q->s2.arr[q->s2.top]);
            pop(&q->s2);
        }

    }
}

void dequeue(Queue*q)
{
    if(isEmpty(&q->s1))
    {
        printf("Queue is Empty\n");
    }
    else{
        pop(&q->s1);
    }
}

void peekQueue(Queue*q)
{
    peek(&q->s1);
}

int sizeQueue(Queue* q)
{
    return size(&q->s1);
}

int main()
{
    Queue q;
    initiate(&q,10);
    
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

            case 3: peekQueue(&q);
                    break;
            case 4: sizeQueue(&q);
                    break;
            default:
                    printf("invalid code\n");
                    continue;
                    
        }
        n--;
    }
    
    int cnt =q.s1.top;
    while (cnt!=-1)
    {
        printf("%d ",q.s1.arr[cnt]);
        cnt--;
    }


}