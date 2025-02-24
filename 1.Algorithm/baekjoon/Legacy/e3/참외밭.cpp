#include<iostream>

using namespace std;

int check[6];
int temp; 

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//n은 땅의 크기 1m^2에서 나는 참외의 개수 
	//집합 a, b에서 가장 큰 숫자를 골라 곱한다. 
	int n;
	int i;
	int arrow, len;
	int min_box;
	int max_x=0;
	int max_y=0;
	int x, y;
	bool flag = true;

	scanf("%d", &n);
	for (i = 0; i < 6; i++)
	{
		scanf("%d%d", &arrow, &len);
		check[i] = len;
		if (arrow >= 1 && arrow <= 2 && max_x < len)
		{
			max_x = len;
			x = i;
		}
		if (arrow >= 3 && arrow <= 4 && max_y < len)
		{
			max_y = len;
			y = i;
		}
	}
	temp = max_x * max_y;
	if ((x + 1) % 6 == y)
	{
		min_box=check[(y + 2) % 6] * check[(y + 3) % 6];
	}
	else
	{
		min_box = check[(x + 2) % 6] * check[(x + 3) % 6];
	}

	printf("%d", n * (temp - min_box));
	return 0;
	/*	if (check[arrow] == 0 && flag)
		{
			check[arrow] = 1;
			temp = len;
		}
		else if(flag)
		{
			flag = false;
			min_box = temp * len;
		}
	}
	
	printf("%d", n * (max_x * max_y - min_box));*/
}