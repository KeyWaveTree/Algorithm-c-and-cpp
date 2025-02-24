#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	int li, sip, bak;
	cin >> n;
	
	bak= n/100;
	sip = (n % 100)/10;
	li = (n % 100) % 10;

	cout << bak + sip + li << endl;
}
