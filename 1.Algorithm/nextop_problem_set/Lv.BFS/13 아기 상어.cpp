#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//문제에서 주어진 아기상어의 이동 방법을 bfs로 구현하는 문제
//bfs도는 순서가 중요한 문제이다.
//ㄴ 거리가 가까운 물고기가 여러마리일시 가장 위체 있는 물고기를 기준으로 그러한 물고기가 여러마리라면 가장 왼쪽에 있는 물고기를 먹는다.
//ㄴ 이러한 코드 처리 구조는 bfs에서 우선순위큐를 사용하거나
//ㄴ bfs를 처리시 먹을 수 있는 물고기를 리스트/배열에다가 저장하여 bfs를 종료후 조건에 맞는 물고기를 정렬후 저장한다온다.
//ㄴ 먹을 수 있는 물고기를 바다에표시하여 왼쪽 위에서부터 오른쪽아랫순으로 가장 먼저 찾은것을 선택한다.
//bfs로 아기 상어가 물고기를 먹을 수 있을때의 지점을 알아낸다면 그 즉시 bfs로 구한 이동 횟수를 어느 변수에다가 합하여 저장하고 잠시 탐색을 종료한다.
//물고기를 먹은 후 아기상어가 먹은 물고기 개수를 판단하여 아기상어의 크기를 변경 후
//방문한 지점 초기화 후 지금 물고기 먹은 위치에서 부터 bfs를 다시 시작한다. 이 과정을 물고기를 먹을 수 없을때까지 반복한다.
//만약 더이상 물고기를 먹지 못한다면 bfs로 탐색을 하지 못한다면 bfs를 종료하고 지금까지 합한 이동횟수를 출력한다.


struct info //아기상어가 이동한 공간 정보를 담는 자료 형태
{
    short x; //현재 아기상어의 x좌표
    short y; //현재 아기상어의 y좌표
    short step; //이기상어의 이동 횟수
};

short n;//바다의 크기
short shark = 2;//아기상어의 크기
short sharkMove;//아기상어가 움직인 횟수
short map[20][20]; //공간의 정보 표시

short checker; //표시 숫자
short check[20][20]; //방문 표시 목록

bool compare(const info &first, const info &second);

void bfs(info start, vector<info> &nominee);

int main() {
    short i, j;
    short x, y;
    short count = 0;
    vector<info> nominee;

    info empty = {0, 0, 0}, item;
    cin >> n;
    //지도 입력
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
            //만약 입력받은 값이 아기 상어 위치라면
            if (map[i][j] == 9) {
                x = j, y = i;//아기 상어의 위치를 저장
                map[i][j] = 0;//지도 표시를 0으로 해준다. 아기상어 방문시 다시 이 위치를 이용할 수 있기 때문에
            }
        }
    }
    while (true) {
        empty.x = x;
        empty.y = y;
        bfs(empty, nominee);//현재 위치에서 가장 가까운 먹이의 위치를 뽑아낸다

        sort(nominee.begin(), nominee.end(), compare);

        //더이상 먹을 물고기가 없으면 종료한다.   .
        if (nominee.size() == 0) break;
        item = nominee[0];
        count++;// 물고기 먹은 횟수 증가
        //만약 상어의 크기가 현재 물고기 먹은 횟수와 일치한다면
        if (shark == count) {
            shark++;
            count = 0;
        }
        x = item.x;
        y = item.y;
        map[y][x] = 0;
        sharkMove += item.step;

        //vector 삭제
        nominee.clear();
        vector<info>().swap(nominee);
    }

    cout << sharkMove;
    return 0;
}

bool compare(const info &first, const info &second) {
    // 우선순위.
    // 1.가장 가깝다면
    // 2.거리가 같은것이 있을시 물고가 위에 있는것을 기준으로
    // 3.높이도 같을시 가장 왼쪽을 기준으로 정렬
    if (first.step == second.step) {
        if (first.y == second.y) return first.x < second.x;
        else return first.y < second.y;
    } else return first.step < second.step;
}

void bfs(info start, vector<info> &nominee) {
    info queueTable[400 + 1];
    info item = {0, 0, 0};
    short front = 0, rear = 1;
    //위, 왼쪽, 오른쪽,아래
    short vx[4] = {0, -1, 1, 0};
    short vy[4] = {-1, 0, 0, 1};
    short posx, posy;
    short i;

    checker++;//현재 체크 표시 기준 숫자 증가
    queueTable[rear] = start;//일할 목록 대기칸에 현재 작업 시작 위치 저장
    check[start.y][start.x] = checker; //미리 현재 작업 시작 위치 방문 기록 표시

    while (true) {
        if (front == rear) break;
        front++;

        item = queueTable[front];
        //만약 지금 현재 위치값에 물고기가 있고 아기상어의 크기보다 작다면 가장 빠르게 먹을 수 있는 물고기 -> bfs 종료
        if (map[item.y][item.x] != 0 && map[item.y][item.x] < shark) {
            nominee.push_back(item);

        }

        for (i = 0; i < 4; i++) {
            posx = item.x + vx[i];
            posy = item.y + vy[i];

            if (posx >= n || posx < 0 || posy >= n || posy < 0) continue;

            //bfs 이동
            //이동할 map 위치가 0이거나 아기 상어 크기보다 작거나 같을때 이동 그리고 방문안한 지역일때
            if (check[posy][posx] != checker && (map[posy][posx] == 0 || map[posy][posx] <= shark)) {
                rear++;
                check[posy][posx] = checker;
                queueTable[rear].x = posx;
                queueTable[rear].y = posy;
                queueTable[rear].step = item.step + 1;
            }

        }
    }


}
