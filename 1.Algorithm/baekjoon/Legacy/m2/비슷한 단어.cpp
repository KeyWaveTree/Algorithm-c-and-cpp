#include<iostream>
#include<string.h>

using namespace std;

int main()
{

	freopen("input.txt", "r", stdin);
	char temp[11] = { '\0' };
	int map[26] = { 0 };
	

	int n;
	int i;
	int count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		char arr[11] = { '\0' };
		//0~25 A~Z
		int other_map[26] = { 0 };//ù��°�� �Է��� �ܾ�� ���� ���ĺ� ����
		int diff = 0;  //������ �ִ� ���ڿ� ����ų� �ٸ� ���ڸ� �������� ����
		int flag = false;
		scanf("%s", arr);
		if (i == 0)
		{
			//ù��°�� �Է��� �ܾ�
			for (int j = 0; j < strlen(arr); j++)
			{
				map[(int)arr[j] - (int)'A']++;
			}
			strcpy(temp, arr);
		}
		else
		{
			//�������� ù��°�ܾ�� ����� �ܾ ã������ ����
			for (int j = 0; j < strlen(arr); j++)
			{
				//���� �ܾ�� �޸𿡼� �ʿ� ����
				other_map[(int)arr[j] - (int)'A']++;
			}
		
			//�ܾ ����
			if (strlen(arr) == strlen(temp)) flag = true;

			for (int j = 0; j < 26; j++)
			{
				if (map[j] != other_map[j])
				{
					diff += abs(map[j] - other_map[j]);
				}
			}

			if (flag && diff <= 2 && diff >= 0) count++;
			else if (diff <= 1 && diff >= 0) count++;

		}

	}

	printf("%d", count);
	return 0;
}