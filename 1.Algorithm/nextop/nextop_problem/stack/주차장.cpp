#include<iostream>

using namespace std;

int stack[10001];
int check[10001];

int main()
{
	freopen("nextop-problem", "r", stdin);
	
	int n; //최대 차량
	int max = 0;//현재 들어온 수가 큰지 작은지 판단할때
	int top, chk;

	cin >> n;
	for (top = 1; top <= n; top++)
	{
		cin >> stack[top];
	}
	
	for (top = 1; top <= n; top++)
	{
		if (stack[top] > max)
		{
			max = stack[top];//들어온 수를 지정 
			check[max] = 1;
		}
		else
		{
			if (stack[top] + 1 == stack[top - 1]) check[top] = 1; //지금 값이 전에있던 값하고 1차이 밖에 안나면
			else
			{
				for (chk = stack[top - 1] - 1; chk >= stack[top] + 1; chk--)
				{
					if (check[chk] != 1)
					{
						cout << "no"<<'\n';
						return 0;
					}
				}
				check[top] = 1;
			}
		}
	}

	cout << "yes"<<'\n';
	return 0;
}