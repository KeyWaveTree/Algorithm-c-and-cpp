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

    //������ ��ġ ���������� ����
    map = k;

    //�� �� ū ����ŭ �����Ҵ� �Ͽ� �Ÿ𸮸� �Ƴ��ڴ�.
    close = max(n+1, k+1);
    check.assign(close, false);
    probQueue.assign(close, (info){0, 0});

    cout << bfs(n);
}

int bfs(int start)
{
    int front = 0, rear = 0;
    int curPos, curTime;
    int time = 100001; //�־��� �ð��Ҹ𺸴� ū ���� �ִ´�.

    rear++;
    check[start] = true;
    probQueue[rear].pos = start;

    while (true)
    {
        if (front == rear) break;
        front++;

        curPos = probQueue[front].pos;
        curTime = probQueue[front].time;

        //���� ��ġ�� ������ ��ġ�̰� ���� ã�� Ƚ������ �� ������ ã�Ҵٸ�
        if (curPos == map && time > curTime) {
            //�Ҹ��� �ð��� �ð������� �����Ѵ�.
            time = curTime;
            //break�Ѵ�. ������ �ִ� �ð��� ����.
            break;

        }

        //���� ��ġ + 1 ��ġ�� ������ ����� �ʰ� �湮�� ������ �ƴҶ��� queue���� �����Ѵ�.
        if (curPos + 1 <= close && !check[curPos + 1]) {
            rear++;
            check[curPos + 1] = true;
            probQueue[rear] = (info) {curPos + 1, curTime + 1};
        }
        //���� ��ġ - 1 ��ġ�� ������ ����� �ʰ� �湮�� ������ �ƴҶ��� queue���� �����Ѵ�.
        if (curPos - 1 >= 0 && !check[curPos - 1]) {
            rear++;
            check[curPos - 1] = true;
            probQueue[rear] = (info) {curPos - 1, curTime + 1};
        }

        //���� ��ġ * 2 ��ġ�� ������ ����� �ʰ� �湮�� ������ �ƴҶ��� queue���� �����Ѵ�.
        if (curPos * 2 <= close && !check[curPos * 2]) {
            rear++;
            check[curPos * 2] = true;
            probQueue[rear] = (info) {curPos * 2, curTime + 1};
        }
    }
    return time;
}