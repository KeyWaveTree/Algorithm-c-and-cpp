#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	int t, r;
	scanf("%d%d", &n, &m);

	//�ﰢ��
	//�簢��
	r = n * m;
	t = r / 2;

	printf("%d %d", t, r);

	return 0;
}