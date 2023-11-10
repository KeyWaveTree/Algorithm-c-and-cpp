#include<iostream>
#include<cstring>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	int check = 0;
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		char arr[51] = { '\0' };
		check = 0;
		scanf("%s", arr);
		for (j = 0; j < strlen(arr); j++)
		{
			if (arr[j] == '(') check++;
			else
			{
				check--;
				if (check < 0) break;
			}
		}
		
		if (check == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}