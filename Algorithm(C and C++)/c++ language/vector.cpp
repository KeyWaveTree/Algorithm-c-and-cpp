#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v; //type ���ʷ����� int, float, char, string, bool, class, typedef struct ��� 
	v.push_back(10); //push ������ �Ҷ����� 2������ �þ��. 
	v.assign(10, 10); //�տ� ����, �ڿ� �ʱⰪ, ������ ����.assign(size, vector<type>)
	v.pop_back(); //return void Ÿ��
	//���� ��� Ȯ�� v[]

	//���� �޼ҵ� 
	/*size() - ������ ����� ������ ��ȯ�Ѵ�.

	swap(vector��ü) - �� ������ ������ ��ȯ(��ü)�Ѵ�.

	empty() - ���Ͱ� ������� ���θ� ��ȯ�Ѵ�.

	at(index) - index��° ��ҿ� �����Ѵ�.

	front() - ������ ù ��° ��Ҹ� ��ȯ�Ѵ�.

	back() - ������ ������ ��Ҹ� ��ȯ�Ѵ�.

	begin() - ������ ù ��° ��Ҹ� ����Ų��.

	end() - ������ ������ ��Ҹ� ����Ų��.
	
	//������ ���� 
	vector<vector<int>> r;
	r.assign(3, vector<int>());
	
	*/



}