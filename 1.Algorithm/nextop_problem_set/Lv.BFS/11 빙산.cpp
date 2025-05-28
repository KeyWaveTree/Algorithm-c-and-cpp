#include<iostream>
#include<queue>

using namespace std;

//좌표 구조체
struct point {
    short x;
    short y;
    char tag; // 바다 및 빙산을 구별하기 위한 태그
};

//지도의 최대 범위
short map[301][301];
short check[301][301];
//행개수 열개수
short row, col;
//바다의 체크 번호를 음수로 감소시킨다. => 체크 배열를 초기화 안하고 빙산과 구별하기 위함
short ocean;
//빙산의 체크 번호를 양수로 증가시킨다. => 이유 바다의 체크번호 선언 이유와 같음.
short ice;


void bfs(short x, short y, char tag);

int main() {
    short i, j;
    short year = 0;
    short cnt = 0;


    //입력
    cin >> row >> col;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        year++;
        ocean--;
        ice++;
        cnt = 0;
        //바다에서 bfs를 하여 인접한 빙산의 크기 감소
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                //만약 현재 위치가 바다이고 현재 바다 체크값을 가지고 있지 않다면 이위치에서 부터 바다를 방문한다.
                if (map[i][j] == 0 && check[i][j] != ocean) {
                    bfs(j, i, 'o');
                }
            }
        }

        
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                if (map[i][j] > 0 && check[i][j] != ice) {
                    bfs(j, i, 'i');
                    cnt++;
                }
            }
        }

        if (cnt >= 2) {
            cout << year;
            break;
        } else if (cnt == 0) {
            cout << 0;
            break;
        }
    }

    return 0;
}


void bfs(short x, short y, char tag) {
    short i;
    short vx[4] = {0, 1, 0, -1};
    short vy[4] = {1, 0, -1, 0};

    short posX, posY;

    queue<point> q;//큐
    point empty = {x, y, tag};
    if (tag == 'o') check[y][x] = ocean;
    else if (tag == 'i') check[y][x] = ice;
    q.push(empty);


    while (true) {
        if (q.empty()) break;
        empty = q.front();
        q.pop();

        x = empty.x;
        y = empty.y;
        tag = empty.tag;

        for (i = 0; i < 4; i++) {
            posX = vx[i] + x;
            posY = vy[i] + y;
            if (posX > col || posX <= 0 || posY > row || posY <= 0) continue;

            //현재 bfs 태그가 o 이고 인접한 위치가 바다이고 방문을 안한 바다이면
            if (tag == 'o' && map[posY][posX] == 0 && check[posY][posX] != ocean) {
                //다음 바다의 위치 저장
                q.push((point) {posX, posY, tag});
                //다음 바다의 위치 방문 표시
                check[posY][posX] = ocean;
            }
            //현재 bfs 태그가 o 이고 인접한 위치가 양수이면(빙하이면)
            if (tag == 'o' && map[posY][posX] > 0) {
                //인접되어 있는 빙하 값 감소
                map[posY][posX]--;
                //만약 지금 감소된 빙하가 바다가 되었다면 근처 빙하에게 반영을 안하기 위해 방문표시를 한다.
                if (map[posY][posX] == 0) check[posY][posX] = ocean;
            }
            //현재 태그가 'i'이고 인접한 위치가 빙하이고 방문을 안한 빙하이면 그룹화 표시를 한다.
            if (tag == 'i' && map[posY][posX] > 0 && check[posY][posX] != ice) {
                q.push((point) {posX, posY, tag});
                check[posY][posX] = ice;
            }


        }

    }

}