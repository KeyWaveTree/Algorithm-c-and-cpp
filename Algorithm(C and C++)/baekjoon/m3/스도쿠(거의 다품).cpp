#include<iostream>
#include<vector>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

bool flag;
int sudoku[9][9];
vector<point> marking;


void tracking(int index)
{
	bool number[3][9] = { false };
	int pos, posX, posY;
	point track; //��ġ �ּ�
	bool check = true; //track�� �ּ���ġ���� ��ġ�� ���� ��Ģ�� ��ġ�ϴ��� ����ϴ� ���� 
	
	
	//���� ���� ������ �ε��� ���� ��ŷ�� �Ǿ��ִ� �� ���̺��� ���������(index ����Ͽ�) ����
	if (index == marking.size()) return flag = true;
	
	//üũ Ȯ�� ���� �ܰ� 
	track = marking.at(index);
	for (pos = 0; pos < 9; pos++)
	{
		//�� ���� 
		number[0][sudoku[pos][track.x]] = true;
		//�� �� 
		number[1][sudoku[track.y][pos]] = true;
	}

	for (pos = 1; pos <= 9; pos++)
	{
		if(number[0][pos] == false )
	}

	for (posX = (track.x / 3) * 3; posX < (track.x / 3) * 3 + 3; posX++)
	{
		for (posY = (track.y / 3) * 3; posY < (track.y / 3) * 3 +3; posY++)
		{
	 
		}

	}
}

int main()
{
	point empty;
	int i, j;
	//�Է� - backtraking�� �ϱ� ���� �غ� ���� 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			empty.x = i;
			empty.y = j;
		
			//�������� �Է¹��� ���� 0�϶� ����� �����Ƿ� ��ǥ�� �ȿ��ٰ� �ִ´�.
			if (sudoku[i][j] == 0)
			{
				marking.push_back(empty);
			}
		}
	}

	//backtraking
	tracking(0);
}