#include<iostream>
#include<string>

using namespace std;

int main()
{
	char secret_code='h';
	char code;
	cin >> code;
	if (code < secret_code) cout << "��";
	else if (code > secret_code) cout << "��";
	else cout << "����";

	return 0;
	 
	//getline(cin, str) �� �� �Է� 
}