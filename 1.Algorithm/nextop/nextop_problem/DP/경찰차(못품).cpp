#include<iostream>

using namespace std;

//�������� ������ �����. 
typedef struct patrol
{
	int car;
	int x;//���� ���� 
	int y;//���� ���� 
};

patrol incident[1001];//��� ���� �迭 
//����ź�Ÿ��� �̿��ؼ� dfs
//���� 
int main()
{
	freopen("input.txt", "r", stdin);
	
	
	
	int n;
	int w;
	cin >> n >> w;

	//������ 1, 2����� 
	patrol one = { 1, 1, 1 };
	patrol two = { 2, n, n };
}