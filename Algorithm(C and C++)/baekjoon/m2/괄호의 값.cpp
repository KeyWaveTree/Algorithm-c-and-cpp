#include<iostream>
#include<string.h>

using namespace std;

char stack[31];
char match[2] = { 2, 3 };
int top;

//91 40
//top �� ��ȯ
int find_match(char find)
{
	char temp = '\0';// ��ġ�� ���� ��
	while (top >= 0)
	{
		if (find == '(' && (stack[top] == ']' || stack[top] == '[')) return top = -1;
		if (find == '[' && (stack[top] == ')' || stack[top] == '(')) return top = -1;
		if (find == stack[top] && temp == '\0')
		{
			//%10 /2 - ), ]�� ��
			stack[top] = match[(find % 10) % 2];
			break;
		}
		else if (find == stack[top])
		{
			temp *= match[(find % 10) % 2];
			stack[top] = temp;

			break;
		}

		temp += stack[top];
		top--;
	}
	return top;
}

int main()
{
	//������ �����. - 
	// (, [ ������ �װ� 
	// top���� ���� �Ʒ��� �����δ�.  
	//) ] ������ ���ڷ� ��ȯ�ϰ� ���� �ݺ��� �Ѵ�.
	//���� top-1�� ���ؼ� ���� ��ȯ�� �ȵȴٸ� ���� ¦�� ã�������� �ݺ��Ѵ�. 
	//�׵��� �ȿ� �ִ� ���� �� ���ϰ� 
	//������ ���ڷ� ��ȯ �� ������ �ִ� ���ڿ� �����ش�. �׸��� �ٽ� stack�� �ִ´�. 

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char arr[31] = { '\0' };
	char boul;
	char other;
	int cnt = 0;

	int i;

	scanf("%s", arr);

	for (i = 0; i < strlen(arr); i++)
	{
		boul = arr[i];
		if (top == -1)
		{
			cout << 0;
			return 0;
		}
		if (boul == '(' || boul == '[')
		{
			top++;
			stack[top] = boul;
		}
		else if (boul == ')')
		{
			//ã�� ��ȣ
			other = '(';
			//�ݺ�
			find_match(other);
		}
		else if (boul == ']')
		{
			//ã�� ��ȣ
			other = '[';
			//�ݺ�
			find_match(other);
		}
	}
	//�� ���ϱ�
	while (top > 0)
	{
		if (stack[top] == '[' || stack[top] == '(' || stack[top] == ']' || stack[top] == ')')
		{
			cout << 0;
			return 0;
		}
		cnt += stack[top];
		top--;
	}

	cout<< cnt;

	return 0;
}