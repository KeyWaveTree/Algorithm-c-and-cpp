#include<iostream>
#include<string>
#define and &&
#define or ||

using namespace std;

int main()
{
	string password;
	bool c1 = false, c2 = false, c3 = false;
	getline(cin, password);

	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 'A' and password[i] <= 'Z') c1 = true;
		else if (password[i] >= 'a' and password[i] <= 'z')c2 = true;
		else if (password[i] >= '0' and password[i] <= '9') c3 = true;

		if (c1 and c2 and c3)
		{
			cout << "����" << '\n';
			break;
		}
	}
	if(!c1 and !c2 and !c3)cout << "�������� �ʴ�.";

	return 0;
}