#include<iostream>

using namespace std;

void sayHello(char cnt='1')
{
	for (char i = 0; i < 1; i++)
	{
		cout << "hello ";
	}
}


//디폴트 인수를 사용할 시 다중 인수를 사용:오버로딩 
void sayHello(int i, char cnt='1')
{
	for (char i = 0; i < cnt; i++)
	{
		cout << "hello ";
	}
}

int main()
{
	sayHello();
	return 0;
}