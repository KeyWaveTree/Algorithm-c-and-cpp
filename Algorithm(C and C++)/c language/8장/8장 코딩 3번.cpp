#include<stdio.h>
#define PI 3.141592

void na(float value, int *i_part, float *f_part)
{
	*i_part = (int)value;
	*f_part = value-*i_part;
}

int main()
{
	float pi = PI;
	int i = 0;
	float f = 0;
	na(pi, &i, &f);
	//why? *i *f는 안되고 i, f는 reperence가 될까?
	// *i, *f는 reperence로 될때 이중으로 참조가 되게 된다. 
	// 처음 선언때와 함수 주소로 참조할때 그래서 단일 pointer는 안된다. 

	printf("%d\n%f", i, f);
}