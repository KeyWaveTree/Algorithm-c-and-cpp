#include<iostream>

using namespace std;

int check[3001];
int arr[3000000];
int spare[3001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, d, k, c;
	int i, j;
	int flag=0;
	int cnt = 0;
	int num = 0;
	int sum = 0;
	//접시 수 n, 초밥의 가지 수 d, 연속해서 먹는 접시 k, 쿠폰 번호
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	////브루트 포스 - 1
	//for (i = 0; i < n; i++)
	//{
	//	check[c] = 1;
	//	flag = 0;
	//	cnt = 1;
	//	for (j = i; j < i + k; j++)
	//	{
	//		if (check[arr[j % n]] == 0) cnt++; // 처음 먹는 초밥이면 카운트
	//		check[arr[j % n]] = 1; // 먹은 초밥 체크
	//	}
	//	sum = max(sum, cnt);
	//	for (j = 0; j < 3001; j++)
	//	{
	//		check[j] = 0;
	//	}
	//}

	//printf("%d", sum);

	/* 누적합 방법 - 2
	 배열을 만들어서 각 인덱스 요소에 더한다 +1 
	 k+1를 더한 인덱스 요소는 +1하고 
	 k+1-k를 한 인덱스 요소는 없애준다. 0으로 만든다. 
	 쿠폰은 인덱스 위치에 1을 계속 넣어준다. 
	 각자리의 합이 k일때 cnt를 +1한다.*/

	//check[c] = 1;
	//for (i = 0; i < n; i++)
	//{
	//	check[arr[i % n]] = 1;
	//	spare[cnt] = arr[i % n]; //check의 인덱스를 임의 공간에 저장시켜 초기화 할때 사용
	//	cnt++;
	//	
	//	if ((cnt-num) % k == 0)
	//	{
	//		for (j = num; j < cnt; j++)
	//		{
	//			flag += check[spare[j]];
	//		}
	//		if (k == flag) sum++; //초밥개수와 각 초밥이 겹치지 않는 다면 
	//		flag = 0;
	//		num++; //k+1-k 를 위한 값(하나씩 늘어나면서 맨 끝은 필요 없음)
	//	}
	//}

	//printf("%d", sum);
	//복습 하기 

	int s = 0;
	int e = 0;

	int total = 1;
	check[c] = 1;// 쿠폰

	for (i = 0; i < k; i++) //한번 싸이클 돌림
	{
		if (check[arr[i]]==0) total++; //초밥이 현재 없으면 초밥개수 업
		check[arr[i]]++; //한번 했다는 신호 
	}
	
	if (sum < total)sum = total;

	//그다음 부터 순환 작업 슬라이딩
	s = k - 1; //k개만큼 차 있기때문에 s 위치 조절
	e = 0;

	for (i = 0; i < n; i++)
	{
		check[arr[e]] -= 1;//현재 체크하는 구간은 모두 1이상 
		if (check[arr[e]] == 0)total--;
		e = (e + 1) % n;//로테이션

		s = (s + 1) % n; //로테이션
		check[arr[s]] += 1;
		if (check[arr[s]] == 1) total++; //현재 s에 1이 있을때 
		if (sum < total)sum = total;
	}

	printf("%d", sum);
	return 0;
}