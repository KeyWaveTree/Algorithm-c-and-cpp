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
	int node;//��� ��ȣ
	int group;// �׷� üũ
	int dist;//��� �Ÿ� Ȯ�� 
};

int matrix[101][101];//�������
int queue[10001];//ť
group_dist arr[101];



int n;//��� 
int m;//����

//int& ���´� ������ ���� 
//����: int a=5;
//int& b = a; - b�� a�� �� 5�� ������ �ִٰ� �ƴ� ���� b�� �ּҰ��� a�� �ּҰ��� ���ٴ� �ǹ� -������ ��Ī 

void bfs(int node, int zone)
{
	int dist[101];
	int check[101] = { 0 };//��� üũ

	int front = -1;
	int rear = 0;

	int start, end;//��� start, end
	int level = 1;//���� �Ÿ� 

	queue[rear] = node; //ť�� start�� ��ġ�� �����Ѵ�.
	arr[node].node = node;//���� ���� ��� ���� ����;
	arr[node].group = zone;//ù��° ��� �׷� ����
	check[node] = 1; //ù��° ��� üũ 

	dist[node] = level;// �ʱ� ���� ����

	while (1)
	{
		if (front == rear) break;// ���� queue�� ����ִٸ� ����

		front++;
		start = queue[front];//���� ��� 
		level = dist[start];//���� �Ÿ� ����
		for (end = 1; end <= n; end++)
		{
			//start���� end�� ���� �ְ� �ѹ��� �湮�� �������� 
			if (matrix[start][end] == 1 && check[end] == 0)
			{
				rear++;//rear ���� �� 
				queue[rear] = end; //����

				check[end] = 1;//��� check 
				dist[end] = level + 1; //üũ �� ��� level �Ÿ� ��� 
				arr[end].group = zone;//�׷� ����
				
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
	int a, b;//�� ����� ���� ���� 
	int cnt = 0;
	int min = 101;
	int min_node = 0;

	cin >> n >> m;
	//���� ������� ���� ���� - ���� ����
	for (i = 0; i < m; i++)
	{
		//���� �Է�
		cin >> a >> b;
		matrix[a][b] = matrix[b][a] = 1;
	}

	//Ʈ�� ���̰� ���� �ּ�ġ �϶� 
	//��� ��忡�� bfs�� ���� �� ���� ���� ����()�� ��ǥ
	for (i = 1; i <= n; i++)
	{
		if (arr[i].group==0)//�湮�� ��尡 �ƴ϶�� ���� ������ �׷�� �ٸ� �׷��̹Ƿ� �׷��� ������ bfs�� ����. 
		{
			cnt++;//�׷� �κ�
			arr[i].group = cnt;
		}
		bfs(i, arr[i].group);//���� ���� �ڽ��� �׷��� ����
	}

	//�׷찣�� ����
	sort(arr + 1, arr + n + 1, [](const group_dist& a, const group_dist& b) {return a.group < b.group; });
	
	//��� �غ� 
	cnt = 1;//�׷��� ���� ���ִ� ����
	cout << arr[n].group << '\n';//��ǥ �� �ο� �� 
	for (i = 1; i <= n+1; i++)
	{
		//���� ���� cnt���� ���� ������ �׷��� �ƴ϶��
		if (cnt != arr[i].group)
		{
			repres.push_back(min_node);//���� �׷� �� ���� level�� ª�� ��� ��ȣ ����
			min = 101;//�ּҰ� ���� �ʱ�ȭ
			cnt++;//�׷� ���� 
		}
		//���� ���� �׷��ȣ�� �°� ������� �׷� �߿��� ���� ���� ������ level�� �۴ٸ� 
		if (cnt == arr[i].group && min > arr[i].dist)
		{
			min_node = arr[i].node;//���� Ž���ϴ� ����� ��ȣ�� �����ϰ�
			min = arr[i].dist;//min�� �ּ� level �Ÿ��� ���� �Ѵ�. 
		}
		
	}
	//����
	sort(repres.begin(), repres.end(), [](const int& a, const int& b) {return a < b; });
	
	//���
	for (auto& value : repres)
	{
		cout << value<<'\n';
	}

	return 0;
}