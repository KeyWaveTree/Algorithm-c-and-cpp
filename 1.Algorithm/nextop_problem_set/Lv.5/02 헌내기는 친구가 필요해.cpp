#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct point {
    int x;
    int y;
};

int n, m;
vector<vector<int> > map;
vector<vector<bool> > check;
queue<point> mapQueue;

int bfs(int x, int y) {
    int vx[4] = {0, 1, 0, -1};
    int vy[4] = {1, 0, -1, 0};
    int posx, posy;
    int cnt = 0;
    point front;

    check[y][x] = 1;
    mapQueue.push((point) {x, y});

    while (!mapQueue.empty()) {
        front = mapQueue.front();
        mapQueue.pop();

        //�����̰� ���� ����� �ִ��� ������ Ȯ���Ѵ�.
        //������ ���� ��ġ���� ���Ѵ�.(1-> ���, 0 -> �� ����)
        cnt += map[front.y][front.x];

        for (int i = 0; i < 4; i++) {
            posx = vx[i] + front.x;
            posy = vy[i] + front.y;

            //���� ���� �̵��� ������ ���� ������ ����ٸ� �ǳʶپ��
            if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;
            //���� ���� �̵��� ������ �湮���� �����̰� ���� �Ƴ����� ������ �湮�� �����̴�.
            if (map[posy][posx] != -1 && check[posy][posx] == 0) {
                mapQueue.push((point) {posx, posy});
                check[posy][posx] = 1;
            }
        }

    }

    return cnt;
}


int main() {
    int i, j;
    int x, y;
    int cnt = 0;
    string in;

    cin >> n >> m;

    map.resize(n);
    check.resize(n);


    //���� ���� �Է� ó��
    for (i = 0; i < n; i++) {
        map[i].assign(m, 0);
        check[i].assign(m, 0);
        cin >> in;//n�� ��ŭ �� ���� ���ڿ� �Է�
        for (j = 0; j < m; j++) {
            //���ڿ� ��Ҹ� ������� �����Ͽ� ������� ������ �������� Ȯ��
            if (in[j] == 'P') map[i][j] = 1;
            else if (in[j] == 'X') map[i][j] = -1;
            else if (in[j] == 'I') {
                x = j;
                y = i;
            }
        }
    }
    cnt = bfs(x, y);
    (cnt != 0) ? cout << cnt : cout << "TT";

    return 0;
}