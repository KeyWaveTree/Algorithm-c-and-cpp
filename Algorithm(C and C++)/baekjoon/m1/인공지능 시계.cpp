#include<iostream>

using namespace std;

int main()
{
	int h, m, s;
	int time;
	int t=0;
	//�ʴ��� �ð�
	//h 3600��
	//m 60��
	//s 1��
	cin >> h >> m >> s;
	cin >> time;
	//��� �ð� �ʴ����� �ٲ㼭 ���
	t = h * 3600 + m * 60 + s+time;
	//�ð� ���� -24�ð� �̻� �Ѿ�� �ȵ�
	h = t / 3600 % 24;
	//�� ����- ���ð����� �ð��� ���־� ��
	m = (t - h * 3600) / 60 %60;
	//�� ���� 
	s= t % 60;

	printf("%d %d %d", h, m, s);

	return 0;
}