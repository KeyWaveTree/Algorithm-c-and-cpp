#include<iostream>

using namespace std;

int main()
{
	//A, B의 카드는 각 10개
	int card[2][10] = { 0 };

	int a_cnt=0; //A가 이긴 턴
	int b_cnt = 0;//B가 이긴 턴
	int i, j;
	int a = 0, b = 1; 
	//a-0번째 칸 담당
	//b-1번째 칸 담당

	//입력
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cin >> card[i][j];
		}
	}

	//각 인덱스 값을 통해 요소를 비교했을때 
	for (i = 0; i < 10; i++)
	{
		//같을때는 넘김 - 계산 할 필요없이 이긴 횟수만 체크
		if (card[a][i] == card[b][i]) continue;
		else if (card[a][i] > card[b][i]) a_cnt++;
		else if (card[a][i] < card[b][i])b_cnt++;
	}

	if (a_cnt > b_cnt) printf("%c", 'A');
	else if (a_cnt < b_cnt) printf("%c", 'B');
	else printf("%c", 'D');

	return 0;
}