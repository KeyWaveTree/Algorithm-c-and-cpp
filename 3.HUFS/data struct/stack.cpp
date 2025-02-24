#include<stdio.h>
#define MAX 100

typedef int data;
struct Stack 
{
	data items[MAX];
	int top;
}*stack;

void initStack()
{
	stack->top = -1;
}

void overflow()
{
	printf("overflow");
	return;
}

void underflow()
{
	printf("underflow");
	return;
}

data isPeek()
{
	if (stack->top == -1)
	{
		underflow();
		return -1;
	}
	return stack->items[stack->top];
}

void push(data item)
{
	if (stack->top == MAX-1)
	{
		overflow();
		return;
	}

	stack->top++;
	stack->items[stack->top] = item;
}

data pop()
{
	data temp = stack->items[stack->top];
	
	if (stack->top == -1
		)
	{
		underflow();
		return -1;
	}

	stack->items[stack->top] = 0;
	stack->top--;

	return temp;
}