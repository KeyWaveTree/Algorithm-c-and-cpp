#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int pe_code, de_code, pe_count;
	int de[7] = {NULL ,5000, 7000, 8500, 9500, 12000, 20000 };
	int prize = 0;
	while (1)
	{
		cin >> pe_code >> de_code >> pe_count;
		if (pe_code == 0 && de_code == 0 && pe_count == 0)
		{
			break;
		}
		if (pe_code == 1) prize = (de[de_code] * pe_count) * 0.8;
		else if (pe_code == 2) prize = (de[de_code] * pe_count) * 0.9;

		cout << prize << endl;
	}
}