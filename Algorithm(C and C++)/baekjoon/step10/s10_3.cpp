#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#define SWAP(a, b, t) ((t=a),(a=b), (b=t))

using namespace std;
int n, k;
int x[10000];

int main() 
{
	freopen("baek_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int temp;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}

	for (int i = 1; i <n; i++)
	{
		int flag = 0;
		for (int j = 1; j <= n-j; j++)
		{
			if (x[j] < x[j+1]) 
			{
				flag = 1;
				SWAP(x[i], x[j], temp);
			}
		}
		if (flag == 0)break;
	}

	printf("%d", x[k]);
}