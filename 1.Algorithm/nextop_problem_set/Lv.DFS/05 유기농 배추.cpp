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

    //���� ������ġ�� �ѹ��̶� �湮�ߴٸ� ����
    if (check[y][x]) return;

    //�װ� �ƴ϶�� ���� ��ġ�� ���� �湮�Ѱ��� ó���̹Ƿ� üũǥ��
    check[y][x] = true;

    //�����¿��
    for (i = 0; i < 4; i++) {
        posx = x + vx[i];
        posy = y + vy[i];
        //���� ���� ������ �ϴ� ��ġ ���� ���� �� ������� dfs�� ���� �ʴ´�.
        if (posx >= m || posx < 0 || posy >= n || posy < 0) continue;
        //�� �� �ִ� ������ ������ ���߰� �ɾ��� �ִ� ���̶��
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
        //������ ���� ���� ��ġ�� ��Ұ� true�̰� �湮�� �ѹ��� ���� �����϶� dfs�� �Ѵ�.
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (cabbageMap[j][k] && !check[j][k]) {
                    dfs(k, j);
                    count++;
                }
            }
        }

        //���� �������� ���� ���
        cout << count << '\n';

        //���� �� Ȯ�� ǥ�� �ʱ�ȭ
        //�׿� ������ ���� �ʱ� ���� �޸� ����
        vector<vector<bool> >().swap(cabbageMap);
        vector<vector<bool> >().swap(check);
    }
}