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
	//why? *i *f�� �ȵǰ� i, f�� reperence�� �ɱ�?
	// *i, *f�� reperence�� �ɶ� �������� ������ �ǰ� �ȴ�. 
	// ó�� ���𶧿� �Լ� �ּҷ� �����Ҷ� �׷��� ���� pointer�� �ȵȴ�. 

	printf("%d\n%f", i, f);
}