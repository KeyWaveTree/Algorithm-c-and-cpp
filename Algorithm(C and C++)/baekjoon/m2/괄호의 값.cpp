#include<iostream>
#include<string.h>

using namespace std;

char stack[31];
char match[2] = { 2, 3 };
int top;


void find_match(char find)
{
	char temp = ' ';// ��ġ�� ���� ��
	while (top >= 0)
	{
		if (find == stack[top] && temp == '\0')
		{
			//%10 /2 - ), ]�� ��
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
	//������ �����. - 
	// (, [ ������ �װ� 
	// top���� ���� �Ʒ��� �����δ�.  
	//) ] ������ ���ڷ� ��ȯ�ϰ� ���� �ݺ��� �Ѵ�.
	//���� top-1�� ���ؼ� ���� ��ȯ�� �ȵȴٸ� ���� ¦�� ã�������� �ݺ��Ѵ�. 
	//�׵��� �ȿ� �ִ� ���� �� ���ϰ� 
	//������ ���ڷ� ��ȯ �� ������ �ִ� ���ڿ� �����ش�. �׸��� �ٽ� stack�� �ִ´�. 

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
			//ã�� ��ȣ
			other = '(';
			//�ݺ�
		}
	}

}