#include<stdio.h>
int main()
{
	char ch=NULL;
	int cnt = 0;
	while (1)
	{
		scanf("%c", &ch);

		if (ch == 'a') cnt++;
		else if (ch == '.') break;
	}
	printf("%d", cnt);
	return 0;
}