#include<iostream>
#include<vector>

using namespace std;

//adjacency matrix
vector<pair<int, int>> adjMatrix[20001];
//dist 배열이란? 시작위치에서 갈 수 있는 최단 경로 비용 기록 배열 
int dist[20001];
//체크 배열 
int check[20001];

int main()
{
	freopen("input.txt", "r", stdin);

	pair<int, int> empty;
	
	dist[0] = 987654321;

	int i;
	int vertex, edge;//노드 , 간선
	int init;//시작값 
	int start, end, weight;//입력의 시작 끝
	int min_node;
	int min_weight = 0;
	
	//정점의 개수 v 간선의 개수 e
	cin >> vertex>> edge;
	
	//시작 정점 k 
	cin >> init;
	
	//u -> v weight w
	for (i = 0; i < edge; i++)
	{
		cin >> start >> end>> weight;
		empty.first = end; 
		empty.second = weight;
		adjMatrix[start].push_back(empty); //start-> end
	}
	

	//각 정점의 최소 거리 inf값으로
	for (i = 1; i <= vertex; i++)
	{
		dist[i] = dist[0];
	}
	//예시로 여행을 할려고 하는데 1~6번까지 관광지가 있다고 할께요
	//저희는 모든 관광지를 한번씩 둘러볼 계획이에요.

	//1번에서 부터 시작
	//1번노드의 가중치를 0으로 하고 큐에 넣는다.  
	//start번노드에서 갈 수 있는 목적지를 탐사한다.

	dist[init] = 0 + min_weight;
	check[init] = 1;
	start = init;
	
	for(i =1; i<= vertex-1; i++)
	{

		//min 노드 초기화 
		min_node = 0;

		for (pair<int, int> node : adjMatrix[start])
		{

			if (check[node.first] == 1) continue;
			
			if (node.second + min_weight < dist[node.first])
			{
				dist[node.first] = node.second + min_weight;
			}

			
		}

		//노드중 가장 작은 값을 가지는 dist 노드를 뽑아라 단 체크가 안된 노드만
		//min heap을 이용해서 구현하는 것이 좋음. 
		for (int j = 1; j <= vertex; j++)
		{
			if (check[j] == 0 && dist[j] < dist[min_node]) min_node = j;
		}
		if (min_node == 0) break;

		min_weight = dist[min_node];
		check[min_node] = 1;
		start = min_node;

		/*
		for (end = 1; end <= vertex; end++)
		{
			//인접행렬에서 갈수 없는 방향이면 
			if (adjMatrix[start][end] == 0 || check[end] == 1) continue;

			//시작 위치에서 탐사한 목적지까지의 비용을 dist 배열에 조건이 있다. 
			//지금까지 현재 위치를 방문한 경로중 지금 방문한 비용이 최소라면 dist 배열에 
			//지금의 비용을 삽입 한다. 

			if (adjMatrix[start][end] + min_weight < dist[end])
			{
				dist[end] = adjMatrix[start][end] + min_weight;
			}
			//찾으면서 가장 작은 거리도 확인한다. 
			//조건만약 체크에 포함 안된 노드와 dist 배열에 훨신 더 작은값이 있다면 
			if (check[end] == 0 && dist[end] < min_node) min_node = min(min_node, dist[end]);
		}

		if (min_node == numeric_limits<int>::max()) break;

		min_weight += dist[min_node];
		check[min_node] = 1;
		start = min_node;
		*/
	}

	for (i = 1; i <= vertex; i++)
	{
		if (dist[i] == dist[0])
		{
			cout << "INF" << '\n';
		}
		else 
		{
			cout << dist[i] << '\n';
		}
	}

	return 0;
}