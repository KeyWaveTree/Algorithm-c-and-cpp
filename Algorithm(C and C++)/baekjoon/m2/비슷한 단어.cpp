#include<iostream>
#include<string.h>

using namespace std;

int main()
{

	freopen("input.txt", "r", stdin);

	int map[27] = { 0 };
	char arr[11] = { '\0' };
	int map_memo[10] = { 0 };
	int memo[10] = { 0 };
	int n;
	int i;
	int count = 0;
	int map_cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{

		int other_map[27] = { 0};//첫번째로 입력할 단어와 비교할 알파벳 개수
		int cnt = 0;//최적화를 위한 변수
		int diff = 0;  //기존에 있던 글자와 벗어나거나 다른 글자를 세기위한 변수
		int map_diff = 0;
		scanf("%s", arr);
		if (i == 0)
		{
			//첫번째로 입력한 단어
			for (int j = 0; j < strlen(arr); j++)
			{
				if (map[(int)arr[j] - 'A'] == 0)
				{
					map_memo[map_cnt] = (int)arr[j] - 'A';
					map_cnt++;
				}
				map[(int)arr[j] - 'A']++;
			}
		}
		else
		{
			//나머지는 첫번째단어와 비슷한 단어를 찾기위한 연산
			for (int j = 0; j < strlen(arr); j++)
			{
				//같은 단어는 메모에서 필요 없음
				if (other_map[(int)arr[j] - 'A'] == 0)
				{
					//other_map의 인덱스 저장
					memo[cnt] = (int)arr[j] - 'A';
					cnt++;
				}
				other_map[(int)arr[j] - 'A']++;
			}
		
			//단어별 개수
			for (int j = 0; j < cnt; j++)
			{
				diff += abs(other_map[memo[j]] - map[memo[j]]);
			}
			for (int j = 0; j < map_cnt; j++)
			{
				map_diff += abs(other_map[map_memo[j]] - map[map_memo[j]]);
			}

			diff = max(diff, map_diff);
			if (diff <= 1 && diff >= 0) count++;

		}

	}

	printf("%d", count);
	return 0;
}