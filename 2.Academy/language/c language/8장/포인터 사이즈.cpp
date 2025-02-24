#include<stdio.h>

int main()
{
	//왜 byte수가 8byte? -원래 4byte 아닌가?
	//컴파일러가 64bit이기에 32bit인 4byte에서 8byte로 되었다.

	char c = 'A';
	char* pc = &c;
	char** ppc = &pc;

	int n = 10;
	int* pn = &n;
	int** ppn = &pn;

	printf("%p %p\n", pc, pc + 1);
	printf("%p %p\n", ppc, ppc + 1);
	printf("%p %p\n", &c, &c + 1);
	printf("%p %p\n", &pc, &pc + 1);
	printf("%p %p\n", &ppc, &ppc + 1);

	printf("%p %p\n", pn, pn + 1);
	printf("%p %p\n", ppn, ppn + 1);
	printf("%p %p\n", &n, &n + 1);
	printf("%p %p\n", &pn, &pn + 1);
	printf("%p %p\n", &ppn, &ppn + 1);

	return 0;
}