#include<iostream>

using namespace std;

int stack[100001];
int top = 0;
int main()
{

	freopen("input.txt", "r", stdin);
	int i;
	int n;
	int value;
	unsigned int sum = 0;

	//stack을 이용
	//정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다. - 언더플로우 안일어남

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &value);
		if (value == 0)
		{
			stack[top] = 0;
			top--;
		}
		else
		{
			top++;
			stack[top] = value;
		}
	}

	//stack에 있는 값을 다 더함
	for (i = 1; i <= top; i++)
	{
		sum += stack[i];
	}


	printf("%d", sum);

	return 0;
}