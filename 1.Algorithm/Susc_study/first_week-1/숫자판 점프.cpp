#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> ission;
int board[5][5];

//종료 조건
void dfs(int start, int x, int y, int cnt) {
	if (cnt == 5)
	{
		ission.insert(start);
		return;
	}

	if (x + 1 < 5) dfs((start * 10) + board[x + 1][y], x + 1, y, cnt + 1);
	if (x - 1 >= 0) dfs((start * 10) + board[x - 1][y], x - 1, y, cnt + 1);
	if (y + 1 < 5) dfs((start * 10) + board[x][y + 1], x, y + 1, cnt + 1);
	if (y - 1 >= 0) dfs((start * 10) + board[x][y - 1], x, y - 1, cnt + 1);
}

int main() {
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &board[i][j]);
		}
			
	}
		
	//dfs 모든 좌표에서 
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			//시작점, x, y,  cnt
			dfs(board[j][i], j, i, 0);
		}
	}
		
	printf("%d", ission.size());

	return 0;
}