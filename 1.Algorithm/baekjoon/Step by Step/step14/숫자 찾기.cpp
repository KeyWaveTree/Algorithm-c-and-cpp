#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<int, bool> cards;
	int i, j;
	int n, m;
	int card;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &card);
		cards[card] = true;
	}

	scanf("%d", &m);
	for (j = 0; j < m; j++)
	{
		scanf("%d", &card);
		printf("%d ", cards.count(card));
	}

	return 0;
}