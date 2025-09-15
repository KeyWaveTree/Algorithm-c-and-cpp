#include<iostream>
#include<vector>

using namespace std;

vector<vector<int >> adjacencyList;
vector<bool> disable;
int n, node, delNode;
int cnt;

//문제 풀이
//1. 인접리스트나 인접행렬을 만들어서 트리의 관계를 표현한다.
//2. 삭제할 노드를 순회하면서 노드를 순차적으로 지운다. dfs로 방문해도 되고 순회알고리즘을 만들어서 삭제해도 괜찮다.
//3. 삭제를 다 완료한 후 -1이 표시된 곳 부터 dfs를 작업한다.
//4. dfs의 재귀 노드에서 다음에 순차적으로 방문할 노드가 주어진다면 dfs로 방문하고
//   방문할 노드가 주어져 있지 않으면 리프노드라고 판단한다.

void delDfs(int start) {
    //삭제할 노드와 그들의 자식들을 모두 비활성화처리한다.
    disable[start] = true;
    for (int end: adjacencyList[start]) delDfs(end);
}

void dfs(int start) {
    //현재 위치 노드가 비활성화 표시된 노드라면
    if (disable[start]) return;

    bool flag = false;//한번이라도 dfs를 통해 다른 노드로 이동했는가를 확인하는 표시
    //반복할 대상이 없으면 리프 노드라는 뜻이다.
    for (int end: adjacencyList[start]) {
        //만약 비활성화 표시한 노드가 아니면 dfs를 한다.
        if (!disable[end]) {
            flag = true;
            dfs(end);
        }
    }

    //반복을 다하고나서 한번이라도 dfs를 돌리지 않았다면 리프노드 누적
    if (!flag) cnt++;

}

int main() {
    int i, start;

    cin >> n;

    //동적 할당
    disable.assign(n, false);
    adjacencyList.resize(n + 1);

    //단 방향 인접리스트 정보 삽입
    for (i = 0; i < n; i++) {
        cin >> node;
        if (node == -1) {
            start = i;
            continue;
        }
        adjacencyList[node].push_back(i);
    }
    cin >> delNode;

    delDfs(delNode);
    dfs(start);
    cout << cnt;

    return 0;
}
