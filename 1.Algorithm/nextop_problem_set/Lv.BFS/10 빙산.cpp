#include<iostream>
#include<queue>

using namespace std;

//��ǥ ����ü
struct point {
    short x;
    short y;
    char tag; // �ٴ� �� ������ �����ϱ� ���� �±�
};

//������ �ִ� ����
short map[301][301];
short check[301][301];
//�ళ�� ������
short row, col;
//�ٴ��� üũ ��ȣ�� ������ ���ҽ�Ų��. => üũ �迭�� �ʱ�ȭ ���ϰ� ����� �����ϱ� ����
short ocean;
//������ üũ ��ȣ�� ����� ������Ų��. => ���� �ٴ��� üũ��ȣ ���� ������ ����.
short ice;


void bfs(short x, short y, char tag);

int main() {
    short i, j;
    short year = 0;
    short cnt = 0;


    //�Է�
    cin >> row >> col;
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        year++;
        ocean--;
        ice++;
        cnt = 0;
        //�ٴٿ��� bfs�� �Ͽ� ������ ������ ũ�� ����
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                //���� ���� ��ġ�� �ٴ��̰� ���� �ٴ� üũ���� ������ ���� �ʴٸ� ����ġ���� ���� �ٴٸ� �湮�Ѵ�.
                if (map[i][j] == 0 && check[i][j] != ocean) {
                    bfs(j, i, 'o');
                }
            }
        }

        
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                if (map[i][j] > 0 && check[i][j] != ice) {
                    bfs(j, i, 'i');
                    cnt++;
                }
            }
        }

        if (cnt >= 2) {
            cout << year;
            break;
        } else if (cnt == 0) {
            cout << 0;
            break;
        }
    }

    return 0;
}


void bfs(short x, short y, char tag) {
    short i;
    short vx[4] = {0, 1, 0, -1};
    short vy[4] = {1, 0, -1, 0};

    short posX, posY;

    queue<point> q;//ť
    point empty = {x, y, tag};
    if (tag == 'o') check[y][x] = ocean;
    else if (tag == 'i') check[y][x] = ice;
    q.push(empty);


    while (true) {
        if (q.empty()) break;
        empty = q.front();
        q.pop();

        x = empty.x;
        y = empty.y;
        tag = empty.tag;

        for (i = 0; i < 4; i++) {
            posX = vx[i] + x;
            posY = vy[i] + y;
            if (posX > col || posX <= 0 || posY > row || posY <= 0) continue;

            //���� bfs �±װ� o �̰� ������ ��ġ�� �ٴ��̰� �湮�� ���� �ٴ��̸�
            if (tag == 'o' && map[posY][posX] == 0 && check[posY][posX] != ocean) {
                //���� �ٴ��� ��ġ ����
                q.push((point) {posX, posY, tag});
                //���� �ٴ��� ��ġ �湮 ǥ��
                check[posY][posX] = ocean;
            }
            //���� bfs �±װ� o �̰� ������ ��ġ�� ����̸�(�����̸�)
            if (tag == 'o' && map[posY][posX] > 0) {
                //�����Ǿ� �ִ� ���� �� ����
                map[posY][posX]--;
                //���� ���� ���ҵ� ���ϰ� �ٴٰ� �Ǿ��ٸ� ��ó ���Ͽ��� �ݿ��� ���ϱ� ���� �湮ǥ�ø� �Ѵ�.
                if (map[posY][posX] == 0) check[posY][posX] = ocean;
            }
            //���� �±װ� 'i'�̰� ������ ��ġ�� �����̰� �湮�� ���� �����̸� �׷�ȭ ǥ�ø� �Ѵ�.
            if (tag == 'i' && map[posY][posX] > 0 && check[posY][posX] != ice) {
                q.push((point) {posX, posY, tag});
                check[posY][posX] = ice;
            }


        }

    }

}