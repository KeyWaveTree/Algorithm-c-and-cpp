#include<iostream>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

point bundle[101];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//n-�ٴ� ����, L-�׹��� �ѷ�, m - ������� ��
	int n, l, m;
	int i, j, k;//�ݺ���
	int w, h;//�÷��� ������ ���� ��ǥ
	int a, b;//�׹��� �ʺ�, ����
	int cnt=0;//����� ���� ����
	int max = 0;
	scanf("%d%d%d", &n, &l, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &bundle[i].x, &bundle[i].y);
	}

	//�÷��� ������
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			//���� ����
			w = bundle[i].x;
			h = bundle[j].y;
			
			//�� �����ȿ� �ִ� �ִ� ������?
			//������ �׹� ���� 
			if (l % 2 != 0) continue;

			//�ѷ� a:1~l/2, b=l/2~1
			for (a = 1; a < l / 2; a++)
			{
				//����� ���� �ʱ�ȭ
				cnt = 0;

				b = (l / 2) - a;
				//��ġ �˻� 
				for (k = 1; k <= m; k++)
				{
					if (w <= bundle[k].x && bundle[k].x <= w + a && h <= bundle[k].y && bundle[k].y <= h + b) cnt++;
				}
				if (max < cnt)max = cnt;
			}
		}
	}

	//��� 
	printf("%d", max);
	return 0;
}