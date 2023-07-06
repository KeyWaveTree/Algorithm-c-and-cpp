#include<iostream>

using namespace std;

int main()
{
	int max_point[100] = { 0 };
	int sum = 0;
	int max=-1;
	int max_index = -1;
	int in;
	int i;

	for (i = 0; i < 10; i++)
	{
		cin >> in; 
		sum += in;//평균을 구하기 위한 값
		//최빈값을 구하기 위해 태이블 지정
		//값은 항상 10의 배수이기에 /10을하면 데이터 크기를 줄여줌
		max_point[in/10]++;
	}

	for (i = 1; i < 100	; i++)
	{
		//최빈값 찾기
		if (max < max_point[i])
		{
			//최빈값 포인트 max로 지정
			max = max_point[i];
			//현재 최빈값 인덱스를 max_index로 저장
			max_index = i;
		}
	}

	printf("%d\n%d", sum / 10, max_index * 10);
	return 0;
}