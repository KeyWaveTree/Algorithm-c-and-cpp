#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char name[10][10] = { '\0' };
	int score[10] = { 0 };
	int a[10] = { 0 };
	int size;

	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> name[i] >> score[i];
		a[i] = 1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (score[i] < score[j])a[i]++;

		}
	}
	
	for(int i=0;i<size;i++)
	{
		cout << name[i] << " " << a[i]<<endl;
	}

	return 0;
}