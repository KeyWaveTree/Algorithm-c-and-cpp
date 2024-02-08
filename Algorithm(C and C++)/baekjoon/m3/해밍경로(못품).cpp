#include<iostream>
#include<algorithm>

using namespace std;

typedef struct bitCode
{
	int bit_value; //xor ���� �Ҷ� ���
	int bit_count; //���� Ž�� �Ҷ� ���
	int index; //��� �Ҷ� ���
};

bitCode arr[100001];
bitCode sorts[100001];
bitCode queue[1001];
int bitdir[100000];

bool compare(const bitCode& a, const bitCode& b)
{
	return a.bit_value < b.bit_value;
}

int main()
{
	//�ع� ��� 
	//�Է¹��� ��Ʈ�� ���� 

	freopen("input.txt", "r", stdin);
	int n, k;
	int i, j;

	int m, h;
	
	int bit_count=0;
	int find_bit_cnt = 0;
	//bit ���� �ޱ� ���� ���ڿ� ��� -> int 
	char bit[32] = { '\0' };

	//bit���� ����, bit���� ���� 
	scanf("%d %d", &n, &k);

	//2 ** 30�̹Ƿ� ���簣���ϰ� bit���� �������� ����. 
	for (i = 1; i <= n; i++) //n���� bit �� 
	{
		
		scanf("%s", bit);
		arr[i].index = i;
		sorts[i].index = i;
		bit_count = 0;
		for (j = 0; j < k; j++) //bit ���
		{	//���ڰ� 1 �ΰ��� ����ϱ� ���ؼ� pow ���(log n)
			if (bit[j] == '1')
			{
				arr[i].bit_value += (int)pow(2, j);//���� ���� �ڸ� ��Ʈ�� 1�̸� ����Ѵ�.
				bit_count++;
			}
		}
		sorts[i].bit_value = arr[i].bit_value;
		//bit���� 1�� ǥ�ð� �� ������ �ִ´�. 
		arr[i].bit_count = bit_count;
	}

	// ���� 
	sort(sorts + 1, sorts + n + 1, compare);

	scanf("%d", &m);


	//m�� �ݺ�

	for (i = 0; i < m; i++)
	{
		//1~h��° ���� ���� �ع� ��� 
		scanf("%d", &h);

			//���� ���� �ϴ� �ּ� Ƚ�� = �� ����  - popcnt�� �Ͽ� bit������ ���ش�. 
			find_bit_cnt = __popcnt(arr[1].bit_value ^ arr[n].bit_value);
			bit_count = arr[1].bit_value ^ arr[n].bit_value;

	
	}

	//��� Ȯ���� ���� 
	//�عְ�� ��� ������ �ڵ� ���̰� 1�� ��� 
	//��Ʈ �� �� 1bit �� ���̰� ���Ƿ� xor ������ �Ͽ� ã�´�. - �ٵ� xor�� ���� �ؾ� �ұ�? ���ص� �ɰͰ����� - �ؾ� ��
	//������ ���Ʈ ������ �ϸ� n^2�� �����Ƿ� 
	//������ �迭���� ���� Ž�� (bit�� ���̰� �ϳ��� ������ ����) 
	//������ ����  
	//�ȳ����� -1 ��� �� ���� 
	//���� ���� Ž�� �ߴµ� ���� �ȳ���. �׷� ���� bit �� ã�� - �ٵ� �̰� ���� �� �� ����. - ������ -1 ���  
	//�ֳĸ� ���� ��Ʈ �� �� ã�´� �ص� ��Ʈ ���� ���� 0�� 1�� ������ 1�� �ٸ��� ������ ������ 0�� 1�� ���̰� ����. 

	//���� ���ᰡ ���� �ʾҴٸ� ������ ��ġ ��� 
}