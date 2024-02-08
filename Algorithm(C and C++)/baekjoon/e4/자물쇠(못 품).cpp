#include<iostream>

using namespace std;

//0번째 사용하기 위해서 1칸을 기준으로 값을 순환시킬 생각
int chain[502];
//bool check[501];// true-포인트 false-순환 :p, q 찾기 용

int main()
{
	freopen("input.txt", "r", stdin);
	int n; //사이즈 
	int i;

	//reverse 포인터 
	bool sw = false;
	int p, q;

	//입력 
	scanf_s("%d", &n);
	p = 1, q = n;
	
	
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &chain[i]);
	}

	//끝과 끝을 반영하도록
	chain[0] = chain[n];
	chain[n + 1] = chain[1];
	
	//check 부분
	for (i = 1; i <= n; i++)
	{
		//p, q 위치 구하기 - p, q 기준은 정답이 될 때 위치 기준으로 한다.
		//앞에 인접된 숫자가 1 차이가 나거나 
		//뒤에 있는 숫자가 차이가 벌어지는 대신 앞에 있는 숫자가 인접된 숫자라면 
		//연결성이 존재된 부분 수열이다.

		//스위치가 false(계속 인접된 숫자)인 상태에서 현재 숫자가 앞 수와 인접할때 현재 위치가 p이다. 
		if ((chain[i] - chain[i - 1] == 1 ||chain[i-1] - chain[i] == n-1) && sw == false )
		{
			sw = true;
			p = i;
			continue;
		}
		//현재 숫자 뒤 인접된 숫자이고 자신은 앞수는 자신과 인접하지 않을때 현재 -1 위치가 q이다.   
		if ((chain[i+1]- chain[i] ==1 || chain[i-1]-chain[i]==n-1) && chain[i] - chain[i - 1] != 1 && sw == true )
		{
			q = i-1;
			break;
		}
		/*if (!(chain[i] - chain[i - 1] == 1 || chain[i+1] - chain[i] == 1))
		{
			check[i] = true;
		}*/

	}

	//확인 함 
	//printf("%d %d\n", chain[p], p);
	//printf("%d %d\n", chain[q], q);

	//둘중 작은 위치을 p, 큰 위치을 q라고 한다. 
	//포인트 위치가 p(왼쪽포인트)값 < q(오른쪽 포인트)값 놓여져 있을때 일때 
	if (chain[p] < chain[q])
	{

	}

	// 포인트 위치가 p(왼쪽포인트)값 > q(오른쪽 포인트)값 놓여져 있을때 일때

	return 0;
}

/*

typedef struct point
{
	int value;
	int index;
};

bool compare(const point& a,const  point& b)
{
	return a.index< b.index;
}


int main()
{
	freopen("input.txt", "r", stdin);
	int n; //사이즈 
	int i; 

	//reverse 포인터 
	point p_or_q[2] = {(0,0)};
	point p, q;
	int cnt = 0;
	
	//옮기는 순서 
	int k1, k2;
	
	//입력 
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &chain[i]);
	}

	//p, q 위치 구하기 -- p, q 기준은 정답이 될 때 위치 기준으로 한다.
	//1을 먼저 찾고 1위치에서 부터 순서대로 본다. (기준점)
	//p, q를 구하는 방법 1씩 차이 n-1 차이 
	//항상 찾을 때 p<q(위치는)
	for (i = 0; i <= n++1; i++)
	{
		//차이가 1씩나거나 n-1차이 나지 않는경우 
		if (!(abs(chain[i%n] - chain[(i+1)%n]) != 1 && abs(chain[i%n] - chain[(i + 1)%n]) != (n - 1)))
		{
			//p 혹은 q인 값을 넣는다. 
			p_or_q[cnt].value = chain[i];
			p_or_q[cnt].index = i;
			//위치도 넣는다. 
			cnt++;
		}
		if (cnt == 2) break;
	}
	
	//둘중 작은 위치을 p, 큰 위치을 q라고 한다. 
	p = min(p_or_q[0], p_or_q[1], compare);
	q = max(p_or_q[0], p_or_q[1], compare);
	printf("%d %d", p.value, q.value);
	//포인트 위치가 p(왼쪽포인트) < q(오른쪽 포인트) 놓여져 있을때 일때 

	// 포인트 위치가 p(왼쪽포인트) > q(오른쪽 포인트) 놓여져 있을때 일때
	
	return 0;

}


10
10 3 4 5 6 7 8 9 2 1 10 3 

   f f f f f f f t t t
*/