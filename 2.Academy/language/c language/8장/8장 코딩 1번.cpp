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
	//포인터에서 배열의 변수명 주소값과 :name 
	//배열의 주소의 0번지의 주소값은: &name[0] 같다.

	printf("%d", get_array_sum(data, 10));
}