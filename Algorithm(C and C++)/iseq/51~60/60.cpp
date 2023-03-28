#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[100] = { 1 };
	int n;
	int L = 0, carry, temp;
	scanf("%d", &n);
	
	for (int j = 1; j <= n; j++) 
	{
		//길이는 정해저 있는것이 아니니  L로 지정
		for (int i = 0; i <= L; i++)
		{
			//현재 자리에 곱 2
			arr[i] *= 2;
		}

		if (arr[L] >= 10) L++; //마지막 배열의 수가 10보다 크면 길이 하나 증가
		//(의미) 1~n까지 반복한 마지막 수가 10의자리보다 크다면 길이를 하나 증가하라 
		carry = 0;

		for (int i = 0; i <= L; i++)
		{
			//일자리 수 ㄴ+ 올림수를 먼저 저장 - 값이 0이 나오면 안된다.
			//(why? arr[i]다가 저장하지 않는가? - 올림수 연산 할 때 손실이 발생한다.)
			temp = arr[i] % 10 + carry;
			//다음 올림수는 저장된 수의 몫 - temp위에다 선언하면 temp가 연산이 된다.
			carry = arr[i] / 10;
			//그다음 위치에다가 일에자리 수 저장
			arr[i] = temp;
		}
	}

	for (int i = L; i >= 0; i--)
	{
		printf("%d", arr[i]);
	}
}