#include<iostream>

using namespace std;

int main()
{
	int t;
	int n;
	int f;
	int i;
	scanf("%d", &t);
	scanf("%d", &n);

	//�ܼ� ���ϱ� ���� 
	for (i = 0; i < n; i++)
	{
		scanf("%d", &f);
		t -= f;
	}

	if (t <= 0) printf("Padaeng_i Happy");
	else printf("Padaeng_i Cry");

	return 0;
}