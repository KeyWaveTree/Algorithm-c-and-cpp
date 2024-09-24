#include<iostream>
#include<vector>

using namespace std;

//adjacency matrix
vector<pair<int, int>> adjMatrix[20001];
//dist �迭�̶�? ������ġ���� �� �� �ִ� �ִ� ��� ��� ��� �迭 
int dist[20001];
//üũ �迭 
int check[20001];

int main()
{
	freopen("input.txt", "r", stdin);

	pair<int, int> empty;
	
	dist[0] = 987654321;

	int i;
	int vertex, edge;//��� , ����
	int init;//���۰� 
	int start, end, weight;//�Է��� ���� ��
	int min_node;
	int min_weight = 0;
	
	//������ ���� v ������ ���� e
	cin >> vertex>> edge;
	
	//���� ���� k 
	cin >> init;
	
	//u -> v weight w
	for (i = 0; i < edge; i++)
	{
		cin >> start >> end>> weight;
		empty.first = end; 
		empty.second = weight;
		adjMatrix[start].push_back(empty); //start-> end
	}
	

	//�� ������ �ּ� �Ÿ� inf������
	for (i = 1; i <= vertex; i++)
	{
		dist[i] = dist[0];
	}
	//���÷� ������ �ҷ��� �ϴµ� 1~6������ �������� �ִٰ� �Ҳ���
	//����� ��� �������� �ѹ��� �ѷ��� ��ȹ�̿���.

	//1������ ���� ����
	//1������� ����ġ�� 0���� �ϰ� ť�� �ִ´�.  
	//start����忡�� �� �� �ִ� �������� Ž���Ѵ�.

	dist[init] = 0 + min_weight;
	check[init] = 1;
	start = init;
	
	for(i =1; i<= vertex-1; i++)
	{

		//min ��� �ʱ�ȭ 
		min_node = 0;

		for (pair<int, int> node : adjMatrix[start])
		{

			if (check[node.first] == 1) continue;
			
			if (node.second + min_weight < dist[node.first])
			{
				dist[node.first] = node.second + min_weight;
			}

			
		}

		//����� ���� ���� ���� ������ dist ��带 �̾ƶ� �� üũ�� �ȵ� ��常
		//min heap�� �̿��ؼ� �����ϴ� ���� ����. 
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
			//������Ŀ��� ���� ���� �����̸� 
			if (adjMatrix[start][end] == 0 || check[end] == 1) continue;

			//���� ��ġ���� Ž���� ������������ ����� dist �迭�� ������ �ִ�. 
			//���ݱ��� ���� ��ġ�� �湮�� ����� ���� �湮�� ����� �ּҶ�� dist �迭�� 
			//������ ����� ���� �Ѵ�. 

			if (adjMatrix[start][end] + min_weight < dist[end])
			{
				dist[end] = adjMatrix[start][end] + min_weight;
			}
			//ã���鼭 ���� ���� �Ÿ��� Ȯ���Ѵ�. 
			//���Ǹ��� üũ�� ���� �ȵ� ���� dist �迭�� �ν� �� �������� �ִٸ� 
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