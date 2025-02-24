#include<iostream>
#define SIZE 12
using namespace std;

int r;
int n;
int w, h;
char map[SIZE][SIZE];


void input()
{
	int i;
	scanf("%d", &r);
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &w, &h);
		map[w-1][h-1] = 'N';
	}
}

void L(int x, int y)
{
	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	L(1, 1);
}