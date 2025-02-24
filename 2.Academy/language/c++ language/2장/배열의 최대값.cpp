#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int arr[100] = { 0 };
	int max = 0;
	for (auto& v : arr)
	{
		v = rand() % 100 + 1;
		if (v > max)max = v;
	}

	cout << max;
}