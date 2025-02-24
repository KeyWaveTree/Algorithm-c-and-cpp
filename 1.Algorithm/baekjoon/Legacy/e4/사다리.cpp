#include<iostream>

using namespace std;

typedef struct bar
{
	int i;
	int d;
};

bar arr[3000];

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	int l;
	int i, d;
	int temp = 0;
	int max = 0;
	//층 수(높이), 층 길이(각 층마다의 칸 갯수) 
	scanf("%d %d", &n, &l);
	for (int k = 0; k < n; k++)
	{	
		//막대기 칸 길이, 왼쪽 끝 혹은 오른쪽 끝 부터 시작할 것인가?
		scanf("%d %d", &arr[k].i, &arr[k].d);
		
		//목적: 각 왼쪽 오른쪽 막대기 칸의 안 겹쳐진 최대 길이는 얼마인가?
		
		//막대기가 한 개 뿐이 없고 또는 인접해 있는 막대기의 방향이 똑 같을때 비교할 필요 없다.  
		if (k == 0 || (k!=0 && arr[k].d == arr[k - 1].d)) continue;
		temp = (l - (arr[k].i + arr[k - 1].i))/2; //높이로 인접해 있고 방향이 다른 막대기들의 겹쳐지지 않은 길이를 temp에다가 저장해라  
		if (temp <= 0) continue;//겹쳐지지 않은 길이가 0이하라면 언제나 겹쳐있으므로 연산할 필요 없다. 
		if (max < temp) max = temp; //안 겹쳐진 최대길이를 max에다가 저장 함. 이게 최초 시간이다. 
	}

	printf("%d", max);//최소시간 출력

	return 0;
}