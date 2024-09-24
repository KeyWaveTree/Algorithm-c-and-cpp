//�������� ��: 100���� 
//������ ��ġ�� 10������ 
//��ü ���� ���� �� ���� ū ��ġ 2���� �̴´�. 
//2���߿� ���� ���� ��� �� ��ġ�� ���������� ���� 0 �� ������ ������. 
//���� 1���� �ɶ������� ������ Ƚ���� �˾Ƴ��ÿ�. 
//����Ƚ���� ū ��ġ 2���� �̴´ٴ� ���� 1���̶�� �Ѵ�. 

#include<iostream>
#include<vector>

using namespace std;

//�� 
vector<int> heap_list;
int heap_index;

//�ִ� ��
void heap_push(int item)
{
	int copy_index;
	//�� �ε��� ����. 1�������� ���� �����ϱ� ����.  
	heap_index++;
	//���� ����.
	heap_list[heap_index] = item;

	//���� ���� �ε����� heap_index��. 
	//heap_index�� �ڽ��� ������ ���(������) ������ �ǹ������� copy_index�� ����.
	copy_index = heap_index;

	//����
	while (1)
	{
		//���� �ε����� 1�̰ų� �ڽ� ��ġ�� ��Ұ� < �θ� ��ġ�� ��Ұ��� �����Ǹ� ������ �ߴ��Ѵ�.
		if (copy_index == 1 || heap_list[copy_index] <= heap_list[copy_index / 2]) break;
		//���� �ڽ��� ��Ұ��� �θ��� ��Ұ� ���� ũ�� �ٲ۴�. ���� �ڽ��� ��ġ���� �θ��� ��ġ������ �ٲ۴�.
		else if (heap_list[copy_index] > heap_list[copy_index / 2])
		{
			heap_list[0] = heap_list[copy_index];
			heap_list[copy_index] = heap_list[copy_index / 2];
			heap_list[copy_index / 2] = heap_list[0];
			copy_index /= 2;
		}
	}
}

int heap_pop()
{
	int item;
	int root = 1;
	bool left_flag, right_flag;

	//���� ����� ���µ� pop�� �� �� �����Ƿ� 0�� return 
	if (heap_index == 0) return 0;

	//���� [1] ��ġ ����
	item = heap_list[root];
	//�� ������ �� ��带 root���ٰ� ������ �ε��� ����
	heap_list[root] = heap_list[heap_index];
	heap_index--;

	//heapfiy ����
	while (1)
	{
		left_flag = false;
		right_flag = false;
		//���� ������ ������� �ϰų� Ȥ�� ���� �����ϰ� �ִ� ���� 0 �̰ų� �θ�� �ڽ��� ���� ���� �ƴҶ��� 
		if (root * 2 <= heap_index && heap_list[root * 2] > heap_list[root]) left_flag = true;

		if (root * 2 + 1 <= heap_index && heap_list[root * 2 + 1] > heap_list[root]) right_flag = true;

		//right flag�� Ȱ��ȭ �Ǹ� left flag�� Ȱ��ȭ �� �� �ۿ� ���°�? = �ƴϴ�.  
		//right flag�� Ȱ��ȭ�� �Ǹ� �� �迭������ right_child�� �����ϰ� left child�� ���������� �����Ѵٰ� �� �� �ִ°� ������ 
		//heap_list[root * 2] >  heap_list[root]�� ���� �ȵ� �� �ִ�. 
		//�� �̷� ����̴�. 
		/*
			 1
			/ \
		   0   2

		�������� Ȱ��ȭ �� �� ������ ������ Ȱ��ȭ�� ���ϴ� ����̴�.
		*/

		if (left_flag == false && right_flag == false) break;

		//���� �������� �Ѵ� �� �� ������ ���� ū ���� ��ġ�� �ľ��Ѵ�.

		//������ �� ū ��� Ȥ�� ���ʸ� Ȱ��ȭ ������ ��� 
		if ((left_flag && right_flag && heap_list[root * 2] > heap_list[root * 2]) || left_flag)
		{
			heap_list[0] = heap_list[root];
			heap_list[root] = heap_list[root * 2];
			heap_list[root * 2] = heap_list[0];
			root *= 2;
		}
		//�������� �� ū ��� Ȥ�� �����ʸ� Ȱ��ȭ�� �Ǿ����� 
		else if ((left_flag && right_flag && heap_list[root * 2] < heap_list[root * 2]) || right_flag)
		{
			heap_list[0] = heap_list[root];
			heap_list[root] = heap_list[root * 2 + 1];
			heap_list[root * 2 + 1] = heap_list[0];
			root *= 2 + 1;
		}

	}
	return item;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int i;

	int n;//������ ���� 
	int bean;//������ ��ġ 
	int cnt = 0;//���� Ƚ��

	int first, second;

	//�������� �ִ�ġ ����
	heap_list.assign(1000001, 0);

	//������ ���� �Է�
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> bean;
		//�Է��� ������ ��ġ �����ٰ� ����
		//�����ٰ� push

		heap_push(bean);



	}

	while (true)
	{
		first = heap_pop();
		second = heap_pop();


		if (first == 0 || second == 0) break;

		heap_push(first - second);
		cnt++;
	}

	cout << cnt;

	return 0;
}