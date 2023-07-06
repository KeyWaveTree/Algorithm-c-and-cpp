//최소공배수 다시 한번 공부
#include<iostream>

using namespace std;

int gcd(int n, int m)
{
	int temp;
	if (n < m) //유클리드 호제법에서 m 변수가 더 크면 위치 바꾸어줌 
	{
		temp = n;
		n = m;
		m = temp;
	}
	//m으로 나누었을때 나머지가 0이라면 m이 가장 작은 값이므로 m을 반환
	if (n % m == 0) return m;
	//m과 n과 m뺀 나머지를 조건에 만족될때 까지 반복
	else return gcd(m, n % m);
}

int main()
{
	int n, m;
	cin >> n >> m;
	printf("%d\n%d", gcd(n, m), n*m/gcd(n,m));
	//최소공약수 - 이해 잘 안됨

	return 0;
}