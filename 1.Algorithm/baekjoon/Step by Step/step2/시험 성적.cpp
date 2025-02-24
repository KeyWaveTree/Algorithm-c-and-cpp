#include<iostream>
#define or ||
#define and &&

using namespace std;


int main()
{
	int n;

	scanf("%d", &n);

	if (n >= 90 and n <= 100) cout << "A";
	else if (n >= 80 and n < 90) cout << "B";
	else if (n >= 70 and n < 80) cout << "C";
	else if (n >= 60 and n < 70)cout << "D";
	else cout << "F";

	return 0;
}