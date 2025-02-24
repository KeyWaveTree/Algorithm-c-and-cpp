#include<stdio.h>

#define N 10
int arr[N][N];
int work, end;

struct Q
{
	int x;
	int y;
	int v;
}queue[N*N];

int E(int h, int w, int L) //y, x, level- ���� ��ġ ��
{
	if (!arr[h + 1][w] && h + 1 <= N)
	{
		arr[h + 1][w] = L + 1;
		end++;
		queue[end].x = h+1;
		queue[end].y = w;
		queue[end].v = L + 1;
	}
	if (!arr[h - 1][w] && h - 1 > 0)
	{
		arr[h - 1][w] = L + 1;
		end++;
		queue[end].x = h-1;
		queue[end].y = w;
		queue[end].v = L + 1;
	}
	if (!arr[h][w + 1] && w + 1 <= N)
	{
		arr[h][w + 1] = L + 1;
		end++;
		queue[end].x = h;
		queue[end].y = w+1;
		queue[end].v = L + 1;
	}
	if (!arr[h][w - 1] && w - 1 > 0)
	{
		arr[h][w + 1] = L + 1;
		end++;
		queue[end].x = h;
		queue[end].y = w-1;
		queue[end].v = L + 1;
	}
}

int main()
{
	freopen("nextop-problem", "r", stdin);
	int n;
	int i, j, L = 0, flag = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", arr[i][j]);
		}
	}

	arr[1][1] = 1;
	queue[1].x = 1;
	queue[1].y = 1;
	queue[1].v = 1;

	end = 1;
	while (1)
	{
		if (work == end)break;

		work++;
		E(queue[work].x, queue[work].y, queue[work].v);

	}

	//���� �ð����⵵�� O(n^3) 
	//while (flag)
	//{
	//	flag = 0;
	//	L++;
	//	//queue �ڷᱸ���� ���

	//	//�˻��� ���ϰ� ã���� �ִ� ���
	//	//for (i = 1; i <= n; i++) //�� i �ݺ���
	//	//{
	//	//	for (j = 1; j <= n; j++) //�� j �ݺ��� �ұ�?
	//	//	{
	//	//		if (arr[i][j] == L)
	//	//		{
	//	//			flag = 1;
	//	//			E(i, j, L);
	//	//		}
	//	//	}
	//	//}
	//}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d", arr[i][j]);
		}
	}

	return 0;
}