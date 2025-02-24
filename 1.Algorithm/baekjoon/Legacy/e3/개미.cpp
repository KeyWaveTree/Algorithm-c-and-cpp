#include<stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);

	int w, h;
	int p, q;
	int t;
	int x, y;
	int* p;
	
	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	scanf("%d", &t);
	x = y = t;
	//// 40% Á¤´ä
	//for (int i = 0; i < t; i++)
	//{
	//	p += psw; q += qsw;
	//	if (p == w || p==0) psw *= -1;
	//	if (q == h || q==0) qsw *= -1;
	//}

	//printf("%d %d", p, q);

	x = (p+t) % (w * 2);
	y = (q+t) % (h * 2);

	if (x >= w) printf("%d ", (w * 2)-x);
	else printf("%d ", x);

	if (y >= h) printf("%d ", (h * 2) - y);
	else printf("%d ", y);

}