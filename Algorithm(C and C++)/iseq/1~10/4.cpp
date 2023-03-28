#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int w, h;
	int t, r;
	cin >> w >> h;
	t = (w * h) / 2;
	r = w * h;

	cout << t << endl;
	cout << r << endl;
}