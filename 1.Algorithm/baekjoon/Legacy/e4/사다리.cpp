#include<iostream>

using namespace std;

typedef struct bar
{
	int i;
	int d;
};

bar arr[3000];

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	int l;
	int i, d;
	int temp = 0;
	int max = 0;
	//�� ��(����), �� ����(�� �������� ĭ ����) 
	scanf("%d %d", &n, &l);
	for (int k = 0; k < n; k++)
	{	
		//����� ĭ ����, ���� �� Ȥ�� ������ �� ���� ������ ���ΰ�?
		scanf("%d %d", &arr[k].i, &arr[k].d);
		
		//����: �� ���� ������ ����� ĭ�� �� ������ �ִ� ���̴� ���ΰ�?
		
		//����Ⱑ �� �� ���� ���� �Ǵ� ������ �ִ� ������� ������ �� ������ ���� �ʿ� ����.  
		if (k == 0 || (k!=0 && arr[k].d == arr[k - 1].d)) continue;
		temp = (l - (arr[k].i + arr[k - 1].i))/2; //���̷� ������ �ְ� ������ �ٸ� �������� �������� ���� ���̸� temp���ٰ� �����ض�  
		if (temp <= 0) continue;//�������� ���� ���̰� 0���϶�� ������ ���������Ƿ� ������ �ʿ� ����. 
		if (max < temp) max = temp; //�� ������ �ִ���̸� max���ٰ� ���� ��. �̰� ���� �ð��̴�. 
	}

	printf("%d", max);//�ּҽð� ���

	return 0;
}