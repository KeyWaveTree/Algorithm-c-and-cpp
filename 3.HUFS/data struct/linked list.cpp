//#include<stdio.h>
//#include<stdlib.h>
//#define N 10
//
//static int i, k, n, u, v, j, ss, s, min, jj;
//
//struct node
//{
//	int v; // 연결리스트의 요소값 
//	node* next;
//};
//
//node *matrix[N]; //포인터로 직접 지정
//
//int main()
//{
//	for (j = 0; j < N ; j++)
//	{
//		matrix[j] = new node;
//		matrix[j]->v = -1;
//		matrix[j]->next = NULL;
//	}
//
//	scanf("%d", &n);
//
//	for (j = 1; j <= n; j++) //데이타 개수 
//	{
//		scanf("%d%d", &u, &v);  //u가 방번호, v 가 공번호
//		node* temp = new node; //다음 노드 
//
//		temp->next = matrix[u]->next;  //방 번호를 연결
//		temp->v = v;  //임시 temp에 공
//		matrix[u]->next = temp;  //연결
//
//	}
//
//	node* jj;
//	for (j = 1; j < N ; j++)  //방번호 탐색
//	{
//		for (jj = matrix[j]->next; jj; jj = jj->next)  //jj는 링크드리스트 안 구조 탐색 위치
//		{
//			printf("%d- %d\n", j, jj->v);
//		}
//	}
//}

#include<stdio.h>
#include<stdlib.h>
typedef int data;

typedef struct NODE
{
	data value;
    NODE *next;
}node;

struct LINKED_LIST
{
    node* head;
    int len;
}
*linked_list;

void initList()
{
    linked_list = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
    linked_list->head = NULL;
    linked_list->len = 0;
}
bool isEmpty()
{
    return linked_list->len == 0;
}
void insertMiddle(int pos, data item)
{
    node* newNode = NULL;
    newNode = (node*)malloc(sizeof(node));
    newNode->value = item;
    newNode->next = NULL;

    for (int i = 0; i < pos; i++)
    {
        linked_list->head = linked_list->head->next;
    }
    newNode->next = linked_list->head->next;
    linked_list->head->next = newNode;
    
   
    linked_list->len++;

}
void removeMiddle()
{
    node* delNode = NULL;
    delNode = (node*)malloc(sizeof(node));
    delNode->next = NULL;
    delNode->value=
}

data readItem()
{

}

void printList()
{

}

void clearList()
{

}