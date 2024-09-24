//데이터의 양: 100만개 
//원두의 가치는 10만까지 
//전체 원두 개수 중 가장 큰 가치 2개만 뽑는다. 
//2개중에 작은 값을 골라 두 가치를 작은값으로 빼고 0 이 나오면 버린다. 
//원두 1개가 될때까지의 연산한 횟수를 알아내시오. 
//연산횟수는 큰 가치 2개를 뽑는다는 것을 1번이라고 한다. 

#include<iostream>
#include<vector>

using namespace std;

//힙 
vector<int> heap_list;
int heap_index;

//최대 힙
void heap_push(int item)
{
	int copy_index;
	//힙 인덱스 증가. 1번지에서 부터 삽입하기 위함.  
	heap_index++;
	//힙에 삽입.
	heap_list[heap_index] = item;

	//지금 현재 인덱스가 heap_index임. 
	//heap_index는 자신이 삽입한 노드(아이탬) 개수를 의미함으로 copy_index를 만듬.
	copy_index = heap_index;

	//교정
	while (1)
	{
		//만약 인덱스가 1이거나 자신 위치의 요소값 < 부모 위치의 요소값이 만족되면 교정을 중단한다.
		if (copy_index == 1 || heap_list[copy_index] <= heap_list[copy_index / 2]) break;
		//만약 자신의 요소값이 부모의 요소값 보다 크면 바꾼다. 또한 자신의 위치값을 부모의 위치값으로 바꾼다.
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

	//현재 사이즈가 없는데 pop을 할 수 없으므로 0을 return 
	if (heap_index == 0) return 0;

	//지금 [1] 위치 삽입
	item = heap_list[root];
	//맨 마지막 힙 노드를 root에다가 삽입후 인덱스 감소
	heap_list[root] = heap_list[heap_index];
	heap_index--;

	//heapfiy 연산
	while (1)
	{
		left_flag = false;
		right_flag = false;
		//지금 범위를 벗어날려고 하거나 혹은 지금 지정하고 있는 값이 0 이거나 부모와 자식이 같은 값이 아닐때만 
		if (root * 2 <= heap_index && heap_list[root * 2] > heap_list[root]) left_flag = true;

		if (root * 2 + 1 <= heap_index && heap_list[root * 2 + 1] > heap_list[root]) right_flag = true;

		//right flag가 활성화 되면 left flag도 활성화 될 수 밖에 없는가? = 아니다.  
		//right flag가 활성화가 되면 힙 배열상으로 right_child가 존재하고 left child도 마찬가지로 존재한다고만 할 수 있는것 뿐이지 
		//heap_list[root * 2] >  heap_list[root]이 만족 안될 수 있다. 
		//즉 이런 경우이다. 
		/*
			 1
			/ \
		   0   2

		오른쪽은 활성화 할 수 있지만 왼쪽은 활성화를 못하는 경우이다.
		*/

		if (left_flag == false && right_flag == false) break;

		//왼쪽 오른쪽이 둘다 할 수 있을때 가장 큰 값의 위치를 파악한다.

		//왼쪽이 더 큰 경우 혹은 왼쪽만 활성화 되있을 경우 
		if ((left_flag && right_flag && heap_list[root * 2] > heap_list[root * 2]) || left_flag)
		{
			heap_list[0] = heap_list[root];
			heap_list[root] = heap_list[root * 2];
			heap_list[root * 2] = heap_list[0];
			root *= 2;
		}
		//오른쪽이 더 큰 경우 혹은 오른쪽만 활성화가 되었을때 
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

	int n;//원두의 개수 
	int bean;//원두의 가치 
	int cnt = 0;//연산 횟수

	int first, second;

	//데이터의 최대치 지정
	heap_list.assign(1000001, 0);

	//원두의 개수 입력
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> bean;
		//입력한 원두의 가치 힙에다가 삽입
		//힙에다가 push

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