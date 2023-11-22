#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	while (true)
	{
		char arr[110] = { '\0' };
		char stack[110] = { '\0' };
		int top = 0;
		fgets(arr, sizeof(arr), stdin);
		//종료 조건
		if (arr[0] == '.') break;
		for (int i = 0; i < strlen(arr); i++)
		{
			top++;
			stack[top] = arr[i];
			if (stack[top] != ')' && stack[top] != ']' && stack[top] != '(' && stack[top] != '[')
			{
				stack[top] = '\0';
				top--;
			}
			else if ((arr[i] == ')' && stack[top-1] == '(') || (arr[i] == ']' && stack[top-1] == '['))
			{
				stack[top] = '\0';
				stack[top - 1] = '\0';
				top-=2;
			}
			
		}

		if (top == 0) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}