#include<iostream>
#include<vector>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

int chessBoard[10][10];
vector<point> sponer;

int main()
{
	int n;
	int i, j;
	int bishop_spon = 0;
	

	//입력 처리 
	cin >> n;
	
	sponer.assign(100, {0, 0});

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> chessBoard[i][j];
			if (chessBoard[i][j] == 1) 
			{
				sponer		
				bishop_spon++;
			}
		}
	}




}