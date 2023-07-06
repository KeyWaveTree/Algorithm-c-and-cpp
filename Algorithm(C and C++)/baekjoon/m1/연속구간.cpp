#include<iostream>
#include<string>

using namespace std;

int main()
{
	string ebit; //8개 bit를 string으로 저장하면 배열과 같은 이점이 있다. 
	int max; //같은 값을 같은 연속된 열 최대길이 저장하는 변수
	int cnt;//같으면 증가 다르면 초기화 
	int i, j;

	for (i = 0; i < 3; i++)
	{
		//입력받을때 마다 초기화 
		max = 0, cnt = 1;

		cin >> ebit;
		//8bit를 ebit[7]까지 비교함 같으면 증가 도중에 다르면 초기화 후 저장
		for (j = 0; j < 8; j++)
		{
			//같으면 길이 수 증가
			if (ebit[j] == ebit[j + 1]) cnt++;
			//다르면 다시 초기화 
			else cnt = 1;
			//길이의 수가 현재 저장된 최대값보다 크다면 저장
			if (max < cnt) max = cnt;
		}
		//각 string 마다 최대 길이 출력
		printf("%d\n", max);
	}

	return 0;
}