#include<iostream>

using namespace std;

int main()
{
	//g- �ʰ�
	//z - ������
	int g[10] = { 0,1,2,3,4,5,6,7,8,9 }; 
	char z[12] = { 'A','B','C','D','E','F','G','H','I', 'J','K','L' };
	int n; //�Է¹޴� �⵵ 

	int cnt = 0; //������ �� ���ΰ�?
	cin >> n;
	n += 60;// 1,2,3,4 �ʱ�ȭ ���� 60�� ���Ͽ� ���� �ǰ� �Ѵ�. 
	// ������ �ֱ�
	printf("%c%d", z[(n-4) % 12], g[(n-4) % 10]);
	return 0;
}