#include<iostream>
#include<vector>
#include<set>

using namespace std;


//�湮����� ���ʿ䰡 ����.
//�湮������� �� ĭ �̵��� ���� -> ���ʿ��� ����
//ĭ �̵��� �̹� �湮�� ĭ�� �湮�ؾ� ������ ���� �� �ֱ⶧���� ���ʿ��� �����̴�.
//5*5ĭ�� 2�� ��ĭ ������ĭ�� 1�� ä���� �ִ� ��� ����: 212121

vector<vector<char> > cellMap;//ĭ ������ �����ϴ� 2���� ����
set<string> digitSet;//6�ڸ� ������� ������ �� �ִ� set

//�����¿�
int vx[4] = {0, -1, 0, 1};
int vy[4] = {1, 0, -1, 0};

void dfs(int x, int y, string cells = "", int cnt = 0) {

    //���� ���� 6���� ���ڿ��� ������ٸ� ���ڿ��� set���ٰ� �ְ� ���� ��� ����
    if (cnt == 6) {
        digitSet.insert(cells);//set���ٰ� ���� ������ ������ �Ȱ��� ������ �ڵ����� �ɷ��ش�.
        return;//��� ����
    }

    //���� ���ڿ� ���̰� 6�� �ƴ϶��ٸ� ���� x, y��ġ�� �ִ� �� ���ڸ� ���忡 �ֱ�
    cells += cellMap[y][x];

    int posx, posy;
    //���� ĭ���� �����¿� �̵�
    for (int next = 0; next < 4; next++) {
        posx = x + vx[next];
        posy = y + vy[next];

        //���� ������ �� ĭ ������ ������ ĭ ������ �ƴ϶�� �ݺ��ϳ��� �ǳʶپ��
        if (posx < 0 || posx >= 5 || posy < 0 || posy >= 5) continue;
        //�װ� �ƴ϶�� ����ĭ���� �̵��Ҷ� �ʿ��� ������ ��͹����� �ۼ��Ѵ�.
        dfs(posx, posy, cells, cnt + 1);// (����x��ġ, ����y��ġ, ���ݱ��� ������ ����, ���ڿ��� ���� Ƚ��)
    }
    //���� ��带 �湮�ϰ� ���ƿ����� ���� ���ڿ��� ���� �����Ѵ�.
    cells.back();
}

int main() {
    int i, j;

    //�Է�
    cellMap.resize(5);
    for (i = 0; i < 5; i++) {
        cellMap[i].assign(5, 0);

        for (j = 0; j < 5; j++) {
            cin >> cellMap[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) dfs(j, i);
    }

    //dfs�� �ٵ������� ���ݱ��� ���� �� �ִ� ���ڿ� ������ ����Ѵ�. -> set�ȿ� ����ִ� ��� ����
    cout << digitSet.size();

    return 0;
}