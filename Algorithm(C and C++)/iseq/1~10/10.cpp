#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;

	//���� ������ ���չ� �ٽ� 
	int max = (a > b && a > c) ? a : (b > c && b > a) ? b : c;
	cout << max;
}