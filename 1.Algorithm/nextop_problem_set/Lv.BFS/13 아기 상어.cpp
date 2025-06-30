#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//�������� �־��� �Ʊ����� �̵� ����� bfs�� �����ϴ� ����
//bfs���� ������ �߿��� �����̴�.
//�� �Ÿ��� ����� ����Ⱑ ���������Ͻ� ���� ��ü �ִ� ����⸦ �������� �׷��� ����Ⱑ ����������� ���� ���ʿ� �ִ� ����⸦ �Դ´�.
//�� �̷��� �ڵ� ó�� ������ bfs���� �켱����ť�� ����ϰų�
//�� bfs�� ó���� ���� �� �ִ� ����⸦ ����Ʈ/�迭���ٰ� �����Ͽ� bfs�� ������ ���ǿ� �´� ����⸦ ������ �����Ѵٿ´�.
//�� ���� �� �ִ� ����⸦ �ٴٿ�ǥ���Ͽ� ���� ���������� �����ʾƷ������� ���� ���� ã������ �����Ѵ�.
//bfs�� �Ʊ� �� ����⸦ ���� �� �������� ������ �˾Ƴ��ٸ� �� ��� bfs�� ���� �̵� Ƚ���� ��� �������ٰ� ���Ͽ� �����ϰ� ��� Ž���� �����Ѵ�.
//����⸦ ���� �� �Ʊ�� ���� ����� ������ �Ǵ��Ͽ� �Ʊ����� ũ�⸦ ���� ��
//�湮�� ���� �ʱ�ȭ �� ���� ����� ���� ��ġ���� ���� bfs�� �ٽ� �����Ѵ�. �� ������ ����⸦ ���� �� ���������� �ݺ��Ѵ�.
//���� ���̻� ����⸦ ���� ���Ѵٸ� bfs�� Ž���� ���� ���Ѵٸ� bfs�� �����ϰ� ���ݱ��� ���� �̵�Ƚ���� ����Ѵ�.


struct info //�Ʊ�� �̵��� ���� ������ ��� �ڷ� ����
{
    short x; //���� �Ʊ����� x��ǥ
    short y; //���� �Ʊ����� y��ǥ
    short step; //�̱����� �̵� Ƚ��
};

short n;//�ٴ��� ũ��
short shark = 2;//�Ʊ����� ũ��
short sharkMove;//�Ʊ�� ������ Ƚ��
short map[20][20]; //������ ���� ǥ��

short checker; //ǥ�� ����
short check[20][20]; //�湮 ǥ�� ���

bool compare(const info &first, const info &second);

void bfs(info start, vector<info> &nominee);

int main() {
    short i, j;
    short x, y;
    short count = 0;
    vector<info> nominee;

    info empty = {0, 0, 0}, item;
    cin >> n;
    //���� �Է�
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
            //���� �Է¹��� ���� �Ʊ� ��� ��ġ���
            if (map[i][j] == 9) {
                x = j, y = i;//�Ʊ� ����� ��ġ�� ����
                map[i][j] = 0;//���� ǥ�ø� 0���� ���ش�. �Ʊ��� �湮�� �ٽ� �� ��ġ�� �̿��� �� �ֱ� ������
            }
        }
    }
    while (true) {
        empty.x = x;
        empty.y = y;
        bfs(empty, nominee);//���� ��ġ���� ���� ����� ������ ��ġ�� �̾Ƴ���

        sort(nominee.begin(), nominee.end(), compare);

        //���̻� ���� ����Ⱑ ������ �����Ѵ�.   .
        if (nominee.size() == 0) break;
        item = nominee[0];
        count++;// ����� ���� Ƚ�� ����
        //���� ����� ũ�Ⱑ ���� ����� ���� Ƚ���� ��ġ�Ѵٸ�
        if (shark == count) {
            shark++;
            count = 0;
        }
        x = item.x;
        y = item.y;
        map[y][x] = 0;
        sharkMove += item.step;

        //vector ����
        nominee.clear();
        vector<info>().swap(nominee);
    }

    cout << sharkMove;
    return 0;
}

bool compare(const info &first, const info &second) {
    // �켱����.
    // 1.���� �����ٸ�
    // 2.�Ÿ��� �������� ������ ���� ���� �ִ°��� ��������
    // 3.���̵� ������ ���� ������ �������� ����
    if (first.step == second.step) {
        if (first.y == second.y) return first.x < second.x;
        else return first.y < second.y;
    } else return first.step < second.step;
}

void bfs(info start, vector<info> &nominee) {
    info queueTable[400 + 1];
    info item = {0, 0, 0};
    short front = 0, rear = 1;
    //��, ����, ������,�Ʒ�
    short vx[4] = {0, -1, 1, 0};
    short vy[4] = {-1, 0, 0, 1};
    short posx, posy;
    short i;

    checker++;//���� üũ ǥ�� ���� ���� ����
    queueTable[rear] = start;//���� ��� ���ĭ�� ���� �۾� ���� ��ġ ����
    check[start.y][start.x] = checker; //�̸� ���� �۾� ���� ��ġ �湮 ��� ǥ��

    while (true) {
        if (front == rear) break;
        front++;

        item = queueTable[front];
        //���� ���� ���� ��ġ���� ����Ⱑ �ְ� �Ʊ����� ũ�⺸�� �۴ٸ� ���� ������ ���� �� �ִ� ����� -> bfs ����
        if (map[item.y][item.x] != 0 && map[item.y][item.x] < shark) {
            nominee.push_back(item);

        }

        for (i = 0; i < 4; i++) {
            posx = item.x + vx[i];
            posy = item.y + vy[i];

            if (posx >= n || posx < 0 || posy >= n || posy < 0) continue;

            //bfs �̵�
            //�̵��� map ��ġ�� 0�̰ų� �Ʊ� ��� ũ�⺸�� �۰ų� ������ �̵� �׸��� �湮���� �����϶�
            if (check[posy][posx] != checker && (map[posy][posx] == 0 || map[posy][posx] <= shark)) {
                rear++;
                check[posy][posx] = checker;
                queueTable[rear].x = posx;
                queueTable[rear].y = posy;
                queueTable[rear].step = item.step + 1;
            }

        }
    }


}
