#include<iostream>
#include<string>

#define or ||

using namespace std;

int main()
{
	string n, v, o;
	string na;
	cout << "�־�" << "����"<< "������";
	cin >> n >> v >> o;

	if (o[0] == 'a' or o[0] == 'e' or o[0] == 'i' or o[0] == 'o' or o[0] == 'u')na = 'an';
	else na = 'a';

	cout << n << ' ' << v << ' ' << na << ' ' << o;

	//string.h�� �����ؼ� strcat�� ����� �� �ֱ��ѵ� ����? ��¸� �ϴ°Ŷ�..
}