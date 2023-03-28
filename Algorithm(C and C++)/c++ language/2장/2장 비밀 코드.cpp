#include<iostream>
#include<string>

using namespace std;

int main()
{
	char secret_code='h';
	char code;
	cin >> code;
	if (code < secret_code) cout << "뒤";
	else if (code > secret_code) cout << "앞";
	else cout << "맞음";

	return 0;
	 
	//getline(cin, str) 한 줄 입력 
}