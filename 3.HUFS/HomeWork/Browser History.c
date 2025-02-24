#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 16382
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH	21

// DO NOT MODIFY //
struct Node {
    char url[MAX_URL_LENGTH];
    struct Node* prev;
    struct Node* next;
};

typedef struct {
    struct Node* head; 
    struct Node* cursor; 
} BrowserHistory;
// DO NOT MODIFY //

//head - ������ �� �ٶ�  - head
//cursor - ������ġ ������ -tail Ȥ�� ������ top
//
/*

BrowserHistory visit visit visit back back forward visit forward back back 
hufs.ac.kr google.com naver.com youtube.com 1 1 1 linkedin.com 2 2 7 

*/
//��ŸƮ �ּ� 
BrowserHistory* browserHistoryCreate(char* homepage) 
{
   
    BrowserHistory* browser = (BrowserHistory*)malloc(sizeof(BrowserHistory)); //������ �ص� ��� 
    struct Node* nodePage = (struct Node*)malloc(sizeof(struct Node)); //���� ������ ��� 
    
    //nodePage ����
    strcpy(nodePage->url, homepage);

    //�⺻ ������ head�� �⺻�� head�� ��� ����  
    browser->head = nodePage;   //�������� head�� nodePage ����
    browser->cursor = nodePage; //�������� Ŀ�� nodePage�� ����

    //nodePage ���� ���� �ʱ�ȭ 
    nodePage->next = NULL;
    nodePage->prev = NULL;

    return browser;
}

void browserHistoryVisit(BrowserHistory* obj, char* url)
{
    BrowserHistory* newPage = browserHistoryCreate(url);
    struct Node* del=NULL;
    //cur���� �̹� homepage�� ���� �׷��� homepage-> next

   //���� ��ġ�� �������� �ִٸ� ������ ��� �ֱ� 
    if (obj->cursor->next != NULL && obj->cursor->next != obj->cursor)
    {
        del = obj->cursor->next; //������ ����
        del->prev = NULL;   // ������ ��ũ ����
        obj->cursor->next = NULL;
        free(del);
    }

    // �� �տ� �������� �ڽŰ� ����
    obj->head->prev = obj->head;

    //���� �� �տ��� new �������ְ� �����丮�� ����Ǿ��ִ� ������ ����
    newPage->cursor->prev =obj->cursor; //���ο� �������� ������ �ִ� node �������� ����
    newPage->cursor->next = newPage->cursor; //newPage�� ������ null �̹Ƿ� �ʱ�ȭ ��� ���������� �ڽ��� �����ؾ� ��
    obj->cursor->next = newPage->cursor;  // == newPage->next->prev= newPage;
    obj->cursor = newPage->cursor;  //Ŀ���� ����Ű�� �ִ� ���� ���ο� ������ obj->cursor->next = newPage->cursor;
}

char* browserHistoryBack(BrowserHistory* obj, int steps)
{
    struct Node* cur = obj->cursor;
    for (int i = 0; i < steps; i++)
    {
        cur = cur->prev;
    }
    obj->cursor = cur;
    return cur->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) 
{
    struct Node* cur = obj->cursor;
    for (int i = 0; i < steps; i++)
    {
        cur = cur->next;
    }
    obj->cursor = cur;
    return cur->url;
}

void browserHistoryFree(BrowserHistory* obj) 
{
    free(obj);
}

// DO NOT MODIFY //
int main() {
    int i = 0, count = 0;
    char arg1[500];
    char arg2[500];
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];

    fgets(arg1, 500, stdin);
    fgets(arg2, 500, stdin);
    if (arg1[strlen(arg1) - 1] == '\n') {
        arg1[strlen(arg1) - 1] = '\0';
    }
    if (arg2[strlen(arg2) - 1] == '\n') {
        arg2[strlen(arg2) - 1] = '\0';
    }
    char* token = strtok(arg1, " "); // �������� ���ڿ� ������

    while (token != NULL) {
        strcpy(cmd[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i = 0;
    token = strtok(arg2, " "); // �������� ���ڿ� ������
    while (token != NULL) {
        strcpy(parm[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " ");
        i++;
    }


    BrowserHistory* obj;
    for (i = 0; i < count; i++) {
        if (strcmp(cmd[i], "BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]); 
        }
        else if (strcmp(cmd[i], "visit") == 0) {
            browserHistoryVisit(obj, parm[i]);
        }
        else if (strcmp(cmd[i], "back") == 0) {
            printf("%s ", browserHistoryBack(obj, atoi(parm[i])));
        }
        else if (strcmp(cmd[i], "forward") == 0) {
            printf("%s ", browserHistoryForward(obj, atoi(parm[i])));
        }
    }
    browserHistoryFree(obj);
    return 0;
}
// DO NOT MODIFY //