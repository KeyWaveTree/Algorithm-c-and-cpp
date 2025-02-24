#include<stdio.h>

int main()
{
	int coin;
	int copy;
	int prize = 0;
	scanf("%d", &coin);

	if (coin > 8000)
	{
		copy = coin;
		copy -= 8000; // 500
		coin -= copy;//8000
		prize += copy * 35 / 100;
	}

	if (coin <= 8000 && coin > 4000)
	{
		copy = coin;//8000
		copy -= 4000; //4000
		coin -= copy; //4000
		prize += copy * 26/ 100;
	}

	if (coin <= 4000 && coin > 1000)
	{
		copy = coin; //4000
		copy -= 1000; //3000
		coin -=copy;
		prize += copy * 17/ 100;
	}

	if (coin <= 1000)
	{
		prize += coin * 8 / 100;
	}
	printf("%d", prize);
}