#include<iostream>

//dfs 설명: 순차적으로
using namespace std;

int n; //게임 구역의 크기
int map[3 + 1][3 + 1]; //게임 구역
bool check[3 + 1][3 + 1];//게임 구역 방문 기록판
bool det = false; //승리 판별 - 기본적으로 도달 할 수 없다고 가정

//점프 게임
void dfs(int x = 1, int y = 1) {

    //만약 현재 위치 y, x 위치가 -1을 가지고 있다면
    if (map[y][x] == -1) {
        //승리 표시
        det = true;
    }

    //만약 현재 위치가 방문했던 위치이면
    //또는 승리 표시를 가지고 있다면 dfs 함수 종료
    if (check[y][x] || det) return;

    //현재 위치 체크 표시
    check[y][x] = true;


    //만약 현재 위치에서 구역에 표시된 수치만큼 아래로 움직일 수 있다면(지도 범위내에서)
    if (y + map[y][x] <= n) dfs(x, y + map[y][x]); //그러한 수치만큼 움직인다.
    //만약 현재 위치에서 구역에 표시된 수치만큼 오른쪽으로 움직일 수 있다면 (지도 범위내에서)
    if (x + map[y][x] <= n) dfs(x + map[y][x], y); //그러한 수치만큼 움직인다.

    //현재 위치 종료시 방문 표시 해제
    check[y][x] = false;
}

int main() {
    int i, j;

    //데이터 입력
    cin >> n;
    for (i = 1; i <= n; i++) {//행
        for (j = 1; j <= n; j++) {//열
            cin >> map[i][j];
        }
    }

    //dfs시작위치 1, 1에서 최종적으로 -1로 표시된 구역으로 갈 수 있는지 갈 수 없는지 확인
    dfs();
    //만약 결과가 true이면 HaruHaru 출력, false이면 Hing 출력
    (det) ? cout << "HaruHaru" : cout << "Hing";

    return 0;
}