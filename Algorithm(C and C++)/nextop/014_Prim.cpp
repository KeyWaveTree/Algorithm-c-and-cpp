#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define N 10

using namespace std;

int arr[N][N];
int r[N][N]; //��³��
bool cheak[N]; //���� ��ǻ�Ͱ� �� ���� üũ why? ���ѹݺ��ɸ��� ����Ŭ ���� false ���� �Ȱ�, true ����
int n=10; // �� ��� ����

void input()
{

}

void prim()
{
	int i, chk, s, e;
	int min;
	int cnt = 0;// ��� Ž�� ����
	
	while (true)
	{
		min = 1000000000;
		for (chk = 1; chk <= n; chk++) //���۳�� index
		{
			for (i = 1; i <= n; i++) //�� ��� index
			{
				if (arr[chk][i] != 0 && cheak[chk] == false && min > arr[chk][i])
				{
					min = arr[chk][i]; //����ġ ����
					s = chk; //����Ǵ� ó���� �ε���
					e = i; //����Ǵ� ���� �ε���
				}
			}
		}

		//cheak�迭�� �ٳ�� ��� ǥ��
		cheak[e] = true;

		// ����� ��ġ���ٰ� �ּҰ� �ֱ�
		r[s][e] = min; 
		r[e][s] = min; 

		cnt++; 
		if (cnt == n - 1) break;
	}
}

void print()
{

}


int main()
{
	input();
}