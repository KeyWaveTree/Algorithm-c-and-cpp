//dfs�� Ǫ�� ����

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<bool> > houseMap, check;//���� ����, ���� �湮 Ȯ�� ����

//���� �׷�ȿ� �ִ� ���� �� ���� ���� (n�� ũ�Ⱑ �� ���� �ʰ�(5<= n <= 25) �ִ� 312���� �׷��� ����� �� �� �ִ�.)
//���� �⺻ ���� �˰���� �� �ϳ��� �ᵵ �ð��ʰ��� �ɸ��� �ʴ´�.(�� �������� �����Ǿ� �Ѵ�. ���� �������� �˰����� �ᵵ �������.)
vector<int> houseComplex;

int n; //n�� ����

//�����¿�
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
int houseCnt;

void dfs(int x, int y) {
    int posx, posy;
    int i;

    //���� ���� ��ġ�� �̹� checkǥ�� �Ǿ� �ִٸ� �Լ��� �����Ѵ�.
    if (check[y][x]) return;
    houseCnt++;
    //�ѹ��� �湮 ���� ���� ��ġ�� �湮�Ͽ����Ƿ� checkǥ�ø� �Ѵ�.
    check[y][x] = true;

    //������ �����¿� �� 1�� ǥ�õ� �������� ��͸� ������.
    for (i = 0; i < 4; i++) {
        posx = vx[i] + x;
        posy = vy[i] + y;
        //���� ���� ��ġ���� ���� ���� ���� ����ٸ�
        if (posx < 0 || posx >= n || posy < 0 || posy >= n) continue;
        if (houseMap[posy][posx]) dfs(posx, posy);

    }
}

int main() {
    string line;
    int i, j;//�ݺ���

    cin >> n;

    //����, �湮 Ȯ�� 2d vector�� �����Ҵ��Ѵ�.
    houseMap.resize(n);
    check.resize(n);

    for (i = 0; i < n; i++) {
        houseMap[i].assign(n, false);
        check[i].assign(n, false);
    }

    //���� ���� �Է�
    //��� ���� ������ �� �Է��ؾ� dfs�� ���� �� �ֱ⿡ ���� �ݺ������� ���� �Է� �� dfs�� ó��
    for (i = 0; i < n; i++) {
        cin >> line;
        for (j = 0; j < line.length(); j++) {
            //vector<bool> ���¸� cin���� �Է��� �� ó�� ����.
            houseMap[i][j] = (bool) ((int) line[j] - '0');
        }
    }

    int item = 0;//���� �׷� ������ �����ϴ� ������ �ʱ�ȭ �Ѵ�.
    //dfs ó��
    //������ ǥ�õǾ� �ִ� ������ �ϳ��� �ϳ��� �湮�ϸ� ���� �湮�� ������ 1�̰� dfs�� �湮 �����̾��ٸ�
    //���ο� �׷��̹Ƿ� dfs�� �Ѵ�. ���� ���� �湮�� ������ 1�̰� �̹� dfs�� �湮���� �ִٸ� �̹� Ȯ���� �����̱⿡ �ٸ� ������ Ȯ���Ѵ�.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            //���� ���� ���� ������ ���̰� �ѹ��̶� dfs�� �湮�� ���� ���ٸ� dfs�� �Ѵ�.
            if (houseMap[i][j] && !check[i][j]) {
                dfs(j, i);
                item++;//dfs�� ������ �׷� �� ����
                houseComplex.push_back(houseCnt);
                houseCnt = 0;
            }
        }
    }

    //�� ���� �׷��� �� ���� ������ ����
    sort(houseComplex.begin(), houseComplex.end());

    //���
    cout << item << '\n';
    for (auto temp: houseComplex) {
        cout << temp << '\n';
    }
    return 0;
}