#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	//in - 들어오는 값
	//out - 나오는 값
	int in, out;
	int max = 0; //열차 최대 인원
	int sum = 0; //in/ out 했을때 열차 승객

	for (int i = 0; i < 10; i++)
	{
		cin >> out;
		cin >> in;

		sum = sum - out + in;
		if (sum > max)max = sum;
	}

	cout << max;
	return 0;
}