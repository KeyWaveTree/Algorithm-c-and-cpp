#include<iostream>

using namespace std;

int arr[1000];
int size_arr;
int k;

// 정렬 한 기준으로
//upper bound - 이진탐색을 하면서 현재 탐색한 값보다 더 큰 값의 처음 위치 
int upper_bound(int s, int e)//start, end, find_value
{
	int m;
	while (s - e != 0)//이진탐색을 하면서 가리키는 값이 겹치지 말아야 하기에 
	{
		m = (s + e) / 2; //첫번째 위치와 마지막 위치를 더하면 배열의 길이임
		if (arr[m] <= k) s = m + 1; //같을때도 넘겨주어야 한다. - 이 코드가 찾는것은 k값이 아닌 k 값보다 큰 수이다.
		else e = m;
	}
	return e;
}

int main() 
{
	scanf("%d", &size_arr);
	for (int i = 1; i <= size_arr; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);


}