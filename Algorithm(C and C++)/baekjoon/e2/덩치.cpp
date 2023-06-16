#include<iostream>
#include<vector>
using namespace std;

typedef struct body
{
	int weght;
	int height;
};

body people[50];

int main()
{
	int lank[50] = { 0 };
	int i,j;
	int n;
	int cnt;
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> people[i].weght;
		cin >> people[i].height;
		lank[i] = 1;
	}

	for (i = 0; i < n; i++)
	{
		
		for (j = 0; j < n; j++)
		{
			if (people[i].height < people[j].height && people[i].weght<people[j].weght) lank[i] += 1;
		}
		printf("%d ", lank[i]);
	}

	return 0;
}