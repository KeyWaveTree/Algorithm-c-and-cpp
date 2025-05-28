#include<iostream>
#include<queue>

using namespace std;

struct point {
    int x;
    int y;
};

int map[101][101];
int marker[101][101];
int n, m;
int checker;

void bfs(int x, int y);

int main() {
    int i, j;
    int cnt;
    int time = 0;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {

        checker--;
        bfs(0, 0);
        time++;


        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (marker[i][j] >= 2) map[i][j] = 0;
                marker[i][j] = 0;
            }
        }
        cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (map[i][j] == 0) cnt++;
            }
        }

        if (cnt == n * m) break;

    }

    cout << time;

}

void bfs(int x, int y) {
    int vx[4] = {0, -1, 0, 1};
    int vy[4] = {1, 0, -1, 0};
    int posx, posy;
    int i;
    marker[y][x] = checker;
    queue<point> q;
    point empty = {x, y};
    point item;

    q.push(empty);

    while (true) {
        if (q.empty()) break;
        item = q.front();
        q.pop();

        x = item.x;
        y = item.y;

        for (i = 0; i < 4; i++) {
            posx = vx[i] + x;
            posy = vy[i] + y;
            if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;

            if (map[posy][posx] == 0 && marker[posy][posx] != checker) {
                q.push((point) {posx, posy});
                marker[posy][posx] = checker;
            } else if (map[posy][posx] == 1) marker[posy][posx]++;
        }
    }
}