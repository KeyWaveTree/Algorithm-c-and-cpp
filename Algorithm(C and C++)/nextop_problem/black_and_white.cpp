#include<iostream>
#include<string>

using namespace std;

typedef struct point
{
	int x;
	int y;
	int check;//도달한 지점이 벽인가?
	int dist; //현재 자신이 도달한 거리- 이것을 활용하여 겹치는지 확인 
	int dPos[4];//자신은 현재 위치에서 4방향을 다 보았는가?
};

//아래, 오, 위, 왼
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int board[120][120];
int n;// 바둑판의 크기 
int l;// 장애물의 개수 

//거리 저장 스택
point stack[14401];
int top;
//최대값 저장
int max_dist = 1;

int main()
{
	freopen("input.txt", "r", stdin);
	string pos_input;
	
	int pos=0;//현재 방향 
	int i;
	//입력
	cin >> n >> l;

	for (i = 0; i < l; i++)
	{
		cin >> pos_input;
		//바둑판 장애물 행렬 좌표 
		int x = (int)pos_input.at(0)-'A';
		int y = (int)pos_input.at(1)-'1';

		//장애물 표시를 -1
		board[y][x] = -1;
	}

	//빈공간

	//4방향 탐색
	top++;
	stack[top].x = 0;
	stack[top].y = 0;
	stack[top].dist = 1;
	stack[top].check = 1;//노드

	//만약 현재 stack top 요소 중 check가 되어 있다면 그 지점은 방향을 트는 노드이다. 
	//방향 우선 순위: 아래, 좌, 우, 위 
	//먼저 pos 방향으로 간다. 
	int x = stack[top].x;
	int y = stack[top].y;
	int dist = 0;
	int cnt = 0;
	bool flag = true;
	
	while (true)
	{
		// 탐색 종료 
		if (top == 0) break;
		x = stack[top].x;
		y = stack[top].y;
		dist = stack[top].dist;//전진시 거리 카운트
		board[y][x] = 1;
		//벽 조건: 가는 길에 -1 벽을 만나거나 범위 끝에 도달하면 벽이라고 인식 

		flag = false; //4방향을 다 보았는가?
		//더이상 갈 수 없다면
		cnt = 0;
		for (i = 0; i < 4; i++)
		{
			
			if (stack[top].dPos[i] == 1)
			{
				cnt++;
			}
		}
		if (cnt == 4) flag = true;
		//자신과 만났다면
		else if(board[dy[pos] + y][dx[pos] + x] == 1)flag = true;
		else if (!flag && (board[dy[pos] + y][dx[pos] + x] == -1 
			|| dy[pos] + y >= n || dx[pos] + x < 0 
			|| dy[pos] + y < 0 || dx[pos] + x >= n))
		{
			//방향 바꾸기 현재 위치에서 갈 수 없는 방향 체크 
			//벽을 만났다면 stack top에다가 check 표시 
			stack[top].check = 1;
			flag = true;
			for (i = 0; i < 4; i++)
			{
				//만약 자신의 위치를 이미 갔다왔다면 
				if (stack[top].dPos[i] == 1) continue;
				//i 방향을 체크 안했지만 갈 수 없을때 
				else if (stack[top].dPos[i] == 0 &&(board[dy[i] + y][dx[i] + x] == -1 
					|| dy[i] + y >= n || dx[i] + x < 0
					|| dy[i] + y < 0 || dx[i] + x >= n|| board[dy[i] + y][dx[i] + x] == 1))
				{
					//자신의 방향은 제외 
				
					stack[top].dPos[i] = 1;
				}
				else if (stack[top].dPos[i] == 0)
				{
					flag = false; // 갈수 있는 dpos가 하나라도 0이 포함되면 갈 수 있다 판단 
					pos = i; //그 공간을 현재 방향으로 삼는다. 
					stack[top].dPos[i] = 1; // 체크 
					break;
				}
			}
		}

		//현재 stack의 top 위치에서 탐색할 공간이 없다. 
		if (flag)
		{
			stack[top] = stack[0];
			//pop연산 - stack 요소의 check가 1 표시된 공간까지 pop연산 
			//연산이 진행 되면서 왔다간 거리표식을 지워줌.
			while (stack[top].check != 1)
			{
				board[stack[top].y][stack[top].x] = 0;
				stack[top] = stack[0];
				top--;
			}

			continue;
		}


		//조건이 만족하지 않는 이상 전진, 표식을 1을 지도에 남긴다. 
		// 스택에 저장한다.
		 
		max_dist = max(dist, max_dist);//지금까지 거리와 최대 거리와 비교하여 최대거리를 판단

		top++;
		stack[top].x = x + dx[pos];
		stack[top].y = y + dy[pos];
		stack[top].dist = dist + 1;
		stack[top].dPos[pos] = 1;
	}
	
	cout << max_dist;

	return 0;
}


//빙판길 돌 붇이치면 양옆으로 갈 수 있음 
//판 n의 크기는 120을 넘지 않는다. 
//장애물의 개수는 200을 넘지 않는다. 
//장애물 번호 A~Z x좌표는 26을 넘어가지 않는다. 