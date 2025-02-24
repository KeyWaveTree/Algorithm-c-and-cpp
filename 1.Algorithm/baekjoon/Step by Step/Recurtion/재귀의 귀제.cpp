#include<iostream>
#include<cstring>
using namespace std;

int n;
int cnt;
char arr[1001];

int palindrome(const char arr[], int l, int r)
{
	if (l >= r)return 1;
	else if (arr[l] != arr[r]) return 0;
	else
	{
		cnt++;
		return palindrome(arr, l + 1, r - 1);
	}
}

int main()
{
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cnt = 1;
		scanf("%s", arr);
		printf("%d ", palindrome(arr, 0, strlen(arr)-1));
		printf("%d\n", cnt);
	}
	return 0;
}