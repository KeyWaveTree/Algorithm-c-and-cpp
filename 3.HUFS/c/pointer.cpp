#include<stdio.h>

//5. �迭 ��� ���ϱ�
void multiplay4(int* p, int len);

int main()
{
	//1. �����Ϳ� ���Ͽ�
	//char* pc = NULL; //64byte �������� 8byte�̴�. 
	//char c = 'A'; //������ ������ ����ų���� type���� ���ƾ� �Ѵ�.

	//pc = &c;
	////pc ������ ������ ������ �ּҸ� �����ϰ�
	////&pc pc ������ ������ �ּҸ� ��Ÿ����.  ���� pc�� &pc�� �ٸ���. 
	//
	//printf("%p %c\n", pc, c); //c�� �ּ�, c�� �����ϴ� ��
	//printf("%p %p\n", &pc, &c); //pc ������ ������ ����Ű�� �� �տ� �ִ� �ּҸ� �ش�.(�迭�� ��������), c�� �ּ� 
	//printf("%d %d\n", sizeof(pc), sizeof(c));//64bit ���� �������� ������� 8�̰�, ������ ����Ʈ ũ�� 1�� ��Ÿ����. 

	//2. �����Ϳ� ���Ͽ� 2
	//int* pn = NULL;
	//int n = 3;

	//pn = &n;

	//printf("%p %d\n", pn, n);
	//printf("%p %p\n", &pn, &n);
	//printf("%d %d\n", sizeof(&pn), sizeof(&n)); //�ּ��� ������� ������ �ּҰ� �Ҵ��ϴ� 8byte�� ����
	//printf("%d %d\n", sizeof(pn), sizeof(n));

	//3.���

	//int a, b, c;
	//int* p = NULL, * q = NULL, * r = NULL;

	//a = 6, b =10;

	//// *p=6, *q=8 *r=8
	//p = &b, q = p, r = &c;
	//p = &a, * q = 8, * r = *p;
	//*r = a + *q + *&c; //6+8+6 20
	//printf("%d %d %d", a, b, c); //6, 8 20

	//4. ���
	/*int a, b, c;
	int* pa = NULL, * pb = NULL, * pc = NULL;

	pa = &a;
	pb = &b;
	pc = &c;

	*pa = 10, *pb = 20;
	*pc = *pa + *pb;

	printf("%d %d %d", a, b, c); ///10 20 30*/

	//5. ���� ������ 
	//char c = 'a';//16 
	//char* p = &c;//8
	//char** pp = &p;//0

	//printf("%p %p\n", p, pp);//c�� �ּ�, p�� �ּ� : 16, 8 
	//printf("%p %p\n", &p, &pp);//p�� �ּҰ�, pp�� �ּҰ� : 8, 0
	//printf("%d\n", sizeof(p)); //8
	//printf("%d\n", sizeof(pp));//8

	////�����͸� ������ byte�� ������ 
	////�Ϲ����� ������ �ּҴ� type�� byte���� �޶�����. 
	//printf("%p %p\n", p, p+1);//c�� �ּ�, c�� �ּ� + sizeof(&c) //16, 24 - Ʋ�� 16 17 
	//printf("%p %p\n", pp, pp+1);//p�� �ּҰ�, p�� �ּҰ� +sizeof(p) == c�� �ּҰ� //8, 16
	//printf("%p %p\n", &c, &c+1);//c���ּ�, c�� �ּ� ��ġ +sizeof(c) //16, 24 -Ʋ�� 16 17
	//printf("%p %p\n", &p, &p + 1);//p�� ��ġ �ּ�, p�� ��ġ �ּ�+sizeof(p) //8, 16
	//printf("%p %p\n", &pp, &pp + 1);//pp�� ��ġ �ּ�, pp�� ��ġ �ּ� +sizeof(pp)0, 8
	
	//6. �迭 ��ҿ� 4�� ���ϱ�
	/*int a[5] = { 5,4,3,2,1 };
	multiplay4(a, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}*/
	return 0;
}
/* 6��
void multiplay4(int* p, int len)
{
	int i;
	for (i=0; i < len; i++)
	{
		p[i] *= 4;
	}
}*/