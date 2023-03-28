#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void holl(int n)
{
	int sum=0;
	for (int i = 1; i <n; i+=2)
	{
		sum += i;
	}
	cout << "È¦¼ö = " << sum;
}

void cheak(int n)
{
	int sum = 0;
	for (int j = 2; j < n; j+=2)
	{
		sum += j;
	}
	cout << "Â¦¼ö = " << sum;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		  cheak(n);
	}
	else 
	{
		holl(n);
	}

}
