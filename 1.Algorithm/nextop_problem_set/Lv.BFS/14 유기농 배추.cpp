#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<bool> > cabbageMap, check;

int m, n;
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {

    typedef pair<int, int> point; //페어 자료형을 point로 변환
    point item(x, y);//현재 위치
    queue<point> cabbageQueue;//처리할 일을 기록할 큐

    int posx, posy;
    int i;

    //현재 위치 큐에다가 삽입
    cabbageQueue.push(item);
    //현재위치 방문 표시
    check[y][x] = true;

    //bfs시작 - 큐에 더이상 할 작업이 없을때 까지 반복해라 일종의 rear
    while (!cabbageQueue.empty()) {
        //큐 front에 있는 처리할 정보를 담는다.
        item = cabbageQueue.front();
        cabbageQueue.pop();//front 정보 제거

        //현재 x, y 위치를 저장한다.(굳이 안하고 item.first, item.second로 해도 상관 없음)
        x = item.first;
        y = item.second;

        //현재 item 칸에서 상하좌우로 인접된 공간에 갈 수 있는지 갈 수 없는지 확인한다.
        for (i = 0; i < 4; i++) {
            posx = x + vx[i];
            posy = y + vy[i];
            if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;
            if (cabbageMap[posy][posx] && !check[posy][posx]) {
                item.first = posx;
                item.second = posy;
                cabbageQueue.push(item);
                check[posy][posx] = true;
            }
        }


    }
}

int main() {
    int t, p;
    int x, y;
    int i, j, k;

    int count;

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
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (cabbageMap[j][k] && !check[j][k]) {
                    bfs(k, j);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}