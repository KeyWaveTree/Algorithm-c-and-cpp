#include<iostream>

using namespace std;

int main()
{
	int n; //문제 개수
	int c; //각 문제가 맞는지 맞지 않는지 저장
	int temp=0; //연속해서 문제를 맞으면 다음에 저장할 총 점수 증가
	int score = 0;// 총점수 공간

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		//입력한 값이 1이 맞다면 
		if (c)
		{
			//카운트 변수인 temp가 증가된다. 
			temp++;
		}
		else
		{
			//도중에 입력한 값이 0이면 보너스 점수를 초기화 해준다. 
			temp = 0;
		}
		score += temp;
	}

	printf("%d", score);

	return 0;
}
