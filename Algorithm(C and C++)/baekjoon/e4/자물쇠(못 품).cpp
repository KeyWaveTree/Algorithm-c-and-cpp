#include<iostream>

using namespace std;

//0��° ����ϱ� ���ؼ� 1ĭ�� �������� ���� ��ȯ��ų ����
int chain[502];
//bool check[501];// true-����Ʈ false-��ȯ :p, q ã�� ��

int main()
{
	freopen("input.txt", "r", stdin);
	int n; //������ 
	int i;

	//reverse ������ 
	bool sw = false;
	int p, q;

	//�Է� 
	scanf_s("%d", &n);
	p = 1, q = n;
	
	
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &chain[i]);
	}

	//���� ���� �ݿ��ϵ���
	chain[0] = chain[n];
	chain[n + 1] = chain[1];
	
	//check �κ�
	for (i = 1; i <= n; i++)
	{
		//p, q ��ġ ���ϱ� - p, q ������ ������ �� �� ��ġ �������� �Ѵ�.
		//�տ� ������ ���ڰ� 1 ���̰� ���ų� 
		//�ڿ� �ִ� ���ڰ� ���̰� �������� ��� �տ� �ִ� ���ڰ� ������ ���ڶ�� 
		//���Ἲ�� ����� �κ� �����̴�.

		//����ġ�� false(��� ������ ����)�� ���¿��� ���� ���ڰ� �� ���� �����Ҷ� ���� ��ġ�� p�̴�. 
		if ((chain[i] - chain[i - 1] == 1 ||chain[i-1] - chain[i] == n-1) && sw == false )
		{
			sw = true;
			p = i;
			continue;
		}
		//���� ���� �� ������ �����̰� �ڽ��� �ռ��� �ڽŰ� �������� ������ ���� -1 ��ġ�� q�̴�.   
		if ((chain[i+1]- chain[i] ==1 || chain[i-1]-chain[i]==n-1) && chain[i] - chain[i - 1] != 1 && sw == true )
		{
			q = i-1;
			break;
		}
		/*if (!(chain[i] - chain[i - 1] == 1 || chain[i+1] - chain[i] == 1))
		{
			check[i] = true;
		}*/

	}

	//Ȯ�� �� 
	//printf("%d %d\n", chain[p], p);
	//printf("%d %d\n", chain[q], q);

	//���� ���� ��ġ�� p, ū ��ġ�� q��� �Ѵ�. 
	//����Ʈ ��ġ�� p(��������Ʈ)�� < q(������ ����Ʈ)�� ������ ������ �϶� 
	if (chain[p] < chain[q])
	{

	}

	// ����Ʈ ��ġ�� p(��������Ʈ)�� > q(������ ����Ʈ)�� ������ ������ �϶�

	return 0;
}

/*

typedef struct point
{
	int value;
	int index;
};

bool compare(const point& a,const  point& b)
{
	return a.index< b.index;
}


int main()
{
	freopen("input.txt", "r", stdin);
	int n; //������ 
	int i; 

	//reverse ������ 
	point p_or_q[2] = {(0,0)};
	point p, q;
	int cnt = 0;
	
	//�ű�� ���� 
	int k1, k2;
	
	//�Է� 
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &chain[i]);
	}

	//p, q ��ġ ���ϱ� -- p, q ������ ������ �� �� ��ġ �������� �Ѵ�.
	//1�� ���� ã�� 1��ġ���� ���� ������� ����. (������)
	//p, q�� ���ϴ� ��� 1�� ���� n-1 ���� 
	//�׻� ã�� �� p<q(��ġ��)
	for (i = 0; i <= n++1; i++)
	{
		//���̰� 1�����ų� n-1���� ���� �ʴ°�� 
		if (!(abs(chain[i%n] - chain[(i+1)%n]) != 1 && abs(chain[i%n] - chain[(i + 1)%n]) != (n - 1)))
		{
			//p Ȥ�� q�� ���� �ִ´�. 
			p_or_q[cnt].value = chain[i];
			p_or_q[cnt].index = i;
			//��ġ�� �ִ´�. 
			cnt++;
		}
		if (cnt == 2) break;
	}
	
	//���� ���� ��ġ�� p, ū ��ġ�� q��� �Ѵ�. 
	p = min(p_or_q[0], p_or_q[1], compare);
	q = max(p_or_q[0], p_or_q[1], compare);
	printf("%d %d", p.value, q.value);
	//����Ʈ ��ġ�� p(��������Ʈ) < q(������ ����Ʈ) ������ ������ �϶� 

	// ����Ʈ ��ġ�� p(��������Ʈ) > q(������ ����Ʈ) ������ ������ �϶�
	
	return 0;

}


10
10 3 4 5 6 7 8 9 2 1 10 3 

   f f f f f f f t t t
*/