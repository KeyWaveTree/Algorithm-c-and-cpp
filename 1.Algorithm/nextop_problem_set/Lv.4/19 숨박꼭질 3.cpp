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

    //���� �ڽ�Ʈ 3
    //�����̵� �ڽ�Ʈ - 2
    //�¿� �̵� �ڽ�Ʈ - 1

    while (!q.empty()) {
        item = q.front();
        q.pop();

        start = item.pos;
        cnt = item.cnt;

        //���� ������ ��ġ�� ������ ��ġ�� �Ȱ��� ���ݱ��� ã�� �ð����� �� ������ ã�Ҵٸ� �ִܽð��� �����Ѵ�.
        if (start == end && time > cnt) {
            time = cnt;
        }

        //*2 �����̵��� ������ ��ġ�� 10�� �����̰� ���� ��ġ���� �����̵��� üũǥ�ø� ���������� bfs�� �۵��ϰԲ� �Ѵ�.
        if (start * 2 <= 1e+5 && !check[start * 2]) {
            q.push((point) {start * 2, cnt});
            check[start * 2] = true;
        }
        //-1 �̵��� ������ ��ġ�� 0 �̻��̰� ���� ��ġ���� �湮 üũ�� ���������� bfs�� �۵��ϰԲ��Ѵ�.
        if (start - 1 >= 0 && !check[start - 1]) {
            q.push((point) {start - 1, cnt + 1});
            check[start - 1] = true;
        }
        //+1 �̵��� ������ ��ġ�� 10�� �����̰� ���� ��ġ ���� �湮 üũ�� ���������� bfs�� �۵��ϰԲ��Ѵ�.
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