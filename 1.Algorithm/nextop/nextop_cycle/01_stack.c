#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 10 //사이즈지정은 원하는데로 변경 가능합니다. 


int S[SIZE + 1]; //0번지 칸을 비워두면 안정성이 높아진다. 
int top;

void overflow()
{
	printf("초과(값 지정) 에러");
	return; //void return은 없어도 무관합니다.
}

void underflow()
{
	printf("바닥(값 지정) 에러");
	return;//void return은 없어도 무관합니다.
}

void push(int item)
{
	if (top == SIZE)
	{
		overflow();
		return; //push 함수 종료
	}

	top++;
	S[top] = item;
}

int pop()
{
	int temp = S[top];
	if (top == 0)
	{
		underflow();
		return -1; //pop함수 종료
	}

	S[top] = 0;
	top--;

	return temp; //없애는 값을 보여주기 위한 return 
}

int main()
{
	push(10);
	push(20);
	printf("%d\n", pop());//20이 나오는지 확인
	printf("%d\n", pop());//10이 나오는지 확인
	printf("%d\n", pop()); //언더플로우가 나오는것을 확인

	return 0;
}