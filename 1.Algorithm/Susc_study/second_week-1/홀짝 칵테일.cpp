#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	bool f1=false, f2=false, f3=false;
	int max = 1; //���ؾ� ��. 
	scanf("%d%d%d", &a, &b, &c);
	//�ϳ��� Ȧ���� ���Ե�������
	if (a % 2 != 0) 
	{
		max *= a;
		f1 = true;
	}
	
	if (b % 2 != 0) 
	{ 
		max *= b; 
		f2 = true;
	}
	
	if (c % 2 != 0)
	{
		max *= c;
		f3 = true;
	}
	
	if (!f1 && !f2 && !f3)
	{
		max = a * b * c;
	}

	printf("%d", max);
	
	return 0;
}