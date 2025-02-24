#include<iostream>

using namespace std;

void prime(int* i)
{
	int j = 2;
	for (j; j <= *i; j++)
	{
		if (*i % j == 0) break;
	}
	if (j == *i) cout<< j<< " ";
}

int main() 
{
	for(int i=2;i<=100;i++)
	{
		prime(&i);
	}
}