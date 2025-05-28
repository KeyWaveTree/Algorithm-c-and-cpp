#include<iostream>
#include<queue>

using namespace std;

struct point {
    int x;
    int y;
    int cnt;
};

int n, m;
int map[1001][1001];
int check[1001][1001];

void bfs(int x, int y) {
    int vx[4] = {0, 1, 0, -1};
    int vy[4] = {-1, 0, 1, 0};

    int posx, posy;
    queue<point> q;
    point empty = {x, y, 0};
    q.push(empty);
    int cnt;

    while (true) {
        if (q.empty()) break;
        empty = q.front();
        q.pop();

        x = empty.x;
        y = empty.y;
        cnt = empty.cnt;
        map[y][x] = cnt;

        for (int i = 0; i < 4; i++) {
            posx = vx[i] + x;
            posy = vy[i] + y;

            if (posx < 0 || posx >= m || posy < 0 || posy >= n) continue;

            if (map[posy][posx] != 0 && check[posy][posx] == 0) {
                q.push((point) {posx, posy, cnt + 1});
                check[posy][posx] = 1;
            }
        }

    }
}

int main() {
    int i, j;
    int startx, starty;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) map[i][j] = -1;
            else if (map[i][j] == 2) {
                starty = i;
                startx = j;
            }
            if (map[i][j] == 0) check[i][j] = -1;
        }
    }

    bfs(startx, starty);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}