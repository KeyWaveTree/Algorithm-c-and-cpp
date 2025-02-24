#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define SIZE 50

char A[SIZE]; //�Է½�
char S[SIZE];//����
int top;

int code(char op)
{
	if (op == '*' || op == '/') return 2;
	else if (op == '+' || op == '-') return 1;
	else return 0;
}

int main()
{

	scanf("%s", A);
	for (int i = 0; i < strlen(A); i++)
	{
		if (A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
		{
			if (code(A[i]) > code(S[top]))
			{
				//push ����
				top++;
				S[top] = A[i];
			}
			else
			{
				//���� ��Ģ ����
				while (1)
				{
					//pop����
					printf("%c", S[top]);
					top--;
					if (code(A[i]) > code(S[top]))
					{
						top++;
						S[top] = A[i];
						break;
					}
				}
			}
		}
		else
		{
			printf("%c", A[i]);
		}
	}

	for (int i = top; i >= 0; i--)
	{
		if (S[i] != '\0')
		{
			printf("%c", S[i]);
		}
		
	}

	return 0;
}