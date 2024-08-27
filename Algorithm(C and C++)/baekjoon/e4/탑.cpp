#include<iostream>
#include<vector>

using namespace std;

typedef struct stick
{
	int len;
	int index;
}stick;

vector<stick> signal, stack;
stick null;
int n, temp;
int top;

void push(stick item)
{
	top++;
	stack[top] = item;
}

stick pop()
{
	if (top == 0) return null;
	stick item = stack[top];
	top--;

	return item;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	stick empty;
	stack.assign(500001, null);
	empty.len = 0;
	empty.index = 0;


	scanf("%d", &n);
	printf("%d ", 0);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		empty.len = temp;
		empty.index = i;

		if (i == 1)
		{
			push(empty);
			continue;
		}
	
		while (stack[top].len < temp)
		{
			if (top == 0) break;
			pop();
		}
		push(empty);
		printf("%d ", stack[top - 1].index);
	

}