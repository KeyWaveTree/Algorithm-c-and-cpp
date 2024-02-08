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
	point track; //위치 주소
	bool check = true; //track의 주소위치에서 배치된 수가 규칙에 일치하는지 고려하는 변수 
	
	
	//만약 내가 지정한 인덱스 값이 마킹이 되어있는 값 길이보다 길어졌을때(index 고려하여) 종료
	if (index == marking.size()) return flag = true;
	
	//체크 확인 연산 단계 
	track = marking.at(index);
	for (pos = 0; pos < 9; pos++)
	{
		//행 축을 
		number[0][sudoku[pos][track.x]] = true;
		//열 축 
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
	//입력 - backtraking을 하기 위한 준비 구간 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			empty.x = i;
			empty.y = j;
		
			//스도쿠에서 입력받은 값이 0일때 비워져 있으므로 좌표를 안에다가 넣는다.
			if (sudoku[i][j] == 0)
			{
				marking.push_back(empty);
			}
		}
	}

	//backtraking
	tracking(0);
}