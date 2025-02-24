//다시 하기 내가 짠 코드가 아님

#include<iostream>

using namespace std;

int student[4][3] = { 0 };

int main()
{
	int check[3] = { 0 };	   //check 배열 
	bool flag = true;
	int in;
	int n;
	int i, j;
	int cnt = 0;
	int max = 0;
	int max_index=0;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> in;
			student[0][j] += in;//점수 더하기
			student[4 - in][j]++; //몇번 나왔는가?
		}
	}

	//최대값 찾기
	for (i = 0; i < 3; i++)
	{
		if (max < student[0][i])
		{
			max = student[0][i];
			max_index = i;
		}
	}
	
	//체크 
	int p = 0;
	for (j = 0; j < 4; j++)
	{
		max = 0;
		cnt = 0;
		max_index = 0;
		for (i = 0; i < 3; i++)
		{
			if (student[j][i] > max)
			{
				max = student[j][i];
				max_index = i;
			}
		}
		
		for (i = 0; i < 3; i++)
		{
			if (student[j][i] == max&&(j==0||check[i])) {
				cnt++;
				if (j == 0)
					check[i] = 1;
			}
		}
		if (cnt == 1)
		{
			printf("%d %d", max_index+1, student[0][max_index]);
			return 0;
		}
	}
	printf("%d %d", 0, student[0][max_index]);
}