#include<iostream>
#include<string>
using namespace std;

int main() 
{
	string s1, addr;
	cin >> s1;
	cin.ignore(); // ����Ű ���ֱ�

	getline(cin, addr);
	cout << addr << "�� " << s1 << "�� �ȳ��ϼ���" << '\n';

	cout << s1.find(addr[1]);
}