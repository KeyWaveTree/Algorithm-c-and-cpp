#include<iostream>

using namespace std;

int check[3001];
int arr[3000000];
int spare[3001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, d, k, c;
	int i, j;
	int flag=0;
	int cnt = 0;
	int num = 0;
	int sum = 0;
	//���� �� n, �ʹ��� ���� �� d, �����ؼ� �Դ� ���� k, ���� ��ȣ
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	////���Ʈ ���� - 1
	//for (i = 0; i < n; i++)
	//{
	//	check[c] = 1;
	//	flag = 0;
	//	cnt = 1;
	//	for (j = i; j < i + k; j++)
	//	{
	//		if (check[arr[j % n]] == 0) cnt++; // ó�� �Դ� �ʹ��̸� ī��Ʈ
	//		check[arr[j % n]] = 1; // ���� �ʹ� üũ
	//	}
	//	sum = max(sum, cnt);
	//	for (j = 0; j < 3001; j++)
	//	{
	//		check[j] = 0;
	//	}
	//}

	//printf("%d", sum);

	/* ������ ��� - 2
	 �迭�� ���� �� �ε��� ��ҿ� ���Ѵ� +1 
	 k+1�� ���� �ε��� ��Ҵ� +1�ϰ� 
	 k+1-k�� �� �ε��� ��Ҵ� �����ش�. 0���� �����. 
	 ������ �ε��� ��ġ�� 1�� ��� �־��ش�. 
	 ���ڸ��� ���� k�϶� cnt�� +1�Ѵ�.*/

	//check[c] = 1;
	//for (i = 0; i < n; i++)
	//{
	//	check[arr[i % n]] = 1;
	//	spare[cnt] = arr[i % n]; //check�� �ε����� ���� ������ ������� �ʱ�ȭ �Ҷ� ���
	//	cnt++;
	//	
	//	if ((cnt-num) % k == 0)
	//	{
	//		for (j = num; j < cnt; j++)
	//		{
	//			flag += check[spare[j]];
	//		}
	//		if (k == flag) sum++; //�ʹ䰳���� �� �ʹ��� ��ġ�� �ʴ� �ٸ� 
	//		flag = 0;
	//		num++; //k+1-k �� ���� ��(�ϳ��� �þ�鼭 �� ���� �ʿ� ����)
	//	}
	//}

	//printf("%d", sum);
	//���� �ϱ� 

	int s = 0;
	int e = 0;

	int total = 1;
	check[c] = 1;// ����

	for (i = 0; i < k; i++) //�ѹ� ����Ŭ ����
	{
		if (check[arr[i]]==0) total++; //�ʹ��� ���� ������ �ʹ䰳�� ��
		check[arr[i]]++; //�ѹ� �ߴٴ� ��ȣ 
	}
	
	if (sum < total)sum = total;

	//�״��� ���� ��ȯ �۾� �����̵�
	s = k - 1; //k����ŭ �� �ֱ⶧���� s ��ġ ����
	e = 0;

	for (i = 0; i < n; i++)
	{
		check[arr[e]] -= 1;//���� üũ�ϴ� ������ ��� 1�̻� 
		if (check[arr[e]] == 0)total--;
		e = (e + 1) % n;//�����̼�

		s = (s + 1) % n; //�����̼�
		check[arr[s]] += 1;
		if (check[arr[s]] == 1) total++; //���� s�� 1�� ������ 
		if (sum < total)sum = total;
	}

	printf("%d", sum);
	return 0;
}