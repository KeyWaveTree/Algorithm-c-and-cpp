#include<iostream>
#include<string>

#define or ||

using namespace std;

int main()
{
	string n, v, o;
	string na;
	cout << "주어" << "동사"<< "목적어";
	cin >> n >> v >> o;

	if (o[0] == 'a' or o[0] == 'e' or o[0] == 'i' or o[0] == 'o' or o[0] == 'u')na = 'an';
	else na = 'a';

	cout << n << ' ' << v << ' ' << na << ' ' << o;

	//string.h를 포함해서 strcat을 사용할 수 있긴한데 굳이? 출력만 하는거라서..
}