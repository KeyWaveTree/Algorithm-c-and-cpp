//#include<stdio.h>
//#include<stdlib.h>
//#define N 10
//
//static int i, k, n, u, v, j, ss, s, min, jj;
//
//struct node
//{
//	int v; // ���Ḯ��Ʈ�� ��Ұ� 
//	node* next;
//};
//
//node *matrix[N]; //�����ͷ� ���� ����
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
//	for (j = 1; j <= n; j++) //����Ÿ ���� 
//	{
//		scanf("%d%d", &u, &v);  //u�� ���ȣ, v �� ����ȣ
//		node* temp = new node; //���� ��� 
//
//		temp->next = matrix[u]->next;  //�� ��ȣ�� ����
//		temp->v = v;  //�ӽ� temp�� ��
//		matrix[u]->next = temp;  //����
//
//	}
//
//	node* jj;
//	for (j = 1; j < N ; j++)  //���ȣ Ž��
//	{
//		for (jj = matrix[j]->next; jj; jj = jj->next)  //jj�� ��ũ�帮��Ʈ �� ���� Ž�� ��ġ
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