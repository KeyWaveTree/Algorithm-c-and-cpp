#include<stdio.h>

int get_array_sum(int* a, int size)
{
	int sum = 0;
	for (size-=1; size >= 0; size--) 
	{
		sum += *(a+size);
	}

	return sum;
}

int main()
{
	int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//�����Ϳ��� �迭�� ������ �ּҰ��� :name 
	//�迭�� �ּ��� 0������ �ּҰ���: &name[0] ����.

	printf("%d", get_array_sum(data, 10));
}