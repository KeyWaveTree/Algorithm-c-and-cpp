#include<iostream>

using namespace std;

int main()
{
	//4시 57분
//Perfect
//Deficient
//Abundant - 초과 

	int n;
	int m;
	int i, j;
	int sum = 0;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		sum = 0;
		for (j = 1; j < m; j++)
		{
			if (m % j == 0)
			{
				sum += j;
			}
		}
		if (sum == m) printf("Perfect\n");
		else if (sum < m) printf("Deficient\n");
		else if(sum > m)printf("Abundant\n");
	}

	return 0;
}