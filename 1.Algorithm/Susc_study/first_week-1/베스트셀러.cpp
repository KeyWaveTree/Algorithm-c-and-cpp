#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>

using namespace std;

map<string, int> books;
vector<pair<string, int>> v;

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	//사전 순 정렬을 안함.
	//string을 scanf, printf를 사용해서 발생하는 오류였다. 
	//cin, cout
	string name;
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		cin >> name;
		if (books.find(name) == books.end()) books[name] = 1;
		else books[name] += 1;
	}

	for (auto& item : books) v.push_back(item);

	sort(v.begin(), v.end(), compare);

	cout<< v.at(0).first;

	return 0;
}