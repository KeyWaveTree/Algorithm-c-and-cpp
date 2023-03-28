#include<stdio.h>
#include<cstring>
#include<iostream>

using namespace std; 

char stick[100000];
int main()
{
	freopen("input.txt", "r", stdin);

	int sum = 0;
	int cnt = 0;

	scanf("%s", stick);
	
	for (int i = 0; i < strlen(stick); i++)
	{
		if (stick[i] == '(')
		{
			sum++;
		}
		else {
			if (stick[i-1] == '(')
			{
				sum--;
				cnt += sum;
			}
			else //³¡ÀÚ¸® °ýÈ£ 
			{
				sum--;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}