//�ּҰ���� �ٽ� �ѹ� ����
#include<iostream>

using namespace std;

int gcd(int n, int m)
{
	int temp;
	if (n < m) //��Ŭ���� ȣ�������� m ������ �� ũ�� ��ġ �ٲپ��� 
	{
		temp = n;
		n = m;
		m = temp;
	}
	//m���� ���������� �������� 0�̶�� m�� ���� ���� ���̹Ƿ� m�� ��ȯ
	if (n % m == 0) return m;
	//m�� n�� m�� �������� ���ǿ� �����ɶ� ���� �ݺ�
	else return gcd(m, n % m);
}

int main()
{
	int n, m;
	cin >> n >> m;
	printf("%d\n%d", gcd(n, m), n*m/gcd(n,m));
	//�ּҰ���� - ���� �� �ȵ�

	return 0;
}