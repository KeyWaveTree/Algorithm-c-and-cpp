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

		int other_map[27] = { 0};//ù��°�� �Է��� �ܾ�� ���� ���ĺ� ����
		int cnt = 0;//����ȭ�� ���� ����
		int diff = 0;  //������ �ִ� ���ڿ� ����ų� �ٸ� ���ڸ� �������� ����
		int map_diff = 0;
		scanf("%s", arr);
		if (i == 0)
		{
			//ù��°�� �Է��� �ܾ�
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
			//�������� ù��°�ܾ�� ����� �ܾ ã������ ����
			for (int j = 0; j < strlen(arr); j++)
			{
				//���� �ܾ�� �޸𿡼� �ʿ� ����
				if (other_map[(int)arr[j] - 'A'] == 0)
				{
					//other_map�� �ε��� ����
					memo[cnt] = (int)arr[j] - 'A';
					cnt++;
				}
				other_map[(int)arr[j] - 'A']++;
			}
		
			//�ܾ ����
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