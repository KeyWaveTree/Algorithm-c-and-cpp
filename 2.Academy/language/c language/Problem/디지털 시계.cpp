#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int main()

{
	int h, m, s;
	h = m = s = 0;

	while (1)
	{
		system("cls");
		printf("%02d : %02d : %02d", h, m, s); // 00 -> 정렬 후 보여짐 
		s++;
		if (s == 60) 
		{
			m++; 
			s = 0;
		}
		if(m==60) 
		{
			h++;
			m = 0;
		}
		if (h == 24)
		{
			h = s = m = 0;
		}
		Sleep(1000);
	}
}