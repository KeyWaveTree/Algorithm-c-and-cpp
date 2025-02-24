#include<iostream>
#include<string>
#include <fstream>
using namespace std;

int main()
{
	
	//ifstream s("D:\\WorkList\\1.Algorithm\\1.Algorithm(C and C++)\\1.Algorithm(C and C++)\\c++ language\\2��\\cpp.txt");
	ifstream s("cpp.txt");
	string s1, s2;
	int cnt=0;
	getline(s, s1);
	getline(s, s2);
	if (s1.length() != s2.length()) 
	{
		return 0;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i]) cnt++;
	}

	cout << cnt;
}