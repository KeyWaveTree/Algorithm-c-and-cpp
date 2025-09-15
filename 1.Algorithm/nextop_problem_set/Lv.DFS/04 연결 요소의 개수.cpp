#include<iostream>
#include<vector>

using namespace std;

//그래프의 연결 요소 - 다음 조건을 만족하는 정점들의 집합
//1. 정의된 경로(edge)로 연결된 정점들은 연결요소에 속한다.
//2. 1번 조건을 만족하면서 정점을 추가할 수 없다.
//   ㄴ> 2번 조건은 연결요소의 부분집합을 배제해야 된다는 뜻이다.
//즉 서로 연결되어있는 집합들이 그래프의 연결요소이다.

//이번 문제는 주어진 정보 중 몇개의 그래프가 있는가를 구하는 문제이다.

int vertex, edge;
vector<bool> check;
vector<vector<bool>> adjacencyMatrix;

void dfs(int start) {
    //만약 이미 start 정점을 방문했다면 함수 return
    if (check[start]) return;

    //방문을 안한 정점일때 check표시
    check[start] = true;

    //start에서 갈 수 있는 정점들을 확인한다.
    for (int end = 1; end <= vertex; end++) {
        //만약 인접행렬에서 end 위치로 이동할 수 있을때만 dfs를 한다
        if (adjacencyMatrix[start][end]) {
            dfs(end);
        }
    }
}

int main() {
    int i;
    int start, end;
    int count = 0;

    cin >> vertex >> edge;
    //인접행렬 동적 할당
    check.assign(vertex + 1, false);
    adjacencyMatrix.resize(vertex + 1);
    for (i = 1; i <= vertex; i++) adjacencyMatrix[i].assign(vertex + 1, false);

    //입력
    for (i = 1; i <= edge; i++) {
        cin >> start >> end;
        //인접행렬 정보 표시
        adjacencyMatrix[start][end] = adjacencyMatrix[end][start] = true;
    }

    //연결요소 개수 세기
    for (start = 1; start <= vertex; start++) {
        //만약 지금 정점이 방문안한 정점이라면
        if (!check[start]) {
            //dfs로 start 정점과 연결된 정점들을 표시
            dfs(start);
            count++; //연결 요소 그래프 개수 추가
        }
    }

    cout << count;
    return 0;
}