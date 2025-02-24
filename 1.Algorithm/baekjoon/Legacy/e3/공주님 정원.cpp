#include<iostream>
#include<algorithm>

using namespace std;

typedef struct flower
{
	int sm, sd;
	int em, ed;
};


int top;
flower bundle[100001];
flower stack[100001];

bool compare(const flower& a, const flower& b)
{
	if (a.em == b.em) return a.ed < b.ed;
	else return a.em < b.em;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int end_stack=0;
	int start_stack=0;
	int n;
	int i;
	int cnt;
	bool flag = false;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &bundle[i].sm, &bundle[i].sd, &bundle[i].em, &bundle[i].ed);
	}

	sort(bundle + 1, bundle + n + 1, compare);

	top = 1;
	stack[top] = bundle[top];

	for (i = 2; i <= n; i++)
	{
		cnt = top;
		flag = false;

		while (bundle[i].sm * 100 + bundle[i].sd <= stack[cnt].em * 100 + stack[cnt].ed)
		{
			flag = true;
			cnt--;
			if (cnt == 0)
			{
				cnt = 1;
				break;
			}
		}

		if (bundle[i].sm * 100 + bundle[i].sd < stack[cnt].sm * 100 + stack[cnt].sd)
		{
			cnt++;
			stack[cnt] = bundle[i];
		}
		else if (flag)
		{
			cnt += 2;
			stack[cnt] = bundle[i];
		}
		else continue;
		top = cnt;
	}


	for (i = 1; i <= top; i++)
	{
		if (stack[i].em * 100 + stack[i].ed >= 1130)
		{
			end_stack = i;
			break;
		}
	}

	for (i = top; i >= 1; i--)
	{
		if (stack[i].sm * 100 + stack[i].sd <= 301)
		{
			start_stack = i;
			break;
		}
	}

	printf("%d", end_stack - start_stack + 1);

	return 0;
}