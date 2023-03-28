#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{

	freopen("baek_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[10] = { 0 };
	int mid=0, avr=0,sum=0;

	for (int i = 1; i <= 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	arr[0] = -987654321;
	for (int i = 2; i <= 5; i++) {
		int temp = arr[i];
		for (int j = i - 1; 1; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else {
				arr[j + 1] = temp;
				break;
			}
		}
	}
	avr = sum / 5;
	mid = arr[5 / 2 + 1];

	printf("%d\n%d", avr, mid);

	return 0;
}