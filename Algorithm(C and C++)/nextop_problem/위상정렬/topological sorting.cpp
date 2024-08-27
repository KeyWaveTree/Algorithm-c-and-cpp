#include<iostream>
#include<limits> //자료형들의 최대치를 구할 수 있는 클래스가 있기에 가지고옴. 
#include<vector>

using namespace std;

//노드가 가지고 있는 정보
typedef struct node 
{
	//노드 번호
	int id;
	//자신에게 도착해야 하는 노드 개수
	int wait;
	//지금까지 자신에게 온 가중치들 중 최소값 
	int weight;
};

//인접 리스트 
vector<pair<int, int>> adjMatrix[100001];

//노드 갱신 배열 최대 10만개 
node renewal[100001];

//노드 개수 //간선 //가중치
int vertex, edge, weight;

//queue
node queue[300001];
int front, rear;

void bfs();

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	pair<int, int> empty;
	node box = { 0, 0, 0 };
	int i;
	
	//노드의 출발과 끝 
	int start, end;
	//bfs를 시작할 노드 번호
	int first;

	cin >> vertex;//노드개수를 받는다. 
	cin >> edge;//간선의 개수

	//인접 리스트 입력 
	for (i = 0; i < edge; i++)
	{
		cin >> start >> end >> weight;
		
		empty.first = end, empty.second = weight;
		adjMatrix[start].push_back(empty);//인접 리스트 정보 추가

		//지금 현재 start가 
		
		//만약 지금 노드 정보 박스에 이미 누군가와 연결 되어 있으면(이미 만들어 졌다면 )
		if (renewal[end].wait >= 1)
		{
			renewal[end].wait++;
		}
		//지금 노드가 처음 만들어질때 
		else
		{
			box.id = end; //노드 정보(왜 도착지를 노드 정보로 하는가? 자신과 연결되어있는 노드들의 개수를 확인하기 위해서)
			box.wait = 1; //도착노드는 누군가와 연결됬다는 번호 
			box.weight = numeric_limits<int>::max();//노드 가중치를 무한으로 넣는다. 
			renewal[box.id] = box;//배열에 삽입 
		}
	}

	//현재 내가 만든 노드 중 한 번도 생성을 안했을때 queue push
	//노드들을 돌면서 wait가 0이 되면 push 한다. 
	for (i = 1; i <= vertex; i++)
	{
		if (renewal[i].wait == 0)
		{
			rear++;
			renewal[i].id = 1;
			queue[rear] = renewal[i];
		}
	}

	bfs();

	return 0;
}

void bfs()
{
	int end;
	node start;

	while (true)
	{
		if (front == rear) break;
		front++;

		start = queue[front];//출발

		for (auto& end : adjMatrix[start.id])//도착 노드들 
		{
			//end.first - 노드의 도착 번호
			//end.second -노드의 가중치 

			// 도착 노드의 연결 횟수 1 감소
			renewal[end.first].wait--;
			
			//도착노드의 최소거리 갱신
			//만약 도착노드로 오면서 이동한 간선의 비용이 도착노드가 가지고 있는 최소 비용보다 작다면 
			if (renewal[end.first].weight > end.second + start.weight)
			{
				renewal[end.first].weight = end.second + start.weight;
			}

			//만약 도착 노드의 연결 횟수가 0이라면 
			if (renewal[end.first].wait == 0)
			{
				//queue에 지금의 노드를 push 한다. 
				rear++;
				queue[rear] = renewal[end.first];
			}
		}

	}
}
