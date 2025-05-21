#include<iostream>
#include<vector>

using namespace std;

typedef struct info
{
    int pos;
    int time;

}info;

vector<bool> check;
vector<info> probQueue;

int close;
int map;

int bfs(int start);

int main()
{
    int n, k;
    int i;

    cin>> n>> k;

    //동생의 위치 전역변수로 저장
    map = k;

    //둘 중 큰 값만큼 동적할당 하여 매모리를 아끼겠다.
    close = max(n+1, k+1);
    check.assign(close, false);
    probQueue.assign(close, (info){0, 0});

    cout << bfs(n);
}

int bfs(int start)
{
    int front = 0, rear = 0;
    int curPos, curTime;
    int time = 100001; //최악의 시간소모보다 큰 값을 넣는다.

    rear++;
    check[start] = true;
    probQueue[rear].pos = start;

    while (true)
    {
        if (front == rear) break;
        front++;

        curPos = probQueue[front].pos;
        curTime = probQueue[front].time;

        //현재 위치가 동생의 위치이고 현재 찾은 횟수보다 더 빠르게 찾았다면
        if (curPos == map && time > curTime) {
            //소모한 시간을 시간변수에 저장한다.
            time = curTime;
            //break한다. 무조건 최단 시간이 성립.
            break;

        }

        //현재 위치 + 1 위치가 범위를 벗어나지 않고 방문한 지역이 아닐때만 queue에다 저장한다.
        if (curPos + 1 <= close && !check[curPos + 1]) {
            rear++;
            check[curPos + 1] = true;
            probQueue[rear] = (info) {curPos + 1, curTime + 1};
        }
        //현재 위치 - 1 위치가 범위를 벗어나지 않고 방문한 지역이 아닐때만 queue에다 저장한다.
        if (curPos - 1 >= 0 && !check[curPos - 1]) {
            rear++;
            check[curPos - 1] = true;
            probQueue[rear] = (info) {curPos - 1, curTime + 1};
        }

        //현재 위치 * 2 위치가 범위를 벗어나지 않고 방문한 지역이 아닐때만 queue에다 저장한다.
        if (curPos * 2 <= close && !check[curPos * 2]) {
            rear++;
            check[curPos * 2] = true;
            probQueue[rear] = (info) {curPos * 2, curTime + 1};
        }
    }
    return time;
}