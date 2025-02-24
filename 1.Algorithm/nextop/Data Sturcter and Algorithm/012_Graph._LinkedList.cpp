#define _CRT_SEUCRE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

#define N 10

struct Linked
{
	int v;
	Linked *next;
};

Linked *matrix[N];
//포인터에서 구조체나 클래스에서는 어떤 요소를 가리킬때 ->쓰고(위치를 가리키는 것이니 그렇다.)
//일반 구조체 클래스에서는 .을 쓴다.

int main()
{
	for (int i = 0; i < N; i++)
	{
		//선언은 해주었지만 아직 생성이 안됨
		matrix[i] = new Linked;
		matrix[i]->v = -1;
		matrix[i]->next = NULL;

	}


	Linked* temp = new Linked;   //임시 temp구조 동적생성
	temp->v = 10;
	matrix[3]->next = temp;//1.

	temp = new Linked;   //임시 temp구조 동적생성
	temp->v = 20;
	matrix[2]->next = temp; //1.


	temp = new Linked;   //임시 temp구조 동적생성
	temp->v = 200;
	temp->next = matrix[3]->next; //2.
	matrix[3]->next = temp;

	temp = new Linked;   //임시 temp구조 동적생성
	temp->v = 300;
	temp->next = matrix[3];//2.
	matrix[3]->next = temp;

	//1과 2의 차이는 무엇인가?
	// 
	//temp->next=matrix[u]->next;  //matrix방에 매단 구조를 temp에 일단 매단다
	//temp->v=v;   //temp 에 값을 지금 구슬  (현재것이 가장 위로)
	//matrix[u]->next=temp;  //temp를 matrix에 매단다.  즉, 매단 역순이 된다.

	return 0;
}