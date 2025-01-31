/*
Description: 
Implementing Stack using array
Time complexity: O(1) for all operations.
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
      printf("Top element is %d \n",ele);
    }
}

int main()
{
    Stack stk;
    stk.size=5;
    stk.top=-1;
    stk.arr =(int*)malloc(stk.size*sizeof(int));
    
    push(&stk,6);
    push(&stk,2);
    push(&stk,8);
    push(&stk,3);
    push(&stk,13);
    push(&stk,23);
    pop(&stk);
    peek(&stk);

    while(stk.top!=-1)
    {
        printf("%d ",stk.arr[stk.top]);
        (stk.top)--;
    }


}