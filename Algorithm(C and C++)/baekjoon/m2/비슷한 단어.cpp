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
		int diff = 0;  //������ �ִ� ���ڿ� ����ų� �ٸ� ���ڸ� �������� ����
		int map_diff = 0;
		scanf("%s", arr);
		if (i == 0)
		{
			//ù��°�� �Է��� �ܾ�
			for (int j = 0; j < strlen(arr); j++)
			{
				map[(int)arr[j] - 'A']++;
			}
		}
		else
		{
			//�������� ù��°�ܾ�� ����� �ܾ ã������ ����
			for (int j = 0; j < strlen(arr); j++)
			{
				//���� �ܾ�� �޸𿡼� �ʿ� ����
				other_map[(int)arr[j] - 'A']++;
			}
		
			//�ܾ ����
			
			

		}

	}

	printf("%d", count);
	return 0;
}