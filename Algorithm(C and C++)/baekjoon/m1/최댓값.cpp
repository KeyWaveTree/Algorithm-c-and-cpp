#include<iostream>

using namespace std;

int main()
{
	//9*9 행렬에서 인덱스 값을 편하게 사용하기 위해 10*10
	int arr[10][10];
	int i, j;
	int max=-1;//최대값은 0미만이므로 -1
	int max_i = 0;//최대값을 가지고 있는 행 위치 
	int max_j = 0;//최대값을 가지고 있는 열 위치

	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			//입력
			cin >> arr[i][j];

			//입력 받은 순간 최대값과 비교 
			if (max < arr[i][j])
			{
				//더크면 필요한 정보 저장
				max = arr[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d", max_i, max_j);

	return 0;
}