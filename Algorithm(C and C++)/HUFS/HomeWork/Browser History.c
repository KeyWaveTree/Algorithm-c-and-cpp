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
//cursor - 다음위치 페이지 -tail

//스타트 주소 
BrowserHistory* browserHistoryCreate(char* homepage) {
   
    BrowserHistory* browser = (BrowserHistory*)malloc(sizeof(BrowserHistory)); //브라우저 해드 노드 
    struct Node* nodePage = (struct Node*)malloc(sizeof(struct Node)); //임의 페이지 노드 
    
    //nodePage 구성
    strcpy(nodePage->url, homepage);

    //기본 브라우저 head는 기본적 head로 취급 하자  
    browser->head = nodePage;   //브라우저의 head는 nodePage 연결
    browser->cursor = nodePage; //브라우저의 커서 nodePage와 연결

    //nodePage 방향 설정
    nodePage->next = NULL;
    nodePage->prev = NULL;

    return browser;
}

void browserHistoryVisit(BrowserHistory* obj, char* url){
    struct Node* newPage = (struct Node*)malloc(sizeof(struct Node));
    struct Node* del;
    //cur에는 이미 homepage가 있음 그러니 homepage-> next

    //url 복사해서 값 넣기
    strcpy(newPage->url, url);

    newPage->next = obj->cursor; //새로운 페이지는 기존에 있던 node 페이지 지정
    obj->cursor->prev = newPage; // == newPage->next->prev= newPage;   
    obj->cursor = newPage;  //커서가 가리키고 있는 값은 새로운 페이지 

   /* del = newPage->prev;
    newPage->prev->next = NULL;
    
    free(del);*/
}

char* browserHistoryBack(BrowserHistory* obj, int steps)
{
    struct Node* cur = obj->cursor;
    for (int i = 0; i < steps; i++)
    {
        cur = cur->next;
    }

    return cur->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    struct Node* cur = obj->cursor;
    for (int i = 0; i < steps; i++)
    {
        cur = cur->prev;
    }

    return cur->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    free(obj->head);
    free(obj->cursor);
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