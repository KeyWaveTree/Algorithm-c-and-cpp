#include<iostream>

using namespace std;

int main()
{
	char ch;
	int consonant = 0, vowel = 0;
	while (cin >> ch) //cin >> ch�� ����Ǹ� ���̱⿡ while���� ����ȴ�. 
	{
		switch (ch)
		{
		case 'a':case 'e':case 'i':case 'o':case 'u':
			vowel++;
			break;
		default:
			consonant++;
			break;
		}
	}
	cout << "���� " << vowel << '\n';
	cout << "����" << consonant << '\n';
} 