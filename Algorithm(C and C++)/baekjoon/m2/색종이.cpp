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
	int cnt; //판의 개수
	for (i = 1; i <= 6; i++)
	{
		scanf("%d", &arr[i]);
	}

	cnt = arr[6];
	
	cnt += arr[5];
	arr[1] -= arr[5] * 11;

	cnt += arr[4];
	arr[2] -= arr[4] * 5;
	if (arr[2] < 0) {
		arr[1] += arr[2] * 4;
		arr[2] = 0;
	}

	cnt += (arr[3] / 4);
	if (arr[3] % 4 != 0) cnt++;
	if (arr[3] % 4 == 1)
	{
		arr[2] -= 5;
		if (arr[2] < 0) {
			arr[1] += arr[2] * 4;
			arr[2] = 0;
		}
		arr[1] -= 7;
	}
	
	else if (arr[3] % 4 == 2)
	{
		arr[2] -= 3;
		if (arr[2] < 0) {
			arr[1] += arr[2] * 4;
			arr[2] = 0;
		}
		arr[1] -= 6;
	}

	else if (arr[3] % 4 == 3)
	{
		arr[2] -= 1;
		if (arr[2] < 0) {
			arr[1] += arr[2] * 4;
			arr[2] = 0;
		}
		arr[1] -= 5;
	}
	
	if (arr[2] != 0) 
	{
		cnt += arr[2] / 9;
		arr[2] %= 9;
	}
	if (arr[2]!= 0)
	{
		cnt++;
		arr[1] -= 36 - arr[2] * 4;
	}

	
	if (arr[1] > 0) {

		cnt += arr[1] / 36;
		if (arr[1] % 36 != 0)
			cnt++;
	}
	

	printf("%d", cnt);

}