#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a=0, b=0, c=0;
	int sum=0, avr=0;
	cin >> a >> b >> c ;
	sum += a + b + c ;
	avr = sum/3;
	
	cout << sum <<" ";
	cout << avr <<" ";

	switch(avr/10)
	{
	case 9:
		cout << "수" << endl;
		break;
	
	case 8:
		cout << "우" << endl;
		break;
	
	case 7:
		cout << "미" << endl;
		break;
	
	case 6:
		cout << "양" << endl;
		break;

	default:
		cout << "가" << endl;
		break;
	}
	return 0;
}
