#include<iostream>
#include<queue>

using namespace std;

struct point {
    int x, y;
};

int map[101][101];
int check[101][101];
int checker;
int n, m;

void bfs(int x, int y);

int main() {
    int i, j;
    int temp1, temp2;
    int time = 0;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        temp1 = 0;
        temp2 = 0;

        checker--;
        bfs(0, 0);

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {

                if (check[i][j] >= 1) {
                    map[i][j] = 0;
                    temp1++;
                }
                if (map[i][j] == 0) temp2++;
            }
        }

        time++;

        //만약 현재 치즈 조각이 다 없어졌다면
        if (temp2 == n * m) break;
    }

    cout << time<< '\n';
    cout << temp1;

}

void bfs(int x, int y) {
    queue<point> q;
    point empty = {x, y};
    int i, posx, posy;
    int vx[4] = {0, 1, 0, -1};
    int vy[4] = {1, 0, -1, 0};
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

            if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;

            if (map[posy][posx] == 0 && check[posy][posx] != checker) {
                q.push((point) {posx, posy});
                check[posy][posx] = checker;
            } else if (map[posy][posx] == 1) {
                check[posy][posx]++;
            }

        }
    }

}