#include<stdio.h>

int main()
{
	int i;//반복할 변수 
	int n;//입력변수 

	int max = 0; //최댓치가 들어갈 변수 max
	int loca = 0; //최댓치의 위치 변수 
	for (i = 1; i <= 9; i++) //입력받을 횟수 및 순서 
	{
		scanf("%d", &n);
		//만약 지금 입력한값이 max값보다 크다면  
		if (n > max)
		{
			max = n;//최댓값 갱신
			loca = i;//최댓값 위치 갱신 - 
		}
	}

	printf("%d\n%d", max, loca);

	return 0;

}