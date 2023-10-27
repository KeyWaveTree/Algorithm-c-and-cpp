#include<iostream>
#include<cmath>

using namespace std;

int main()
{

	freopen("input.txt", "r", stdin);

	int arr[7] = { 0 };
	int n;
	int i;
	int num;
	int cnt = 1; //판의 개수
	int p = 36; //판의 최대 넓이
	scanf("%d", &n);
	for (i = 1; i <= n-(n%6); i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 1; i <= n; i++)
	{
		num = (i * i) * arr[i];
		int i2 = (int)sqrt(p);
		int num2 = (int)sqrt(num);
		if (p - num > 0 && i2 >num2) p -= num;
		else if (p - num == 0)
		{
			cnt++;
			p = 36;
		}
		else 
		{
			if (p < num)
			{
				cnt += num / p;
				p = 36 - (num % p);
			}
			else if (p > num)
			{
				cnt += p / num;
				p = 36 - (p % num);
			}
		}
	}

	printf("%d", cnt);
}