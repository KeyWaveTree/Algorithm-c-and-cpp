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

//head - 페이지 값 줄때 
//cursor - 다음위치 페이지


//스타트 주소 
BrowserHistory* browserHistoryCreate(char* homepage) {

    BrowserHistory* browser = NULL;
    BrowserHistory* nodePage = NULL; //임의 노드 

    //head는 현재 저장된 페이지 주소로 - brower 저장
    browser->head = homepage;
    *browser->head->url = *homepage;

    //curser 노드 연결
    browser->cursor->next = nodePage; //임의의 url 노드 추가 
    nodePage->cursor->prev = browser; //연결

    return browser;
}

void browserHistoryVisit(BrowserHistory* obj, char* url){
    BrowserHistory *newPage = NULL;
  
  /*  obj->cursor->next = newPage;
    newPage->cursor->prev = obj;*/
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {

}

char* browserHistoryForward(BrowserHistory* obj, int steps) {

}

void browserHistoryFree(BrowserHistory* obj) {

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