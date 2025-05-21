#include<iostream>
#include<queue>

using namespace std;


char map[101][101];
char check[101][101];
char checker;
short n;

struct point {
    int x;
    int y;
};


void bfs(short x, short y, char marker);

int main() {
    short i, j, k;
    short cnt;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (k = 0; k < 2; k++) {
        checker++;
        cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (check[i][j] == checker) continue;
                bfs(j, i, map[i][j]);
                cnt++;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (map[i][j] == 'G') map[i][j] = 'R';
            }
        }

        cout << cnt << ' ';
    }
    return 0;
}

void bfs(short x, short y, char marker) {
    short i;
    short vx[4] = {0, 1, 0, -1};
    short vy[4] = {1, 0, -1, 0};

    short posx, posy;
    point empty = (point) {x, y};
    queue<point> q;

    q.push(empty);

    while (true) {
        if (q.empty()) break;
        empty = q.front();
        q.pop();

        x = empty.x;
        y = empty.y;

        for (i = 0; i < 4; i++) {
            posx = vx[i] + x;
            posy = vy[i] + y;

            if (posx >= n || posx < 0 || posy >= n || posy < 0) continue;

            if (map[posy][posx] == marker && check[posy][posx] != checker) {
                q.push((point) {posx, posy});
                check[posy][posx] = checker;
            }

        }
    }


}