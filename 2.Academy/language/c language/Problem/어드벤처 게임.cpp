#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define and &&
#define or ||
#define not ~

char arr[10][10];

void start()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 9 and i == 9) arr[i][j] = 'G';
			else arr[i][j] = '.';
			if (i == 1 and j == 1) arr[i][j] = '#';
		}
	}
}

void map(char &key, int &x, int &y)
{
	if (key == 'w')
	{
		arr[x][y - 1] = '#';
		arr[x][y] = '.';
		y--;
	}
	else if (key == 's')
	{
		arr[x][y + 1] = '#';
		arr[x][y] = '.';
		y++;
	}

	if (key == 'a')
	{
		arr[x - 1][y] = '#';
		arr[x][y] = '.';
		x--;
	}
	else if (key == 'd')
	{
		arr[x + 1][y] = '#';
		arr[x][y] = '.';
		x++;
	}
}

int main()
{
	srand(time(NULL));

	char key;
	int x = 1, y = 1;
	int mo1Pos = 5;
	int mo2Pos = 6;

	start();

	while (1)
	{

		key = _getch();
		mo1Pos = rand() % 10;
		mo2Pos = rand() % 10;

		map(key, x, y);

		system("cls");
	}

	return 0;
}