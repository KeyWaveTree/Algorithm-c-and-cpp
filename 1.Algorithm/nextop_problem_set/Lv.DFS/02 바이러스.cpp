#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> adjMatrix;//인접 행렬
vector<bool> check; //컴퓨터 방문 기록판
int vertex; //컴퓨터(노드)의 수 - 방문할 노드를 찾기 위해 전역 변수
int edge; //네트워크(간선)의 수 -지역변수로 지정해도 괜찮음.
int cnt;//감염된 컴퓨터의 수를 누적하는 변수

void dfs(int start) { //시작 노드
    int end;

    check[start] = true; //start 노드 체크 표시
    cnt++; //감염 표시 증가

    //다음에 방문할 노드 찾기
    for (end = 1; end <= vertex; end++) {
        //인접 행렬을 이용하여 현재 위치된 곳에서 다음에 방문할 수 있는 도착지를 확인
        //만약 인접행렬값이 true이고 방문할 지역이 방문을 한번도 안했을때만 방문한다.
        if (adjMatrix[start][end] && !check[end]) {
            dfs(end);
        }

    }
}

int main() {

    int start, end; //출발 간선, 도착 간선
    int i;


    //노드수 간선수 입력
    cin >> vertex >> edge;

    //동적 할당
    check.resize(vertex + 1); //체크 배열 할당
    adjMatrix.resize(vertex + 1);//인접 행렬 1차원 할당
    //인접행렬이므로 2차원 할당
    for (i = 1; i <= vertex; i++) adjMatrix[i].assign(vertex + 1, false);

    //graph 정보 입력
    for (i = 1; i <= edge; i++) {
        cin >> start >> end;//출발 노드, 도착 노드 입력
        //양방향 간선 표시
        adjMatrix[start][end] = adjMatrix[end][start] = true;
    }


    dfs(1);//1번노드에서 dfs시작

    //dfs가 끝난 후 감염된 컴퓨터의 수 출력 1번 노드를 뺀
    cout << cnt - 1;

    return 0;
}