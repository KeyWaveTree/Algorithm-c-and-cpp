#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

struct Infor
{
	int seq; //순서
	int age; //나이
	string id; //이름 아이디 
};

bool compare(Infor &n, Infor &m)
{
	if (n.age == m.age) return n.seq < m.seq;
	else return n.age < m.age;
}

int main()
{
	vector<Infor> in;
	string name;
	Infor inf;
	int age;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >>age >> name;
		
		inf.age = age;
		inf.id = name;
		inf.seq = i;
		in.push_back(inf);
	}

	sort(in.begin(), in.end(), compare);

	for (auto& i : in)
	{
		cout << i.age <<" " << i.id << '\n';
	}

	return 0;
}