#include<iostream>
#include<algorithm>

using namespace std;

typedef struct table
{
	int number;
	int color;
	int size;
	int max_value;
};

const int MAX_SIZE = ((int)2e+5)+1;//�ִ� ���� ����

table balls[MAX_SIZE];
int color[MAX_SIZE];
int check[MAX_SIZE];

bool compare(const table& a, const table& b)
{
	return a.size < b.size;
}

bool reset(const table& a, const table &b)
{
	return a.number < b.number;
}

int main()
{
	int i, j=0;// �ݺ��ϴ� �� 
	int n;//���� ���� ���� 
	int c, s;//���� color�� size
	int colorCount = 0; //�÷��� index
	int all_sum = 0;

	cin >> n;//���� ���� �Է� 
	
	for (i = 1; i <= n; i++)
	{
		cin >> c >> s;
		balls[i].number = i+1;
		balls[i].color = c;
		balls[i].size = s;

		//�÷� ����
		color[colorCount++] = balls[i].color;
	}

	//ũ�� ������ ����
	sort(balls + 1, balls + n + 1, compare);
	
	//�÷��� ���� ��
	for (i = 1; i <= n; i++)
	{
		//���� ���� �ɷ��ֱ� ���� �ۼ��� 
		//�����̶� �ڿ� �ִ� ���� ��� x
		//���� ���� ����� ���� �����Ǿ� �ִ� ���� ������ ���� �۴ٸ� 
		while (balls[j].size < balls[i].size) //1�� �ݺ��� �뵵
		{
			all_sum += balls[j].size;//��� ũ�� ���� �� �����Ѵ�. 
			check[balls[j].color] += balls[j].size;// ���� �ڽ��� ������ ������ ������ �����ִ°��� ���Ѵ�.
			j++;//��ġũ�⸦ ������Ų��. 
		}
		//���� i�� ����Ű�� �ִ� ���� �ִ�ġ�� �� ���Ѱ��� ������ ������ ����̴�. 
		balls[i].max_value = all_sum - check[balls[i].color];
	}

	//����ġ�� �ǵ�����
	sort(balls + 1, balls + n + 1, reset);

	for (i = 1; i <= n; i++)
	{
		cout << balls[i].max_value << '\n';
	}

	return 0;
}