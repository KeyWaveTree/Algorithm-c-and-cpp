#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct point {
    int x;
    int y;
};

int n, m;
vector<vector<int> > map;
vector<vector<bool> > check;
queue<point> mapQueue;

int bfs(int x, int y) {
    int vx[4] = {0, 1, 0, -1};
    int vy[4] = {1, 0, -1, 0};
    int posx, posy;
    int cnt = 0;
    point front;

    check[y][x] = 1;
    mapQueue.push((point) {x, y});

    while (!mapQueue.empty()) {
        front = mapQueue.front();
        mapQueue.pop();

        //도연이가 만난 사람이 있는지 없는지 확인한다.
        //지도의 현재 위치값을 더한다.(1-> 사람, 0 -> 빈 공간)
        cnt += map[front.y][front.x];

        for (int i = 0; i < 4; i++) {
            posx = vx[i] + front.x;
            posy = vy[i] + front.y;

            //만약 다음 이동할 지역이 지도 공간을 벗어났다면 건너뛰어라
            if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;
            //만약 다음 이동할 지역이 방문안한 지역이고 벽이 아나리면 다음에 방문할 지역이다.
            if (map[posy][posx] != -1 && check[posy][posx] == 0) {
                mapQueue.push((point) {posx, posy});
                check[posy][posx] = 1;
            }
        }

    }

    return cnt;
}


int main() {
    int i, j;
    int x, y;
    int cnt = 0;
    string in;

    cin >> n >> m;

    map.resize(n);
    check.resize(n);


    //지도 정보 입력 처리
    for (i = 0; i < n; i++) {
        map[i].assign(m, 0);
        check[i].assign(m, 0);
        cin >> in;//n번 만큼 맵 정보 문자열 입력
        for (j = 0; j < m; j++) {
            //문자열 요소를 순서대로 지정하여 사람인지 벽인지 도연인지 확인
            if (in[j] == 'P') map[i][j] = 1;
            else if (in[j] == 'X') map[i][j] = -1;
            else if (in[j] == 'I') {
                x = j;
                y = i;
            }
        }
    }
    cnt = bfs(x, y);
    (cnt != 0) ? cout << cnt : cout << "TT";

    return 0;
}