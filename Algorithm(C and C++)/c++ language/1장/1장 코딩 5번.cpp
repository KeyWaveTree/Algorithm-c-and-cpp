#include<iostream>

using namespace std;

int main()
{
	const float P = 3.3058;
	float p;
	
	cin >> p;
	
	cout << p * P;
	//if()조건 안에 변수 선언 가능 but and or 연산이 있을때 커팅될 수 있음 javascrept와 비슷 최적화 기법중 하나 
	//컴파일러에 우선연산이 된다. 

	// 피연산은 작은데 나누는 수가 더 크다면(어떤수로 나누는 값이 범위가 저장이 안되면? 어떻게 해야 하는가?) 
}