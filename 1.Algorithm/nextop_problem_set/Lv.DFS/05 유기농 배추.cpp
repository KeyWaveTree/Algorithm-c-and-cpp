#include<iostream>

#include <vector>

using namespace std;

vector<vector<bool>> cabbageMap, check;
int vx[4] = {0, -1, 0, 1};
int vy[4] = {-1, 0, 1, 0};

int n, m;

void dfs(int x, int y) {
    int i = 0;
    int posx, posy;

    //만약 지금위치를 한번이라도 방문했다면 종료
    if (check[y][x]) return;

    //그게 아니라면 현재 위치는 지금 방문한것이 처음이므로 체크표시
    check[y][x] = true;

    //상하좌우로
    for (i = 0; i < 4; i++) {
        posx = x + vx[i];
        posy = y + vy[i];
        //만약 지금 갈려고 하는 위치 값이 지도 밖 범위라면 dfs를 하지 않는다.
        if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;
        //갈 수 있는 인접된 공간이 배추가 심어져 있는 땅이라면
        if (cabbageMap[y][x]) dfs(posx, posy);
    }
}

int main() {
    int t;
    int p;
    int i, j, k;
    int x, y;
    int count = 0;

    cin >> t;
    for (i = 0; i < t; i++) {
        //가로, 세로, 배추 위치
        cin >> m >> n >> p;

        //세로 크기 만큼 지도/확인표시 동적할당(인덱스 범위)
        cabbageMap.resize(n);
        check.resize(n);
        //가로 크기 만큼 지도/확인표시 동적할당
        for (j = 0; j < n; j++) {
            cabbageMap[j].assign(m, false);
            check[j].assign(m, false);
        }

        //좌표 개수만큼 좌표 입력
        for (j = 0; j < p; j++) {
            cin >> x >> y;
            //입력한 좌표만 배추 심었다는 표시
            cabbageMap[y][x] = true;
        }

        count = 0;
        //지도를 돌며 현재 위치된 요소가 true이고 방문을 한번도 안한 구역일때 dfs를 한다.
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (cabbageMap[j][k] && !check[j][k]) {
                    dfs(k, j);
                    count++;
                }
            }
        }

        //배추 흰지렁이 개수 출력
        cout << count << '\n';

        //지도 및 확인 표시 초기화
        //잉여 공간이 남지 않기 위한 메모리 해제
        vector<vector<bool> >().swap(cabbageMap);
        vector<vector<bool> >().swap(check);
    }
}