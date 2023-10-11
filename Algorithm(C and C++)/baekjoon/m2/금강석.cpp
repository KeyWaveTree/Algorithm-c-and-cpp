#include<iostream>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

point bundle[100];
//�ʺ�, ����, ���� ����, �밢�� ���� 
int n, m, t, k;
int ans;
int max_x, max_y;

//1. ��ü ��ǥ�� 45�� ��￩�� Ǭ ����
void plan(int x, int y)
{
	int q;
	int cnt = 0;
	int p = y - x; //��ǥ ��ġ���� ��� ��

	//��ǥ���� k�� ���Ѵ�. 
	if (x + y + k > 2 * n) {
		x = n - (p / 2) - (k / 2); //��� ���� �����ؼ� ����� �ٽ� ����
		y = n + (p / 2) - (k / 2); //
	}
	//�������� ���� -k/2 �Ͽ� ����Ʈ ���� 
	for (q = 0; q < t; q++)//������ ����
	{
		//�ݰ��� ����ź �Ÿ� - ���� ��ǥ�� ȸ�������Ƿ� �ʿ� ����
		//if (abs(bundle[q].x - x) + abs(bundle[q].y - y) <= k / 2) cnt++;
		if (x <= bundle[q].x && bundle[q].x <= x + k && y<= bundle[q].y && bundle[q].y <= y+k) cnt++;
	}
	
	if (ans < cnt)
	{
		//���簢�� ������ �Ǵ� ���� �Ʒ����� ���� ���� ����
		//���� �Ʒ� ������ ���� �밢�� ���� ���ϱ� - ����
		max_x = x + k/2; 
		max_y = y + k/2;
		ans = cnt;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, j;
	int w, h;
	int x, y;
	scanf("%d%d%d%d", &n, &m, &t, &k);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &x, &y);
		//ȸ�� ��� 
		bundle[i].x = x+y;
		bundle[i].y = x-y;
	}

	//�÷��� ������
	for (i = 0; i < t; i++)//���� 
	{	
		for (j = 0; j < t; j++)//����
		{
			//�ڵ������� ��ġ�� ������ ��ġ�� ��
			//������ �밢������ ���� - ȸ�� ���
			w = bundle[i].x;
			h = bundle[j].y;
			//��ǥ�� ���� ����� �ִٸ� 
			if ((w + h) % 2)
			{
				//���� 4���� �������� �� Ž�� - ���� �ִ� �ݰ��� �� 	
				plan(w - 1, h);
				plan(w, h - 1);
				plan(w + 1, h);
				plan(w, h + 1);
			}
			//�� �̿� 
			else plan(w, h);
		}
	}

	//���� ����Ʈ�� �����ȿ� ���ٸ� �ٽ� ���ġ 

	//ȸ�� ��� -> �ٽ� ���� ���� /2 ¦�� ��ǥ�� ���ؼ� 
	printf("%d %d\n%d", (x+y)/2, (x-y)/2, ans);

	return 0;
}