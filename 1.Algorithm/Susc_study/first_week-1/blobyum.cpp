#include<iostream>

using namespace std;

const int SIZE = 200000;

int arr[SIZE];
int main()
{
	int n, k;
	int i;
	int sum = 0;
	int max = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		//순환을 해야 하기에 - 범위가 틀렸었음.
		arr[n+i] = arr[i];
		if (i + 1 <= k)
		{
			sum += arr[i];
		}
	}
	max = sum;
	
	//접근 자체도 맞았지만 2*n으로 해야 함. n으로 하면 못할 수 있음 범위 때문에  
	for (i = k; i <=2*n; i++)
	{
		//누적합
		//뒤에 있는 애 부터 빼야 함.
		sum -= arr[i - k];
		sum += arr[i];
		if (sum > max) max = sum;
	}

	printf("%d", max);
	return 0;
}