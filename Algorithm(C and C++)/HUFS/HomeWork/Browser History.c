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
//cursor - ������ġ ������ -tail

//��ŸƮ �ּ� 
BrowserHistory* browserHistoryCreate(char* homepage) {
   
    BrowserHistory* browser = (BrowserHistory*)malloc(sizeof(BrowserHistory)); //������ �ص� ��� 
    struct Node* nodePage = (struct Node*)malloc(sizeof(struct Node)); //���� ������ ��� 
    
    //nodePage ����
    strcpy(nodePage->url, homepage);

    //�⺻ ������ head�� �⺻�� head�� ��� ����  
    browser->head = nodePage;   //�������� head�� nodePage ����
    browser->cursor = nodePage; //�������� Ŀ�� nodePage�� ����

    //nodePage ���� ����
    nodePage->next = NULL;
    nodePage->prev = NULL;

    return browser;
}

void browserHistoryVisit(BrowserHistory* obj, char* url){
    struct Node* newPage = (struct Node*)malloc(sizeof(struct Node));
    struct Node* del;
    //cur���� �̹� homepage�� ���� �׷��� homepage-> next

    //url �����ؼ� �� �ֱ�
    strcpy(newPage->url, url);

    newPage->next = obj->cursor; //���ο� �������� ������ �ִ� node ������ ����
    obj->cursor->prev = newPage; // == newPage->next->prev= newPage;   
    obj->cursor = newPage;  //Ŀ���� ����Ű�� �ִ� ���� ���ο� ������ 

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