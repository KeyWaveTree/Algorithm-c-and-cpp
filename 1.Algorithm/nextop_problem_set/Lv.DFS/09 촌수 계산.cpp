#include<iostream>
#include<vector>

using namespace std;

int people, relation;
int cur1, cur2;
int dis;
bool exist;

vector<vector<bool> > adjacencyMatrix;
vector<bool> check;

void dfs(int start, int count = 0) {
    //지금 현재 위치가 check 표시된 노드라면 현재 재귀 노드 종료
    //혹은 이미 자신이 찾아야 하는 위치를 찾았다면 종료
    if (check[start] || exist) return;

    //만약 현재 위치가 자신이 찾고 있는 cur2 변수(친척인지 확인하고 싶은 값)라면
    if (start == cur2) {
        exist = true; //친척 존재 여부 true로 바꾸고
        dis = count;//현재 까지 dfs로 이동한 거리를 저장한다.
        return;//dfs 노드 종료
    }

    //현재 start(사람:노드)위치를 check표시 한다.
    check[start] = true;

    for (int end = 1; end <= people; end++) {
        //만약 adjacencyMatrix에서 지정한 위치를 갈 수 있다면 dfs노드는 생성후 방문한다.
        if (adjacencyMatrix[start][end]) {
            //다음 위치로 갈 수 있는 노드 수치를 전달, 현재 방문 횟수 증가
            dfs(end, count + 1);
        }
    }

}

int main() {

    int node, edge;//노드 및, 간선 반복수
    int start, end;

    cin >> people; //총 사람 노드의 개수
    cin >> cur1 >> cur2; //촌수 계산할 두 사람의 정보
    cin >> relation; //graph edge 개수

    //인접 행렬 동적 할당
    adjacencyMatrix.resize(people + 1);
    //방문기록 확인 check vector 동적 할당
    check.assign(people + 1, false);
    for (node = 1; node <= people; node++) {
        adjacencyMatrix[node].assign(people + 1, false);
    }

    //간선 정보 입력
    for (edge = 1; edge <= relation; edge++) {
        cin >> start >> end;
        adjacencyMatrix[start][end] = adjacencyMatrix[end][start] = true;
    }

    //dfs 시작
    dfs(cur1);

    //dfs가 끝났어도 exist가 false 이면 -1출력(친척관계가 아니다라는 표시)
    if (!exist) cout << -1;
        //false가 아닐시 답을 출력
    else cout << dis;

    return 0;
}