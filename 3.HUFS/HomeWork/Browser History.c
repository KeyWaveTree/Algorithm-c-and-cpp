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

//head - 페이지 값 줄때  - head
//cursor - 다음위치 페이지 -tail 혹은 스텍의 top
//
/*

BrowserHistory visit visit visit back back forward visit forward back back 
hufs.ac.kr google.com naver.com youtube.com 1 1 1 linkedin.com 2 2 7 

*/
//스타트 주소 
BrowserHistory* browserHistoryCreate(char* homepage) 
{
   
    BrowserHistory* browser = (BrowserHistory*)malloc(sizeof(BrowserHistory)); //브라우저 해드 노드 
    struct Node* nodePage = (struct Node*)malloc(sizeof(struct Node)); //임의 페이지 노드 
    
    //nodePage 구성
    strcpy(nodePage->url, homepage);

    //기본 브라우저 head는 기본적 head로 취급 하자  
    browser->head = nodePage;   //브라우저의 head는 nodePage 연결
    browser->cursor = nodePage; //브라우저의 커서 nodePage와 연결

    //nodePage 방향 설정 초기화 
    nodePage->next = NULL;
    nodePage->prev = NULL;

    return browser;
}

void browserHistoryVisit(BrowserHistory* obj, char* url)
{
    BrowserHistory* newPage = browserHistoryCreate(url);
    struct Node* del=NULL;
    //cur에는 이미 homepage가 있음 그러니 homepage-> next

   //다음 위치가 페이지가 있다면 지워줄 기록 넣기 
    if (obj->cursor->next != NULL && obj->cursor->next != obj->cursor)
    {
        del = obj->cursor->next; //페이지 저장
        del->prev = NULL;   // 페이지 링크 제거
        obj->cursor->next = NULL;
        free(del);
    }

    // 맨 앞에 페이지는 자신과 연결
    obj->head->prev = obj->head;

    //먼저 맨 앞에다 new 페이지넣고 히스토리가 저장되어있는 페이지 연결
    newPage->cursor->prev =obj->cursor; //새로운 페이지는 기존에 있던 node 페이지들 지정
    newPage->cursor->next = newPage->cursor; //newPage의 다음은 null 이므로 초기화 라고 생각했으나 자신을 지정해야 함
    obj->cursor->next = newPage->cursor;  // == newPage->next->prev= newPage;
    obj->cursor = newPage->cursor;  //커서가 가리키고 있는 값은 새로운 페이지 obj->cursor->next = newPage->cursor;
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
    char* token = strtok(arg1, " "); // 공백으로 문자열 나누기

    while (token != NULL) {
        strcpy(cmd[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i = 0;
    token = strtok(arg2, " "); // 공백으로 문자열 나누기
    while (token != NULL) {
        strcpy(parm[i], token); // 나눈 문자열을 배열에 저장하기
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