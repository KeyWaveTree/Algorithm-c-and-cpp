#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int arr[10][10] = { 0 };
	int n, cnt;
	int i=1, j;
	//bool flag =true; //�� ���� ����

	scanf("%d", &n);

	//�ʱ�ȭ
	for (int k = 1; k <= n; k++)
	{
		for (j = 1; j <= n; j++)
		{
			arr[k][j] = -1;
		}
	}

	j = n / 2 + 1;
	cnt = i;
	arr[i][j] = 1;

	while (cnt!=n*n)
	{
		i--, j++;
		if (i == 0 && j > n) i += 2, j--;
		else if (i == 0) i += n;
		else if (j > n) j -= n;
		else if (arr[i][j] != -1) i += 2, j--;
		//�ۿ� �ִ� 0�̰ų� �ȿ� �ִ� �Ҵ��� �ȵ� ������ ���̸� 
		//if (arr[i][j] == 0 || arr[i][j] == -1) flag = false;
		//������ ���� �Ҵ��� �Ǿ� ������ 
		//else flag = true;
		//if (!flag && i == 0) i += n;
		//if (!flag && j > n) j -= n;
		//��ġ ������ ���� 1��° �����̸� �ٽ� �ݺ�
		//if (flag) i+=2, j--;
		
		arr[i][j]=++cnt;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}