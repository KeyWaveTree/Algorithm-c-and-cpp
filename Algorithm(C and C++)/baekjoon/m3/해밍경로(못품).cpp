#include<iostream>
#include<algorithm>

using namespace std;

typedef struct bitCode
{
	int bit_value; //xor 개산 할때 사용
	int bit_count; //이진 탐색 할때 사용
	int index; //출력 할때 사용
};

bitCode arr[100001];
bitCode sorts[100001];
bitCode queue[1001];
int bitdir[100000];

bool compare(const bitCode& a, const bitCode& b)
{
	return a.bit_value < b.bit_value;
}

int main()
{
	//해밍 경로 
	//입력받은 비트를 저장 

	freopen("input.txt", "r", stdin);
	int n, k;
	int i, j;

	int m, h;
	
	int bit_count=0;
	int find_bit_cnt = 0;
	//bit 수를 받기 위해 문자열 사용 -> int 
	char bit[32] = { '\0' };

	//bit값의 개수, bit값의 길이 
	scanf("%d %d", &n, &k);

	//2 ** 30이므로 간당간당하게 bit수는 부족하지 않음. 
	for (i = 1; i <= n; i++) //n개의 bit 값 
	{
		
		scanf("%s", bit);
		arr[i].index = i;
		sorts[i].index = i;
		bit_count = 0;
		for (j = 0; j < k; j++) //bit 계산
		{	//문자가 1 인것을 사용하기 위해서 pow 사용(log n)
			if (bit[j] == '1')
			{
				arr[i].bit_value += (int)pow(2, j);//지금 현재 자리 비트가 1이면 계산한다.
				bit_count++;
			}
		}
		sorts[i].bit_value = arr[i].bit_value;
		//bit에서 1이 표시가 된 개수를 넣는다. 
		arr[i].bit_count = bit_count;
	}

	// 정렬 
	sort(sorts + 1, sorts + n + 1, compare);

	scanf("%d", &m);


	//m번 반복

	for (i = 0; i < m; i++)
	{
		//1~h번째 까지 가는 해밍 경로 
		scanf("%d", &h);

			//내가 가야 하는 최소 횟수 = 답 개수  - popcnt를 하여 bit개수를 새준다. 
			find_bit_cnt = __popcnt(arr[1].bit_value ^ arr[n].bit_value);
			bit_count = arr[1].bit_value ^ arr[n].bit_value;

	
	}

	//경로 확인을 위해 
	//해밍경로 모든 인접한 코드 차이가 1인 경로 
	//비트 수 가 1bit 씩 차이가 나므로 xor 연산을 하여 찾는다. - 근데 xor를 굳이 해야 할까? 안해도 될것같은데 - 해야 함
	//하지만 브루트 포스로 하면 n^2이 나오므로 
	//정렬한 배열에서 이진 탐색 (bit가 차이가 하나가 나오는 값을) 
	//나오면 저장  
	//안나오면 -1 출력 및 종료 
	//만약 이진 탐색 했는데 값이 안나옴. 그럼 같은 bit 수 찾아 - 근데 이건 성립 될 수 없다. - 무조건 -1 출력  
	//왜냐면 같은 비트 수 를 찾는다 해도 비트 수가 같고 0과 1의 개수가 1개 다르기 때문에 무조건 0과 1이 차이가 난다. 

	//만약 종료가 되지 않았다면 저장한 위치 출력 
}