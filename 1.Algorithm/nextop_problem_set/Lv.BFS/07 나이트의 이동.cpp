#include<iostream>
#include<vector>

using namespace std;


typedef struct point {
    int x;
    int y;
    int cnt;
} point;

int l;
int front, rear;
point start, stop;
vector<point> knightQueue;
vector<vector<int> > check;

//체크 보드에 표시할 번호
int bfs(int recode);

int main() {
    knightQueue.assign(301 * 301 + 2, (point) {0, 0, 0});
    int t;
    int i;

    cin >> t;
    check.resize(301);
    for (i = 0; i <= 300; i++) {
        check[i].assign(301, 0);
    }

    for (i = 1; i <= t; i++) {
        front = 0, rear = 2;
        cin >> l;
        cin >> start.x >> start.y;
        cin >> stop.x >> stop.y;
        knightQueue[rear - 1] = start;
        check[start.y][start.x] = i;
        cout << bfs(i) << '\n';
    }
}

int bfs(int recode) {
    int x, y, cnt;
    int posX, posY;
    int i;
    int vx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int vy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    while (true) {
        if (front == rear) break;
        front++;

        x = knightQueue[front].x;
        y = knightQueue[front].y;
        cnt = knightQueue[front].cnt;

        if (x == stop.x && y == stop.y) break;

        for (i = 0; i < 8; i++) {
            posX = vx[i] + x;
            posY = vy[i] + y;

            if (posX >= l || posY >= l || posX < 0 || posY < 0) continue;
            if (check[posY][posX] != recode) {
                knightQueue[rear].x = posX;
                knightQueue[rear].y = posY;
                knightQueue[rear].cnt = cnt + 1;
                check[posY][posX] = recode;
                rear++;
            }
        }
    }

    return cnt;
}