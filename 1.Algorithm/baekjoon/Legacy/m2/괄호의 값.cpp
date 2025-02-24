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
		//��ȣ�� ��ģ��
		if (arr[i] == -3 || arr[i] == -4)
		{
			sum = 0;//�����ؾ� �ϱ⿡ 
			while (1)
			{
				if (top == 0)
				{
					printf("0");
					return 0;
				}
				if (stack[top] == -1 || stack[top] == -2 ) break;
				//���� ���ϴ� ����
				sum += stack[top]; //��ȣ ��ģ ������ ���� ���Ѵ�. 
				top--; //��ģ ��ȣ�� ������ ���� ��������. 
			}

			//���� ó�� -���� �ȸ�����
			if ((arr[i] == -3 && stack[top] == -2) || (arr[i] == -4 && stack[top] == -1))
			{
				printf("0");
				return 0;
			}
			//��ȣ�� �ٷ� �������� 
			else if (sum == 0 && stack[top] == -1) stack[top] = 2;
			else if (sum == 0 && stack[top] == -2) stack[top] = 3;

			//sum�� �ִ� ���ϰ� ���ϱ� ���� 
			else if (stack[top] == -1) stack[top] = sum * 2;
			else if (stack[top] == -2)stack[top] = sum * 3;
		}
		//�ܴ̿� ��ȣ ������
		else
		{
			//stack�� push
			top++;
			stack[top] = arr[i];
		}
	}

	//�� ���ϴ� ����
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

////top �� ��ȯ
//int find_match(int find)
//{
//	int temp = 0;// ��ġ�� ���� ��
//	while (top >= 0)
//	{
//		if (find == (int)'(' && (stack[top] == (int)']' || stack[top] == (int)'[')) return top = -1;
//		if (find == (int)'[' && (stack[top] == (int)')' || stack[top] == (int)'(')) return top = -1;
//		if (find == stack[top] && temp == 0)
//		{
//			//%10 /2 - ), ]�� ��
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
//	//������ �����. - 
//	// (, [ ������ �װ� 
//	// top���� ���� �Ʒ��� �����δ�.  
//	//) ] ������ ���ڷ� ��ȯ�ϰ� ���� �ݺ��� �Ѵ�.
//	//���� top-1�� ���ؼ� ���� ��ȯ�� �ȵȴٸ� ���� ¦�� ã�������� �ݺ��Ѵ�. 
//	//�׵��� �ȿ� �ִ� ���� �� ���ϰ� 
//	//������ ���ڷ� ��ȯ �� ������ �ִ� ���ڿ� �����ش�. �׸��� �ٽ� stack�� �ִ´�. 
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
//			//ã�� ��ȣ
//			other = (int)'(';
//			//�ݺ�
//			find_match(other);
//		}
//		else if (boul == ']')
//		{
//			//ã�� ��ȣ
//			other = (int)'[';
//			//�ݺ�
//			find_match(other);
//		}
//	}
//	//�� ���ϱ�
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