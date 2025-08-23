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

    typedef pair<int, int> point; //��� �ڷ����� point�� ��ȯ
    point item(x, y);//���� ��ġ
    queue<point> cabbageQueue;//ó���� ���� ����� ť

    int posx, posy;
    int i;

    //���� ��ġ ť���ٰ� ����
    cabbageQueue.push(item);
    //������ġ �湮 ǥ��
    check[y][x] = true;

    //bfs���� - ť�� ���̻� �� �۾��� ������ ���� �ݺ��ض� ������ rear
    while (!cabbageQueue.empty()) {
        //ť front�� �ִ� ó���� ������ ��´�.
        item = cabbageQueue.front();
        cabbageQueue.pop();//front ���� ����

        //���� x, y ��ġ�� �����Ѵ�.(���� ���ϰ� item.first, item.second�� �ص� ��� ����)
        x = item.first;
        y = item.second;

        //���� item ĭ���� �����¿�� ������ ������ �� �� �ִ��� �� �� ������ Ȯ���Ѵ�.
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
        //����, ����, ���� ��ġ
        cin >> m >> n >> p;

        //���� ũ�� ��ŭ ����/Ȯ��ǥ�� �����Ҵ�(�ε��� ����)
        cabbageMap.resize(n);
        check.resize(n);
        //���� ũ�� ��ŭ ����/Ȯ��ǥ�� �����Ҵ�
        for (j = 0; j < n; j++) {
            cabbageMap[j].assign(m, false);
            check[j].assign(m, false);
        }

        //��ǥ ������ŭ ��ǥ �Է�
        for (j = 0; j < p; j++) {
            cin >> x >> y;
            //�Է��� ��ǥ�� ���� �ɾ��ٴ� ǥ��
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