#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int arr[3] = { 0 };
	

	while (1) 
	{
			int cnt = 0;
			int sum = 0;
			for (int i = 0; i < 3; i++)
			{
				cin >> arr[i];
				switch (arr[i])
				{
				 case 1:
					sum += 5000;
					continue;
				 case 2:
					sum += 6000;
					continue;
				 case 3:
					sum += 7000;
					continue;
				 case 4:
					sum += 10000;
					continue;
				 case 5:
					sum += 20000;
					continue;
				 case 0:
					cnt++;
					if (cnt == 3) return 0;
					else continue;

				}
			}
			cout << sum << endl;
	}
}