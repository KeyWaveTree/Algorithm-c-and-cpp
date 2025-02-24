#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//1 c
	/*char arr[100] = { '\0' };
	
	gets_s(arr, sizeof(arr));
	for(int i = strlen(arr) - 1; i >= 0; i--)
	{
		printf("%c", arr[i]);
	}*/

	//2 c++
	string arr;
	cin >> arr;

	for (int i = arr.length() - 1; i >= 0; i--)
	{
		cout << arr[i];
	}

	return 0;
}