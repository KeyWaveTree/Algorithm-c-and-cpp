#include<iostream>
#include<limits> //�ڷ������� �ִ�ġ�� ���� �� �ִ� Ŭ������ �ֱ⿡ �������. 
#include<vector>

using namespace std;

//��尡 ������ �ִ� ����
typedef struct node 
{
	//��� ��ȣ
	int id;
	//�ڽſ��� �����ؾ� �ϴ� ��� ����
	int wait;
	//���ݱ��� �ڽſ��� �� ����ġ�� �� �ּҰ� 
	int weight;
};

//���� ����Ʈ 
vector<pair<int, int>> adjMatrix[100001];

//��� ���� �迭 �ִ� 10���� 
node renewal[100001];

//��� ���� //���� //����ġ
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
	
	//����� ��߰� �� 
	int start, end;
	//bfs�� ������ ��� ��ȣ
	int first;

	cin >> vertex;//��尳���� �޴´�. 
	cin >> edge;//������ ����

	//���� ����Ʈ �Է� 
	for (i = 0; i < edge; i++)
	{
		cin >> start >> end >> weight;
		
		empty.first = end, empty.second = weight;
		adjMatrix[start].push_back(empty);//���� ����Ʈ ���� �߰�

		//���� ���� start�� 
		
		//���� ���� ��� ���� �ڽ��� �̹� �������� ���� �Ǿ� ������(�̹� ����� ���ٸ� )
		if (renewal[end].wait >= 1)
		{
			renewal[end].wait++;
		}
		//���� ��尡 ó�� ��������� 
		else
		{
			box.id = end; //��� ����(�� �������� ��� ������ �ϴ°�? �ڽŰ� ����Ǿ��ִ� ������ ������ Ȯ���ϱ� ���ؼ�)
			box.wait = 1; //�������� �������� �����ٴ� ��ȣ 
			box.weight = numeric_limits<int>::max();//��� ����ġ�� �������� �ִ´�. 
			renewal[box.id] = box;//�迭�� ���� 
		}
	}

	//���� ���� ���� ��� �� �� ���� ������ �������� queue push
	//������ ���鼭 wait�� 0�� �Ǹ� push �Ѵ�. 
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

		start = queue[front];//���

		for (auto& end : adjMatrix[start.id])//���� ���� 
		{
			//end.first - ����� ���� ��ȣ
			//end.second -����� ����ġ 

			// ���� ����� ���� Ƚ�� 1 ����
			renewal[end.first].wait--;
			
			//��������� �ּҰŸ� ����
			//���� �������� ���鼭 �̵��� ������ ����� ������尡 ������ �ִ� �ּ� ��뺸�� �۴ٸ� 
			if (renewal[end.first].weight > end.second + start.weight)
			{
				renewal[end.first].weight = end.second + start.weight;
			}

			//���� ���� ����� ���� Ƚ���� 0�̶�� 
			if (renewal[end.first].wait == 0)
			{
				//queue�� ������ ��带 push �Ѵ�. 
				rear++;
				queue[rear] = renewal[end.first];
			}
		}

	}
}
