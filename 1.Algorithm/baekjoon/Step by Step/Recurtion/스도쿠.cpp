#include<iostream>
#include<set>

using namespace std;

//����Ʈ�� x, y��ǥ ����
typedef struct point
{
	int x;
	int y;
	
};


int sudocu[9][9];

point arr[82];

//ü���� ��� 
void dfs(int index)
{
	//���� ���� 
	if (index == 0)
	{
		//���
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sudocu[i][j];
			} 
			cout << '\n';
		}
		exit(0);
	}
	set<int> x,y,z; //��, ��, 3*3�迭 
	int posx, posy;
	bool check = true;  //�ּ���ġ���� ��ġ�� ���� ��Ģ�� ��ġ�ϴ��� ����ϴ� ���� 
	
	posx = arr[index].x;
	posy = arr[index].y;

	//0�� ��ġ�� x, y���� Ȯ�� 
	for (int i = 0; i < 9; i++)
	{
		//��
		x.insert(sudocu[posy][i]);
		//�� 
		y.insert(sudocu[i][posx]);
	}

	//������ 3*3 �ݺ�:
	for (int i = (posy / 3) * 3; i < (posy / 3) * 3 + 3; i++)
	{
		for (int j = (posx / 3) * 3; j < (posx / 3) * 3 + 3; j++)
		{
			z.insert(sudocu[i][j]);
		}
	}

	//1~9���� ������ ���Ե��ִ°� Ȯ�� 
	for (int i = 1; i <= 9; i++)
	{
		//���� ������ �� �� �ִٸ� ���� 
		//���� x, y, z�� �ϳ��� i��� ���ڿ� ���� �ȵȴٸ� ��� �Լ� 
		if (x.find(i) == x.end() && y.find(i) == y.end() && z.find(i) == z.end())
		{
			//���� ��ġ�� ���� ������ 
			sudocu[posy][posx] = i;
			dfs(index - 1);
			//������ �ǵ��� ���� ���� �ʱ�ȭ 
			sudocu[posy][posx] = 0;
		}
		
	
	}
	
}

int main()
{
	freopen("input.txt", "r", stdin);

	point empty;
	int i, j;
	int num;
	int cnt = 1;
	//���� 0�� ��ġ�� ã�´�. 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin >> num;
			//������ �迭 �Է�
			sudocu[i][j] = num;
			empty.x = j;
			empty.y = i;
			if (num == 0)
			{
				arr[cnt] =empty;
				cnt++;
			}
		}
	}
	

	dfs(cnt-1);
}

