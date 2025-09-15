#include<iostream>
#include<vector>

using namespace std;

int vx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int vy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int w, h;

vector<vector<bool>> map, check;

void dfs(int x, int y) {
    int posx, posy;
    int i;

    if (check[y][x]) return;

    check[y][x] = true;

    for (i = 0; i < 8; i++) {
        posx = x + vx[i];
        posy = y + vy[i];
        if (posx >= w || posx < 0 || posy >= h || posy < 0) continue;

        if (map[y][x]) dfs(posx, posy);
    }

}

int main() {
    int i, j;
    int cnt;
    bool item;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        //동적할당 및 입력
        map.resize(h);
        check.resize(h);
        for (i = 0; i < h; i++) {
            map[i].assign(w + 1, false);
            check[i].assign(w + 1, false);
            for (j = 0; j < w; j++) {
                cin >> item;
                map[i][j] = item;
            }
        }

        cnt = 0;
        //dfs
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                //만약 지금 현재 위치가 섬이고 한번도 방문을 안했다면
                if (map[i][j] && !check[i][j]) {
                    dfs(j, i);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

    }

    return 0;
}