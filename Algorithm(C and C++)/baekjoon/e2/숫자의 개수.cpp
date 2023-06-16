#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[10] = { '\0' };
	int num[10] = { 0 };
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	sprintf(str, "%d", a * b * c);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < strlen(str); j++)
		{
			if (i == (int)str[j] - '0') num[i]++;
		}
		printf("%d\n", num[i]);
	}
	
	return 0;
}