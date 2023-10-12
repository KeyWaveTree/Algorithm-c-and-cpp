#include<iostream>
#include<string.h>

using namespace std;

char stack[31];
char match[2] = { 2, 3 };
int top;


void find_match(char find)
{
	char temp = ' ';// 수치를 더할 값
	while (top >= 0)
	{
		if (find == stack[top] && temp == '\0')
		{
			//%10 /2 - ), ]의 식
			stack[top] = match[find % 10 / 2];
			break;
		}
		else if (find == stack[top])
		{
			stack[top] = temp;
			break;
		}

		temp += stack[top];
		top--;
	}
}

int main()
{
	//스택을 만든다. - 
	// (, [ 나오면 쌓고 
	// top에서 부터 아래로 움직인다.  
	//) ] 나오면 숫자로 변환하고 다음 반복을 한다.
	//만약 top-1과 비교해서 숫자 변환이 안된다면 내가 짝을 찾을때까지 반복한다. 
	//그동안 안에 있는 수는 다 더하고 
	//만나면 숫자로 변환 및 기존에 있던 숫자와 곱해준다. 그리고 다시 stack에 넣는다. 

	char arr[31] = { '\0' };
	char boul;
	char other;
	
	int i;

	scanf("%s", arr);

	for (i = 0; i < strlen(arr); i++)
	{
		boul = arr[i];
		if (boul == '(' || boul == '[')
		{
			top++;
			stack[top] = boul;
		}
		else if (boul == ')')
		{
			//찾을 괄호
			other = '(';
			//반복
		}
	}

}