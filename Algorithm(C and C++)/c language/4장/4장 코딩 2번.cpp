#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int x, y, z;
	int ans;
	
	scanf("%d %d %d", &x, &y, &z);

	ans=x* y - z;
	printf("%d", ans);

}