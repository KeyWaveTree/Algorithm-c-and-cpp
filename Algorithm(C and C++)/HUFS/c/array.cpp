#include<stdio.h>
#define ARRAY_SIZE 5

//2.
void inputNumbers(int num[], int len); //num[] �迭�� �ּ� ���̴� ���� call by reference�� �ҷ��´�.
double computeAverage(int num[], int len);

int main()
{
	//1. �迭 ��Ұ� �Է��� �ݴ�� ���
	//int number[ARRAY_SIZE], i;

	//for (i = 0; i < 5; i++) 
	//{
	//	scanf("%d", &number[i]);
	//}

	//for (i = ARRAY_SIZE - 1; i >= 0; i--)
	//{
	//	printf("%d ", number[i]);
	//}


	//2. �迭�� �ִ� ��Ұ��� ����� ���϶�.
	//int numbers[ARRAY_SIZE];
	//inputNumbers(numbers, ARRAY_SIZE); //�迭 ������ �־ call by reference�� ��
	//printf("%.3lf", computeAverage(numbers, ARRAY_SIZE));


	//3. two dimensional array
	/*int row, col;
	int arr[ARRAY_SIZE + 1][ARRAY_SIZE + 1] = {0};

	for (int i = 0; i < ARRAY_SIZE + 1; i++)
	{
		for (int j = 0; j < ARRAY_SIZE + 1; j++)
		{
			if (i == j) arr[i][j] = 0;
			else if (j > i) arr[i][j] = 1;
			else if (i > j) arr[i][j] = -1;
		}
	}

	for (int i = 0; i < ARRAY_SIZE + 1; i++)
	{
		for (int j = 0; j < ARRAY_SIZE + 1; j++)
		{
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}

//2
//void inputNumbers(int num[], int len) //num[] �迭�� �ּ� ���̴� ���� call by reference�� �ҷ��´�. ������ �ᵵ ��
//{
//	int i;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &num[i]);
//	}
//}
//
//double computeAverage(int num[], int len)
//{
//	double sum = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		sum += num[i];
//	}
//
//	return sum/(double)len;
//}