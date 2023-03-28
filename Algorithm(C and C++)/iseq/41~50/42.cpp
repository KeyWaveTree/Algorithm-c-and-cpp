#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int dice_arr[6] = { 0 };
	int n;

	cin >> n;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		int dice = rand() % 6;
		dice_arr[dice]++;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%d %d %.3f\n", i + 1, dice_arr[i], 100 * float(dice_arr[i]) /(float) n);
	}
}