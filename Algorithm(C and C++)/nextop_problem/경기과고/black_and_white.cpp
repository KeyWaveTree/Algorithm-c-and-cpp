#include<iostream>
#include<string>

using namespace std;

typedef struct point
{
	int x;
	int y;
	int check;//������ ������ ���ΰ�?
	int dist; //���� �ڽ��� ������ �Ÿ�- �̰��� Ȱ���Ͽ� ��ġ���� Ȯ�� 
	int dPos[4];//�ڽ��� ���� ��ġ���� 4������ �� ���Ҵ°�?
};

//�Ʒ�, ��, ��, ��
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int board[120][120];
int n;// �ٵ����� ũ�� 
int l;// ��ֹ��� ���� 

//�Ÿ� ���� ����
point stack[14401];
int top;
//�ִ밪 ����
int max_dist = 1;

int main()
{
	freopen("input.txt", "r", stdin);
	string pos_input;
	
	int pos=0;//���� ���� 
	int i;
	//�Է�
	cin >> n >> l;

	for (i = 0; i < l; i++)
	{
		cin >> pos_input;
		//�ٵ��� ��ֹ� ��� ��ǥ 
		int x = (int)pos_input.at(0)-'A';
		int y = (int)pos_input.at(1)-'1';

		//��ֹ� ǥ�ø� -1
		board[y][x] = -1;
	}

	//�����

	//4���� Ž��
	top++;
	stack[top].x = 0;
	stack[top].y = 0;
	stack[top].dist = 1;
	stack[top].check = 1;//���

	//���� ���� stack top ��� �� check�� �Ǿ� �ִٸ� �� ������ ������ Ʈ�� ����̴�. 
	//���� �켱 ����: �Ʒ�, ��, ��, �� 
	//���� pos �������� ����. 
	int x = stack[top].x;
	int y = stack[top].y;
	int dist = 0;
	int cnt = 0;
	bool flag = true;
	
	while (true)
	{
		// Ž�� ���� 
		if (top == 0) break;
		x = stack[top].x;
		y = stack[top].y;
		dist = stack[top].dist;//������ �Ÿ� ī��Ʈ
		board[y][x] = 1;
		//�� ����: ���� �濡 -1 ���� �����ų� ���� ���� �����ϸ� ���̶�� �ν� 

		flag = false; //4������ �� ���Ҵ°�?
		//���̻� �� �� ���ٸ�
		cnt = 0;
		for (i = 0; i < 4; i++)
		{
			
			if (stack[top].dPos[i] == 1)
			{
				cnt++;
			}
		}
		if (cnt == 4) flag = true;
		//�ڽŰ� �����ٸ�
		else if(board[dy[pos] + y][dx[pos] + x] == 1)flag = true;
		else if (!flag && (board[dy[pos] + y][dx[pos] + x] == -1 
			|| dy[pos] + y >= n || dx[pos] + x < 0 
			|| dy[pos] + y < 0 || dx[pos] + x >= n))
		{
			//���� �ٲٱ� ���� ��ġ���� �� �� ���� ���� üũ 
			//���� �����ٸ� stack top���ٰ� check ǥ�� 
			stack[top].check = 1;
			flag = true;
			for (i = 0; i < 4; i++)
			{
				//���� �ڽ��� ��ġ�� �̹� ���ٿԴٸ� 
				if (stack[top].dPos[i] == 1) continue;
				//i ������ üũ �������� �� �� ������ 
				else if (stack[top].dPos[i] == 0 &&(board[dy[i] + y][dx[i] + x] == -1 
					|| dy[i] + y >= n || dx[i] + x < 0
					|| dy[i] + y < 0 || dx[i] + x >= n|| board[dy[i] + y][dx[i] + x] == 1))
				{
					//�ڽ��� ������ ���� 
				
					stack[top].dPos[i] = 1;
				}
				else if (stack[top].dPos[i] == 0)
				{
					flag = false; // ���� �ִ� dpos�� �ϳ��� 0�� ���ԵǸ� �� �� �ִ� �Ǵ� 
					pos = i; //�� ������ ���� �������� ��´�. 
					stack[top].dPos[i] = 1; // üũ 
					break;
				}
			}
		}

		//���� stack�� top ��ġ���� Ž���� ������ ����. 
		if (flag)
		{
			stack[top] = stack[0];
			//pop���� - stack ����� check�� 1 ǥ�õ� �������� pop���� 
			//������ ���� �Ǹ鼭 �Դٰ� �Ÿ�ǥ���� ������.
			while (stack[top].check != 1)
			{
				board[stack[top].y][stack[top].x] = 0;
				stack[top] = stack[0];
				top--;
			}

			continue;
		}


		//������ �������� �ʴ� �̻� ����, ǥ���� 1�� ������ �����. 
		// ���ÿ� �����Ѵ�.
		 
		max_dist = max(dist, max_dist);//���ݱ��� �Ÿ��� �ִ� �Ÿ��� ���Ͽ� �ִ�Ÿ��� �Ǵ�

		top++;
		stack[top].x = x + dx[pos];
		stack[top].y = y + dy[pos];
		stack[top].dist = dist + 1;
		stack[top].dPos[pos] = 1;
	}
	
	cout << max_dist;

	return 0;
}


//���Ǳ� �� ����ġ�� �翷���� �� �� ���� 
//�� n�� ũ��� 120�� ���� �ʴ´�. 
//��ֹ��� ������ 200�� ���� �ʴ´�. 
//��ֹ� ��ȣ A~Z x��ǥ�� 26�� �Ѿ�� �ʴ´�. 