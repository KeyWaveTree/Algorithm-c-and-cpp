#include<iostream>

using namespace std;

//문제에서 주어진 아기상어의 이동 방법을 bfs로 구현하는 문제
//bfs도는 순서가 중요한 문제이다.
//ㄴ 거리가 가까운 물고기가 여러마리일시 가장 왼쪽에 있는 물고기를 선택한다 했으니
//ㄴ 좌, 아래, 위, 오른쪽 순서대로 우선순위를 지정하여 bfs를 보아야 한다. ->
//   이렇게 한다면 거리가 같은 물고기를 복잡한 계산 필요없이 구현 로직상으로 방문할 그 즉시 선택할 수 았가 때문
//bfs로 아기 상어가 물고기를 먹을 수 있을때의 지점을 알아낸다면 그 즉시 bfs로 구한 이동 횟수를 어느 변수에다가 합하여 저장하고 잠시 탐색을 종료한다.
//물고기를 먹은 후 아기상어가 먹은 물고기 개수를 판단하여 아기상어의 크기를 변경 후
//방문한 지점 초기화 후 지금 물고기 먹은 위치에서 부터 bfs를 다시 시작한다. 이 과정을 물고기를 먹을 수 없을때까지 반복한다.
//만약 더이상 물고기를 먹지 못한다면 bfs로 탐색을 하지 못한다면 bfs를 종료하고 지금까지 합한 이동횟수를 출력한다.


struct info //아기상어가 이동한 공간 정보를 담는 자료 형태
{
    short x; //현재 아기상어의 x좌표
    short y; //현재 아기상어의 y좌표
    short step; //이기상어의 이동 횟수
};

short n;//바다의 크기
short shark = 2;//아기상어의 크기
short move;//아기상어가 움직인 횟수
short map[20][20]; //공간의 정보 표시

short checker; //표시 숫자
short check[20][20]; //방문 표시 목록

info queueTable[400 + 1];

info bfs(info start);

int main() {
    int i, j;
    int x, y;
    
    cin >> n;
    //지도 입력
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                x = j;
                y = i;
            }
        }
    }

}

info bfs(info start) {
    short front = 0, rear = 1;
    short vx[4] = {-1, 0, 0, 1};
    short vy[4] = {0, 1, -1, 0};
    short posx, posy;
    queueTable[rear] = start;

    while (true) {

    }

}
