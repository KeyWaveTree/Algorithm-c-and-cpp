#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int arr[10] = { 0 };
	int li = 0, sip = 0, bak = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		if (arr[i] >= 100 && arr[i]<1000) bak += arr[i]; 
		else if (arr[i] >= 10 && arr[i]<100) sip += arr[i];
		else if (arr[i] >= 0 && arr[i]<10) li += arr[i];
	}
	cout << li << endl;
	cout << sip << endl;
	cout << bak << endl;

}