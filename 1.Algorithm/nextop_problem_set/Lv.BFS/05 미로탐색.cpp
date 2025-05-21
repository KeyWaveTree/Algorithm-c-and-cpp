#include<iostream>
#include<vector>

using namespace std;

typedef struct point {
    int x, y;
    int cnt;
} point;

vector<vector<int> > map;
vector<vector<bool> > check;

int n, m;

int bfs(int x, int y);


int main() {
    string line;
    int cnt;
    int i, j;
    cin >> n >> m;

    map.resize(n);
    check.resize(n);
    for (i = 0; i < n; i++) {
        map[i].assign(m, 0);
        check[i].assign(m, false);
    }

    for (i = 0; i < n; i++) {
        cin >> line;
        for (j = 0; j < line.length(); j++) {
            map[i][j] = (int) (line[j] - '0');
        }
    }

    cnt = bfs(0, 0);

    cout << cnt;
    return 0;
}

int bfs(int x, int y) {
    vector<point> queue;
    int vx[4] = {0, -1, 0, 1};
    int vy[4] = {-1, 0, 1, 0};
    int posX, posY;
    int cnt = 1;
    int i;
    queue.assign(n * m + 1, (point) {0, 0});

    int front = 0, rear = 1;
    check[y][x] = true;
    queue[rear] = (point) {x, y, cnt};
    rear++;

    while (true) {
        if (front == rear) break;
        front++;

        x = queue[front].x;
        y = queue[front].y;
        cnt = queue[front].cnt;
        if (x == m - 1 && y == n - 1) break;

        for (i = 0; i < 4; i++) {
            posX = vx[i] + x;
            posY = vy[i] + y;
            if (posX >= m || posX < 0 || posY >= n || posY < 0) continue;
            if (map[posY][posX] == 1 && !check[posY][posX]) {
                queue[rear] = (point) {posX, posY, cnt + 1};
                check[posY][posX] = true;
                rear++;
            }
        }

    }

    return cnt;
}