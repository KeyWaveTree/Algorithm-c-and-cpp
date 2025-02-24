#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, bool> dense;
	string name1, name2;
	int n;
	int cnt = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2;
		dense.insert({ name1, false });
		dense.insert({ name2, false });
		if ((dense[name1] == false || dense[name2] == false && name1 == "ChongChong")
			|| (name1 != "ChongChong" && dense[name1] == true))
			
		{
			dense[name1] = true;
			cnt++;
		}
		if ((name2 == "ChongChong" && (dense[name1] == false || dense[name2] == false))
			||(name2 != "ChongChong" && dense[name2] == true))
		{
			dense[name2] = true;
			cnt++;
		}
	}

	printf("%d",cnt);

	return 0;
}