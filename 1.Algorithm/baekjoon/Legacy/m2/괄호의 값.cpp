#include<iostream>
#include<string.h>

using namespace std;

char txt[41];
int arr[41];
int stack[41];
int top;

int main()
{
	freopen("input.txt", "r", stdin);
	int i;
	int sum = 0;
	scanf("%s", txt);
	for (i = 0; i < strlen(txt); i++)
	{
		if (txt[i] == '(') arr[i] = -1;
		if (txt[i] == ')') arr[i] = -3;
		if (txt[i] == '[') arr[i] = -2;
		if (txt[i] == ']') arr[i] = -4;
	}

	for (i = 0; i < strlen(txt); i++)
	{
		//괄호가 닫친것
		if (arr[i] == -3 || arr[i] == -4)
		{
			sum = 0;//누적해야 하기에 
			while (1)
			{
				if (top == 0)
				{
					printf("0");
					return 0;
				}
				if (stack[top] == -1 || stack[top] == -2 ) break;
				//합을 구하는 구간
				sum += stack[top]; //괄호 닫친 구간의 합을 구한다. 
				top--; //닫친 괄호를 만날때 까지 내려간다. 
			}

			//예외 처리 -쌍이 안맞으면
			if ((arr[i] == -3 && stack[top] == -2) || (arr[i] == -4 && stack[top] == -1))
			{
				printf("0");
				return 0;
			}
			//괄호가 바로 닫쳤을때 
			else if (sum == 0 && stack[top] == -1) stack[top] = 2;
			else if (sum == 0 && stack[top] == -2) stack[top] = 3;

			//sum에 있는 값하고 곱하기 전에 
			else if (stack[top] == -1) stack[top] = sum * 2;
			else if (stack[top] == -2)stack[top] = sum * 3;
		}
		//이외는 괄호 열린것
		else
		{
			//stack에 push
			top++;
			stack[top] = arr[i];
		}
	}

	//다 더하는 구간
	sum = 0;
	for (i = top; i >= 1; i--)
	{
		if (stack[i] < 0)
		{
			printf("0");
			return 0;
		}
		sum += stack[i];
	}

	printf("%d", sum);
	return 0;
}
////91 40
// 
// int stack[31];
// int match[2] = { 2, 3 };
// int top;

////top 값 반환
//int find_match(int find)
//{
//	int temp = 0;// 수치를 더할 값
//	while (top >= 0)
//	{
//		if (find == (int)'(' && (stack[top] == (int)']' || stack[top] == (int)'[')) return top = -1;
//		if (find == (int)'[' && (stack[top] == (int)')' || stack[top] == (int)'(')) return top = -1;
//		if (find == stack[top] && temp == 0)
//		{
//			//%10 /2 - ), ]의 식
//			stack[top] = match[(find % 10) % 2];
//			break;
//		}
//		else if (find == stack[top])
//		{
//			temp *= match[(find % 10) % 2];
//			stack[top] = temp;
//
//			break;
//		}
//
//		temp += stack[top];
//		top--;
//	}
//	return top;
//}
//
//int main()
//{
//	//스택을 만든다. - 
//	// (, [ 나오면 쌓고 
//	// top에서 부터 아래로 움직인다.  
//	//) ] 나오면 숫자로 변환하고 다음 반복을 한다.
//	//만약 top-1과 비교해서 숫자 변환이 안된다면 내가 짝을 찾을때까지 반복한다. 
//	//그동안 안에 있는 수는 다 더하고 
//	//만나면 숫자로 변환 및 기존에 있던 숫자와 곱해준다. 그리고 다시 stack에 넣는다. 
//
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//
//	char arr[31] = { '\0' };
//	char boul;
//	int other=0;
//	int cnt = 0;
//
//	int i;
//
//	scanf("%s", arr);
//
//	for (i = 0; i < strlen(arr); i++)
//	{
//		boul = arr[i];
//		if (top == -1)
//		{
//			cout << 0;
//			return 0;
//		}
//		if (boul == '(' || boul == '[')
//		{
//			top++;
//			stack[top] = (int)boul;
//		}
//		else if (boul == ')')
//		{
//			//찾을 괄호
//			other = (int)'(';
//			//반복
//			find_match(other);
//		}
//		else if (boul == ']')
//		{
//			//찾을 괄호
//			other = (int)'[';
//			//반복
//			find_match(other);
//		}
//	}
//	//다 더하기
//	while (top > 0)
//	{
//		if (stack[top] == (int)'[' || stack[top] == (int)'(' || stack[top] == (int)']' || stack[top] == (int)')')
//		{
//			cout << 0;
//			return 0;
//		}
//		cnt += stack[top];
//		top--;
//	}
//
//	cout<< cnt;
//
//	return 0;
//}