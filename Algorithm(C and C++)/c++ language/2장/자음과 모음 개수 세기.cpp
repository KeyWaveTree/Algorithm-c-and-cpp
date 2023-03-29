#include<iostream>

using namespace std;

int main()
{
	char ch;
	int consonant = 0, vowel = 0;
	while (cin >> ch) //cin >> ch는 실행되면 참이기에 while문이 실행된다. 
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
	cout << "모음 " << vowel << '\n';
	cout << "자음" << consonant << '\n';
} 