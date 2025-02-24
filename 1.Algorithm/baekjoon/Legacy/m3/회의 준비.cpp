#include<iostream>
#include<algorithm>
#include<vector>
/*
in : 
6
4
6 3
1 6
6 5
3 4

6
3
1 6
6 5
3 4

answer:
2
2
3 or 6

3
2
3 (or 4)
6

*/
using namespace std;

typedef struct group_dist
{
	int node;//노드 번호
	int group;// 그룹 체크
	int dist;//노드 거리 확인 
};

int matrix[101][101];//인접행렬
int queue[10001];//큐
group_dist arr[101];



int n;//노드 
int m;//간선

//int& 형태는 참조자 형태 
//예시: int a=5;
//int& b = a; - b는 a의 값 5를 가지고 있다가 아닌 변수 b의 주소값은 a의 주소값과 같다는 의미 -일종의 별칭 

void bfs(int node, int zone)
{
	int dist[101];
	int check[101] = { 0 };//노드 체크

	int front = -1;
	int rear = 0;

	int start, end;//노드 start, end
	int level = 1;//현재 거리 

	queue[rear] = node; //큐에 start할 위치를 지정한다.
	arr[node].node = node;//지금 현재 노드 정보 저장;
	arr[node].group = zone;//첫번째 노드 그룹 지정
	check[node] = 1; //첫번째 노드 체크 

	dist[node] = level;// 초기 레벨 설정

	while (1)
	{
		if (front == rear) break;// 만약 queue가 비어있다면 종료

		front++;
		start = queue[front];//시작 노드 
		level = dist[start];//현재 거리 저장
		for (end = 1; end <= n; end++)
		{
			//start에서 end로 갈수 있고 한번도 방문을 안했을때 
			if (matrix[start][end] == 1 && check[end] == 0)
			{
				rear++;//rear 증가 후 
				queue[rear] = end; //삽입

				check[end] = 1;//노드 check 
				dist[end] = level + 1; //체크 후 노드 level 거리 계산 
				arr[end].group = zone;//그룹 지정
				
			}
		}
	}
	arr[node].dist = level;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	vector<int> repres;
	int i;
	int a, b;//두 노드의 관계 생성 
	int cnt = 0;
	int min = 101;
	int min_node = 0;

	cin >> n >> m;
	//먼저 인접행렬 부터 생성 - 간선 지정
	for (i = 0; i < m; i++)
	{
		//관계 입력
		cin >> a >> b;
		matrix[a][b] = matrix[b][a] = 1;
	}

	//트리 높이가 가장 최소치 일때 
	//모든 노드에서 bfs를 돌린 후 가장 적은 높이()가 대표
	for (i = 1; i <= n; i++)
	{
		if (arr[i].group==0)//방문한 노드가 아니라면 현재 설정된 그룹과 다른 그룹이므로 그룹을 증가후 bfs를 돈다. 
		{
			cnt++;//그룹 부분
			arr[i].group = cnt;
		}
		bfs(i, arr[i].group);//시작 노드와 자신의 그룹을 지정
	}

	//그룹간의 정렬
	sort(arr + 1, arr + n + 1, [](const group_dist& a, const group_dist& b) {return a.group < b.group; });
	
	//출력 준비 
	cnt = 1;//그룹을 관리 해주는 변수
	cout << arr[n].group << '\n';//대표 총 인원 수 
	for (i = 1; i <= n+1; i++)
	{
		//만약 지금 cnt값이 지금 지정한 그룹이 아니라면
		if (cnt != arr[i].group)
		{
			repres.push_back(min_node);//이전 그룹 중 가장 level이 짧은 노드 번호 저장
			min = 101;//최소값 갱신 초기화
			cnt++;//그룹 증가 
		}
		//만약 지금 그룹번호가 맞고 현재까지 그룹 중에서 가장 작은 값보다 level이 작다면 
		if (cnt == arr[i].group && min > arr[i].dist)
		{
			min_node = arr[i].node;//지금 탐색하는 노드의 번호를 저장하고
			min = arr[i].dist;//min을 최소 level 거리로 정의 한다. 
		}
		
	}
	//정렬
	sort(repres.begin(), repres.end(), [](const int& a, const int& b) {return a < b; });
	
	//출력
	for (auto& value : repres)
	{
		cout << value<<'\n';
	}

	return 0;
}