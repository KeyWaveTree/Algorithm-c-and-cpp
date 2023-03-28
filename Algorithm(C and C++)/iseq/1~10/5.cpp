#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14

#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	float r;
	cin >> r;

	cout << (2 * r*  PI) << endl;
	cout << r * r * PI << endl;
}