#include<iostream>
#include<set>

using namespace std;

//포인트의 x, y좌표 저장
typedef struct point
{
	int x;
	int y;
	
};


int sudocu[9][9];

point arr[82];

//체워서 출력 
void dfs(int index)
{
	//종료 조건 
	if (index == 0)
	{
		//출력
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
	set<int> x,y,z; //행, 열, 3*3배열 
	int posx, posy;
	bool check = true;  //주소위치에서 배치된 수가 규칙에 일치하는지 고려하는 변수 
	
	posx = arr[index].x;
	posy = arr[index].y;

	//0의 위치의 x, y에서 확인 
	for (int i = 0; i < 9; i++)
	{
		//행
		x.insert(sudocu[posy][i]);
		//열 
		y.insert(sudocu[i][posx]);
	}

	//종이의 3*3 반복:
	for (int i = (posy / 3) * 3; i < (posy / 3) * 3 + 3; i++)
	{
		for (int j = (posx / 3) * 3; j < (posx / 3) * 3 + 3; j++)
		{
			z.insert(sudocu[i][j]);
		}
	}

	//1~9까지 삽입후 포함되있는가 확인 
	for (int i = 1; i <= 9; i++)
	{
		//만약 삽입을 할 수 있다면 삽입 
		//만약 x, y, z중 하나라도 i라는 숫자에 포함 안된다면 재귀 함수 
		if (x.find(i) == x.end() && y.find(i) == y.end() && z.find(i) == z.end())
		{
			//현재 위치에 숫자 삽입후 
			sudocu[posy][posx] = i;
			dfs(index - 1);
			//삽입후 되돌아 오면 숫자 초기화 
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
	//먼저 0의 위치를 찾는다. 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin >> num;
			//스도쿠 배열 입력
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

