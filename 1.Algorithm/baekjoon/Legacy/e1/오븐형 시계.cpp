#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, m, w;
	int sum = 0;//��ü�ð�
	cin >> h >> m;
	cin >> w;
	
	//���� ��ü �ð����� ������ - �д���
	sum = h * 60 + m + w;

	//�ð�
	h = sum / 60 % 24;
	
	//��
	m = (sum - (h * 60)) % 60;

	//���� �ʱ��� �Ѵٸ�
	/*
	h = sum / 3600 % 24;
	m = (sum - (h * 3600)) % 60;
	w= sum% 60;
	*/

	cout << h << " " << m<<" "<<w;

	return 0;
}