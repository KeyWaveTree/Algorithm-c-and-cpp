#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	set<string> check;
	string name;	
	int cnt=0;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name;
		if (name == "ENTER")
		{
			check.clear();
			continue;
		}
		if (check.find(name)==check.end())
		{
			check.insert(name);
			cnt++;
		}
			
	}

	printf("%d", cnt);
	return 0;
}