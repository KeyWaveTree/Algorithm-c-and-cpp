#include<iostream>
#include<queue>

using namespace std;

struct point {
    int pos;
    int cnt;
};

bool check[100001];

int bfs(int start, int end) {
    point item = {start, 0};
    queue<point> q;
    int cnt;
    int time = 100001;

    q.push(item);

    //총합 코스트 3
    //순간이동 코스트 - 2
    //좌우 이동 코스트 - 1

    while (!q.empty()) {
        item = q.front();
        q.pop();

        start = item.pos;
        cnt = item.cnt;

        //만약 술래의 위치가 동생의 위치와 똑같고 지금까지 찾은 시간보다 더 빠르게 찾았다면 최단시간을 갱신한다.
        if (start == end && time > cnt) {
            time = cnt;
        }

        //*2 순간이동을 했을때 위치가 10만 이하이고 현재 위치에서 순간이동용 체크표시를 안했을때만 bfs를 작동하게끔 한다.
        if (start * 2 <= 1e+5 && !check[start * 2]) {
            q.push((point) {start * 2, cnt});
            check[start * 2] = true;
        }
        //-1 이동을 했을대 위치가 0 이상이고 현재 위치에서 방문 체크를 안했을때만 bfs를 작동하게끔한다.
        if (start - 1 >= 0 && !check[start - 1]) {
            q.push((point) {start - 1, cnt + 1});
            check[start - 1] = true;
        }
        //+1 이동을 했을때 위치가 10만 이하이고 현재 위치 에서 방문 체크를 안했을때만 bfs를 작동하게끔한다.
        if (start + 1 <= 1e+5 && !check[start + 1]) {
            q.push((point) {start + 1, cnt + 1});
            check[start + 1] = true;
        }

    }

    return time;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}