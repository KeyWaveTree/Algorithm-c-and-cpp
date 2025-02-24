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

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z') arr[i] += 32;
		else if (arr[i] >= 'a' && arr[i] <= 'z') arr[i] -= 32;
		printf("%c", arr[i]);
	}
	return 0;*/

	//2 c++
	string arr;
	getline(cin, arr);
	
	for (int i = 0; arr.length(); i++)
	{
		if (isupper(arr[i])) tolower(arr[i]);
		else if(islower(arr[i])) toupper(arr[i]);
		cout << arr[i];
	}
}