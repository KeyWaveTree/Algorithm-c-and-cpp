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
	int current_index;
	int left_index, right_index;


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
		
		current_index = root; //���� ������ ���� left right �ڽ� ��ġ�� �ٲ� �� �ִ� ���ɼ��� �ٲ��� �ʰ� �Ȱ��� ��츦 Ȯ���ϱ� ���� ����  
		left_index = root * 2;
		right_index = root * 2 + 1;

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
		
		//�������� �� �� �ִ� ��� 
		//���� root���� * 2+1�� ������ heap_index�� ����� �ʰ� ������ �ڽ��� ���� �ڽ� ���� ũ�� �ڽź��� �� ũ�� �� �� �ִ�.  
		if (right_index <= heap_index && 
			heap_list[root] < heap_list[right_index] && 
			heap_list[left_index] < heap_list[right_index])
		{
			current_index = right_index;
		}
		//������ ���� �������� 
		//����root���� *2�� ������ heap_index�� ����� �ʰ� root�� �����ڽĺ��� ������ �� �� �ִ�. 
		else if (left_index <= heap_index && 
			heap_list[root] < heap_list[left_index])
		{
			current_index = left_index;
		}

		//���� �ٲ��� �ʾҴٸ� �״�� ������ ���� ���Ḧ �Ѵ�.
		if (current_index == root) break; //���� ������ �ε����� root�� ���ٸ� �� �ٲ��� �ʾҴٸ�
		
		//�ڸ��� �ٲ�� �Ѵٸ� �ڸ��� �ٲ۴�. 
		heap_list[0] = heap_list[root];
		heap_list[root] = heap_list[current_index];
		heap_list[current_index] = heap_list[0];

		//���� ������ root�� current_index�� �ٲ۴�.
		root= current_index;

		 
		// ����:
		// ���� �켱������ �� ���� �ø��� �����ε� �켱������ ������ ���� ���� ���� �ִ�. 
		// �Ϻη� ���� ���� ���� �� ���� �÷��� ��Ģ�� ��߳��� �ؼ� ��߳��� �ʴ� �ڸ��� ã�Ƴ��ڴٴ� ���̴�.    
		// �ٲ��� �ʴ� �ٴ� ���� ������ ������ ���ٴ� ���̴�.
		
		//���� ���� ���� �������� ����ϴ� ��Ź�� �ִ�. �̰����� Ư���� ��Ģ�� �־ �׻� ���̰� ���� ������ 
		//������ �켱���� ��´�. ���� ��Ź���� ��Ģ�� �־ �켱������ ���� ������� ���� ������ �ɰ� �״��� �켱������ ���� 2���� 
		//�켱������ ���� ��� �� �����̵�� �ɴ´�.�׷��������� 2�� �翷�� �Ѹ� �Ѹ� �� 4���� ���� ���̴�. 
		//�׷��ٰ� ���ȿ� ���� �켱������ ���� ������� ���� ���̴�.
		//����� �� ���ȿ� �켱������ ���� ���� ����� ���� �������� 
		//��Ģ�� ���� 2��°�� ū �켱������ ���� �ɾƾ� �Ѵ�. 
		//������ �� �������� �����̴� ���� �ʹ� �����Ƽ� �ּ������� �����̰� �ʹٰ� �Ѵٸ� ��� �ؾ� �ϴ°��� ��������

		//���� �� �ڿ� �ִ� ���� �켱������ ���� ����� �� ���� ���� ���� �̸��� a��� �θ��ڴ�.
		//�׷��� ��Ģ�� ���� ���̴�. 
		//�� ���� �ִ� a ���� ���ڸ����� �켱������ ���ؼ� ���� ū �켱������ ���� ���� �켱������ �ڸ��� �ٲ۴�. 
		//a�� �ڸ��� �ٲ��. ������ a�ؿ��� �ڽź��� �� ū �켱�������� �������̴�. 
		//a�� �켱������ �����Ҷ� ���� �������� ��Ģ�� �ּ������� �ٲ۰��̴�. �� �ٲ�� �ൿ�� ���Ѵٸ� ���� ��Ź�� ��Ģ�� ���� ���ٴ� ���̴�.
		
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
		if (bean != 0)
		{
			heap_push(bean);
		}
		else
		{
			cout << heap_pop()<<'\n';
		}
		
		
	}

	//while (true)
	//{
	//	first = heap_pop();
	//	second = heap_pop();


	//	if (first == 0 || second == 0) break;

	//	heap_push(first - second);
	//	cnt++;
	//}

	//cout << cnt;

	return 0;
}