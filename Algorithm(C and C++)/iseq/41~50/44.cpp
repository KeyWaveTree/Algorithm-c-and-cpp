#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//1 c-1 이중 for
	/*char arr[10][100] = { '\n' };
	int cnt;
	
	//아스키 코드값으로 변할뿐 똑같다.
	for (char i = 0; i < 5; i++)
	{
		cnt = 0;
		gets_s(arr[i], sizeof(arr[i]));
		for (int j = 0; j < strlen(arr[i]); j++)
		{
			if (arr[i][j] == 'A') cnt++;
		}
		printf("%d\n", cnt);

	}*/
	
	//2 c++
	string arr[100];

	for (int i = 0; i < 5; i++)
	{
		//c++ string gets_s 안됨 cin.getline은 귀찮음- 숫자 입력
		//string class에 getline함수 가지고 온다.
		int cnt = 0;
		getline(cin, arr[i]);
		for (int j = 0; j < arr[i].length(); j++)
		{
			if (arr[i][j] == 'A')cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
} 