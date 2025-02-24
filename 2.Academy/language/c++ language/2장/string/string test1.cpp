#include<iostream>
#include<string>
using namespace std;

int main() 
{
	string s1, addr;
	cin >> s1;
	cin.ignore(); // 엔터키 없애기

	getline(cin, addr);
	cout << addr << "의 " << s1 << "씨 안녕하세요" << '\n';

	cout << s1.find(addr[1]);
}