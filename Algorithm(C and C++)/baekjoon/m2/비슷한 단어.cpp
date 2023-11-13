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
		int diff = 0;  //기존에 있던 글자와 벗어나거나 다른 글자를 세기위한 변수
		int map_diff = 0;
		scanf("%s", arr);
		if (i == 0)
		{
			//첫번째로 입력한 단어
			for (int j = 0; j < strlen(arr); j++)
			{
				map[(int)arr[j] - 'A']++;
			}
		}
		else
		{
			//나머지는 첫번째단어와 비슷한 단어를 찾기위한 연산
			for (int j = 0; j < strlen(arr); j++)
			{
				//같은 단어는 메모에서 필요 없음
				other_map[(int)arr[j] - 'A']++;
			}
		
			//단어별 개수
			
			

		}

	}

	printf("%d", count);
	return 0;
}