#include<iostream>
#include<algorithm>

using namespace std;

typedef struct table
{
	int number;
	int color;
	int size;
	int max_value;
};

const int MAX_SIZE = ((int)2e+5)+1;//최대 공의 개수

table balls[MAX_SIZE];
int color[MAX_SIZE];
int check[MAX_SIZE];

bool compare(const table& a, const table& b)
{
	return a.size < b.size;
}

bool reset(const table& a, const table &b)
{
	return a.number < b.number;
}

int main()
{
	int i, j=0;// 반복하는 수 
	int n;//현재 공의 개수 
	int c, s;//공의 color와 size
	int colorCount = 0; //컬러의 index
	int all_sum = 0;

	cin >> n;//공의 개수 입력 
	
	for (i = 1; i <= n; i++)
	{
		cin >> c >> s;
		balls[i].number = i+1;
		balls[i].color = c;
		balls[i].size = s;

		//컬러 저장
		color[colorCount++] = balls[i].color;
	}

	//크기 순으로 정렬
	sort(balls + 1, balls + n + 1, compare);
	
	//컬러볼 누적 합
	for (i = 1; i <= n; i++)
	{
		//같은 값은 걸러주기 위해 작성됨 
		//정렬이라서 뒤에 있는 값은 상관 x
		//이전 공의 사이즈가 현재 지정되어 있는 공의 사이즈 보다 작다면 
		while (balls[j].size < balls[i].size) //1번 반복할 용도
		{
			all_sum += balls[j].size;//모든 크기 값을 다 누적한다. 
			check[balls[j].color] += balls[j].size;// 현재 자신이 누적한 색상값을 색상값이 모여져있는곳에 더한다.
			j++;//위치크기를 증가시킨다. 
		}
		//현재 i가 가리키고 있는 공의 최대치는 다 더한값에 색상값을 누적한 결과이다. 
		balls[i].max_value = all_sum - check[balls[i].color];
	}

	//원위치로 되돌리기
	sort(balls + 1, balls + n + 1, reset);

	for (i = 1; i <= n; i++)
	{
		cout << balls[i].max_value << '\n';
	}

	return 0;
}