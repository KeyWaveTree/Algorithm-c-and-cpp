#include<iostream>

using namespace std;

int check[30001];
int arr[30001];
int main()
{
	//브루트 포스 - 1
	//접시 수 n, 초밥의 가지 수 d, 연속해서 먹는 접시 k, 쿠폰 번호  
	int n, d, k, c;
	int i, j;
	int flag;
	int sum=0;
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int coupon = c;
	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = i; j < i + k; j++)
		{
			if (check[arr[j % n]] == 1) flag++; // 이미 먹은 초밥일 경우 중복 수 표시	
			else check[arr[j % n]] = 1; // 처음 먹어보는 초밥일 경우 체크		

			if (arr[j % n] == c) coupon = 0; // 쿠폰 스시 있을 시
		}
		sum = max(sum, k - flag + coupon); //연속으로 먹을 수 있는 최대접시 - 중복접시 + 쿠폰스시	
		memset(check, 0, sizeof(check)); // 체크 초기화
	}

	// 누적합 방법 - 2
	// 배열을 만들어서 각 인덱스 요소에 더한다 +1 
	// K+1를 더한 인덱스 요소는 +1하고 
	// k+1-k를 한 인덱스 요소는 없애준다. 0으로 만든다. 
	// 쿠폰은 인덱스 위치에 1을 계속 넣어준다. 
	// 각자리의 합이 k일때 cnt를 +1한다.
}