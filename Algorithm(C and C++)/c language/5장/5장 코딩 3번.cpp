#include<stdio.h>

int main()
{
	int day;

	scanf("%d", &day);

	switch (day)
	{
	
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("평일");
		break;
	case 6:
	case 0:
		printf("주말");
		break;

	}

}