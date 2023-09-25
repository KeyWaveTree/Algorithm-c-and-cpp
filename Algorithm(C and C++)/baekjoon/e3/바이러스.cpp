#include<iostream>

using namespace std;

//dfs����
int map[101][101] = { 0 };//���� ���
int check[101] = { 0 };//üũ 
int all; //��� ��ǻ���� ��
int con; //����Ǿ� �ִ� ��ǻ�� ��
int s, e;
int cnt;

int input()
{
	int i;
	scanf("%d", &all);
	scanf("%d", &con);

	if (con == 0) return 0;
	//������� 
	for (i = 1; i <= con; i++)
	{
		scanf("%d%d", &s, &e);
		map[s][e] = 1;
		map[e][s] = 1;
	}

	return 1;
}

void dfs(int start)
{
	int i;
	check[start] = 1;
	//����Ǿ� �ִ� ��ǻ�Ͱ� ������ ����
	//�� �� �� ������ 
	for (i = 1; i <= all; i++) //���� i�� end ���� 
	{
		
		if (check[i] == 0 && map[start][i] == 1)
		{
			check[i] = 1;
			cnt++;
			dfs(i);
		}
	}
}

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int code = input();
	if (code == 1) dfs(1);
	printf("%d", cnt);
	return 0;
}