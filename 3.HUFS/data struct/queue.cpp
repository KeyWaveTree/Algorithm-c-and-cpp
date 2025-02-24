#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef int data;

struct Queue
{
	data items[N];
	int front;
	int rear;
} *queue;

void initQueue()
{
	queue->front = queue->rear=0;
}
bool isFull()
{
	return queue->front == (queue->rear + 1) % N;
}

bool isEmpty()
{
	return queue->front == queue->rear;
}

void Enqueue(data *item)
{
	queue->rear++;
	if (isFull()) 
	{
		printf("overflow\n");
		return;
	}
	queue->items[queue->rear] = *item;
}

data Dequeue()
{
	data item = queue->items[queue->front+1];
	if (isEmpty())
	{
		printf("underflow\n");
		return -1;
	}
	queue->front++;
	queue->items[queue->front]=0;
	return item;
}

int main()
{

}