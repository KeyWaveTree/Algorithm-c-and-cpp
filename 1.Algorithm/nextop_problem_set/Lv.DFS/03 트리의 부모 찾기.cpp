#include<iostream>
#include<vector>

using namespace std;

int node;
vector<int> check;
vector<vector<int> > adjacencyList;

void dfs(int start) {

    //인접 리스트로 다음에 갈 방문노드를 확인한다.
    for (auto end: adjacencyList[start]) {
        //만약 지금 시작할 노드 번호를 방문 안했을때만 dfs를 시작한다.
        if (check[end] == 0) {
            check[end] = start; //자신이 방문할 노드의 부모는 start이다.
            dfs(end); //dfs시작
        }
    }
}


int main() {
    int i;
    int start, end;

    cin >> node;
    check.assign(node + 1, 0);
    adjacencyList.resize(node + 1);

    for (i = 1; i < node; i++) {
        cin >> start >> end;
        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }

    check[1] = 1;//1노드의 부모는 자기 자신
    dfs(1);
    for (i = 2; i <= node; i++) {
        cout << check[i] << '\n';
    }

    return 0;
}