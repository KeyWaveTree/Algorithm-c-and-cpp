#include<stdio.h>

int main()
{
	//�� byte���� 8byte? -���� 4byte �ƴѰ�?
	//�����Ϸ��� 64bit�̱⿡ 32bit�� 4byte���� 8byte�� �Ǿ���.

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