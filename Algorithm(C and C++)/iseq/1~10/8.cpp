#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0) cout << "Â¦¼ö" << endl;
		else cout << "È¦¼ö" << endl;
	}
	
	return 0;
}