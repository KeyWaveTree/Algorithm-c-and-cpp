#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//1. 문자열 복사 및 붙여넣기
	//c
	//char arr[100] = { '\0' };
	//char copy[100] = { '\0' };
	//char arrow;
	//int wave, k=0, cnt = 0;

	//gets_s(arr, sizeof(arr));
	//scanf("%c %d", &arrow, &wave);
	//
	//strcpy(copy, arr);
	//for (int i = 0; i <strlen(copy); i++)//처음 시작 위치 중앙
	//{
	//	strcat(arr, copy);
	//	cnt += strlen(copy);
	//	if (cnt / 2 % strlen(copy) == 0) k = cnt/2;
	//}
	//if (arrow == 'L')
	//{
	//	for (int i = k + wave; i < k + strlen(copy) + wave; i++)
	//	{
	//		printf("%c", arr[i]);
	//	}
	//}
	//else if (arrow == 'R')
	//{
	//	for (int i = k - wave; i < k + strlen(copy) - wave; i++)
	//	{
	//		printf("%c", arr[i]);
	//	}
	//}
	//
	//return 0;

	//c++
	//2. 포인터 링크드리스트
	
	//3. 순환 (원형 큐 방식)
	
	// 예외 문자열 길이까지 꽉 체워짐 그다음 오버런됨 - 동적할당을 한 경우에도 오버런됨 나중에 탐구
	/*
	temp=strcat(copy, arr);  
	strcat(copy, temp);
	*/

	//c++
	
	//2. 순환 문자열 
	//c
	//c++
	
}