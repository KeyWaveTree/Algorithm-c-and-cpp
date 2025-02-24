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
	int current_index;
	int left_index, right_index;


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
		
		current_index = root; //현재 지정한 값이 left right 자식 위치로 바뀔 수 있는 가능성과 바뀌지 않고 똑같은 경우를 확인하기 위한 변수  
		left_index = root * 2;
		right_index = root * 2 + 1;

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
		
		//오른쪽을 갈 수 있는 경우 
		//지금 root에서 * 2+1를 했을때 heap_index에 벗어나지 않고 오른쪽 자식이 왼쪽 자식 보다 크고 자신보다 더 크면 할 수 있다.  
		if (right_index <= heap_index && 
			heap_list[root] < heap_list[right_index] && 
			heap_list[left_index] < heap_list[right_index])
		{
			current_index = right_index;
		}
		//왼쪽을 갈수 있을경우는 
		//지금root에서 *2를 했을때 heap_index에 벗어나지 않고 root가 왼쪽자식보다 작을때 할 수 있다. 
		else if (left_index <= heap_index && 
			heap_list[root] < heap_list[left_index])
		{
			current_index = left_index;
		}

		//만약 바뀌지 않았다면 그대로 힙교정 연산 종료를 한다.
		if (current_index == root) break; //지금 지정한 인덱스와 root와 같다면 즉 바뀌지 않았다면
		
		//자리를 바꿔야 한다면 자리를 바꾼다. 
		heap_list[0] = heap_list[root];
		heap_list[root] = heap_list[current_index];
		heap_list[current_index] = heap_list[0];

		//지금 지정한 root를 current_index로 바꾼다.
		root= current_index;

		 
		// 이유:
		// 힙은 우선순위를 맨 위에 올리는 구조인데 우선순위가 높으면 높을 수록 위에 있다. 
		// 일부러 가장 작은 값을 맨 위로 올려서 규칙을 어긋나게 해서 어긋나지 않는 자리를 찾아내겠다는 것이다.    
		// 바뀌지 않는 다는 뜻은 구조에 문제가 없다는 뜻이다.
		
		//예를 들어보자 집에 가족끼리 사용하는 식탁이 있다. 이가족은 특별한 규칙이 있어서 항상 나이가 많은 순으로 
		//선택할 우선권을 얻는다. 가족 식탁에도 규칙이 있어서 우선순위가 높은 사람부터 가장 가운대로 앉고 그다음 우선순위가 높은 2명이 
		//우선순위가 높은 사람 양 옆사이드로 앉는다.그런다음에는 2명 양옆에 한명 한명씩 총 4명을 앉을 것이다. 
		//그러다가 집안에 가장 우선순위가 작은 사람까지 앉을 것이다.
		//어느날 이 집안에 우선순위가 가장 높은 사람이 집에 없다하자 
		//규칙을 따라 2번째로 큰 우선순위가 먼저 앉아야 한다. 
		//하지만 이 가족들은 움직이는 것이 너무 귀찮아서 최소한으로 움직이고 싶다고 한다면 어떻게 해야 하는가는 예제에서

		//먼저 맨 뒤에 있는 작은 우선순위를 가진 사람이 맨 위로 간다 하자 이름을 a라고 부르겠다.
		//그러면 규칙이 깨질 것이다. 
		//맨 위에 있는 a 기준 옆자리들은 우선순위를 비교해서 가장 큰 우선순위와 가장 작은 우선순위의 자리를 바꾼다. 
		//a는 자리가 바뀐다. 하지만 a밑에는 자신보다 더 큰 우선순위들이 있을것이다. 
		//a의 우선순위가 만족할때 까지 내려가면 규칙을 최소한으로 바꾼것이다. 즉 바뀌는 행동을 안한다면 가족 식탁의 규칙도 문제 없다는 뜻이다.
		
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