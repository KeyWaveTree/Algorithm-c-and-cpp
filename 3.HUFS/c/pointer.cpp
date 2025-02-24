#include<stdio.h>

//5. 배열 요소 곱하기
void multiplay4(int* p, int len);

int main()
{
	//1. 포인터에 관하여
	//char* pc = NULL; //64byte 기준으로 8byte이다. 
	//char c = 'A'; //포인터 변수를 가리킬려면 type형이 같아야 한다.

	//pc = &c;
	////pc 포인터 변수는 변수의 주소만 저장하고
	////&pc pc 포인터 변수의 주소를 나타낸다.  따라서 pc와 &pc는 다르다. 
	//
	//printf("%p %c\n", pc, c); //c의 주소, c가 저장하는 값
	//printf("%p %p\n", &pc, &c); //pc 포인터 변수를 가리키면 맨 앞에 있는 주소를 준다.(배열도 마찬가지), c의 주소 
	//printf("%d %d\n", sizeof(pc), sizeof(c));//64bit 기준 포인터의 사이즈는 8이고, 변수의 바이트 크기 1을 나타낸다. 

	//2. 포인터에 관하여 2
	//int* pn = NULL;
	//int n = 3;

	//pn = &n;

	//printf("%p %d\n", pn, n);
	//printf("%p %p\n", &pn, &n);
	//printf("%d %d\n", sizeof(&pn), sizeof(&n)); //주소의 사이즈는 포인터 주소값 할당하는 8byte와 같음
	//printf("%d %d\n", sizeof(pn), sizeof(n));

	//3.계산

	//int a, b, c;
	//int* p = NULL, * q = NULL, * r = NULL;

	//a = 6, b =10;

	//// *p=6, *q=8 *r=8
	//p = &b, q = p, r = &c;
	//p = &a, * q = 8, * r = *p;
	//*r = a + *q + *&c; //6+8+6 20
	//printf("%d %d %d", a, b, c); //6, 8 20

	//4. 계산
	/*int a, b, c;
	int* pa = NULL, * pb = NULL, * pc = NULL;

	pa = &a;
	pb = &b;
	pc = &c;

	*pa = 10, *pb = 20;
	*pc = *pa + *pb;

	printf("%d %d %d", a, b, c); ///10 20 30*/

	//5. 이중 포인터 
	//char c = 'a';//16 
	//char* p = &c;//8
	//char** pp = &p;//0

	//printf("%p %p\n", p, pp);//c의 주소, p의 주소 : 16, 8 
	//printf("%p %p\n", &p, &pp);//p의 주소값, pp의 주소값 : 8, 0
	//printf("%d\n", sizeof(p)); //8
	//printf("%d\n", sizeof(pp));//8

	////포인터만 고정된 byte를 가지고 
	////일반적인 변수의 주소는 type의 byte마다 달라진다. 
	//printf("%p %p\n", p, p+1);//c의 주소, c의 주소 + sizeof(&c) //16, 24 - 틀림 16 17 
	//printf("%p %p\n", pp, pp+1);//p의 주소값, p의 주소값 +sizeof(p) == c의 주소값 //8, 16
	//printf("%p %p\n", &c, &c+1);//c의주소, c의 주소 위치 +sizeof(c) //16, 24 -틀림 16 17
	//printf("%p %p\n", &p, &p + 1);//p의 위치 주소, p의 위치 주소+sizeof(p) //8, 16
	//printf("%p %p\n", &pp, &pp + 1);//pp의 위치 주소, pp의 위치 주소 +sizeof(pp)0, 8
	
	//6. 배열 요소에 4를 곱하기
	/*int a[5] = { 5,4,3,2,1 };
	multiplay4(a, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}*/
	return 0;
}
/* 6번
void multiplay4(int* p, int len)
{
	int i;
	for (i=0; i < len; i++)
	{
		p[i] *= 4;
	}
}*/