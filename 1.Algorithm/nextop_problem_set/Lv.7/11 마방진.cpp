#include<iostream>

using namespace std;

int map[501][501];

//4, 6 ������ ��Ģ ����:https://m.blog.naver.com/askmrkwon/220768685076

void oddMagicSquare(int n, int cnt = 0, int stepX = 0, int stepY = 0) {

    //���ڸ� ��ġ�� ���� ��ǥ
    int y = stepY + 1, x = (n) / 2 + 1 + stepX;


    //1. ������ ù �� , �߰� �� ���� 1 �� �ΰ�
    //2. ���� ����, ���� �����ϸ鼭 ���������� ���� �־��.
    //3. ���� �����ϹǷ� ���� ù �ຸ�� �۾����� ���� ���� ������ ������ �Ѿ��.
    //4. ���� �����ϹǷ� ���� �� ���� �Ѿ�� ��� ���� ù ���� �Ѿ��.
    //5. ���̺� �� ���� n �� ����̸� �ุ ����(���� ��ȭ����)
    for (int i = 1; i <= n * n; i++) {
        map[y][x] = ++cnt;
        if (i % n == 0) y++;
        else {
            y--;
            x++;
        }
        if (y < 1 + stepY) y = n + stepY;
        if (x > n + stepX) x = 1 + stepX;
    }
}

//
void quadSwap(int y, int x, int n) {
    int temp;

    //���� ��Ī���� swap
    temp = map[y][x];
    map[y][x] = map[n - y + 1][n - x + 1];
    map[n - y + 1][n - x + 1] = temp;

    //���� ��Ī�� ������ ��ġ��� �������� swap
    temp = map[x][y];
    map[x][y] = map[n - x + 1][n - y + 1];
    map[n - x + 1][n - y + 1] = temp;
}

void quadMagicSquare(int n) {

    int i, j;
    int cnt = 0;

    //1.���������� ü���� �������� ��� ���� ������� 1:2:1�� ������.(4�� ����̹Ƿ� ����)
    int ratioOne = (25 * n) / 100;//1�� ����
    int ratioTwo = (50 * n) / 100;//2�� ����

    //2.n * n �������� ���ڸ� ������� 1~n*n���� �ִ´�.
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            map[i][j] = ++cnt;
        }
    }

    //3. �� ���� ������ ���� �������� ���� ���� �����鳢�� ���� ��Ī���� ��ȯ�Ѵ�.
    for (i = 1; i <= ratioOne; i++) {//1�� ����
        for (j = ratioOne + 1; j <= ratioOne + ratioTwo; j++) {//2�� ����
            quadSwap(i, j, n);
        }
    }
}

void evenSwap(int n, int m, int x, int y) {
    int i, j;
    int temp;
    //n - n�� ������ ��ġ n
    //m - ���� ������ �������� ��ȯ�� ��ġ
    //x, y - �밢���� ���� ���߱� ���� Ȧ�� �������� ��� ���� ��ġ

    //1. ���� ���� m���� ���� ���� ��ȯ
    //2. ���� ������ m-1���� ���� ���� ��ȯ
    for (i = 1; i < n / 2 + 1; i++) {
        //1. ���� ���� m���� ���� ���� ��ȯ
        for (j = 1; j <= m; j++) {
            temp = map[i][j];
            map[i][j] = map[i + n / 2][j];
            map[i + n / 2][j] = temp;
        }

        //2. ���� ������ m-1���� ���� ���� ��ȯ
        for (j = n; j > n - (m - 1); j--) {
            temp = map[i][j];
            map[i][j] = map[i + n / 2][j];
            map[i + n / 2][j] = temp;
        }
    }

    //3.�밢������ ���߱� ���� 1�� 4���� �߾Ӱ� �߾��� ������ ���� ��ȯ

    for (j = x - 1; j <= x; j++) {
        temp = map[y][j];
        map[y][j] = map[y + n / 2][j];
        map[y + n / 2][j] = temp;
    }

}

void evenMagicSquare(int n) {
    //x���� �������� �ٲٱ����� ����
    int x = (n / 2 - 1) / 2;
    int m = n / 2 * n / 2;

    //1. n/2�� �������� �����.
    oddMagicSquare(n / 2, 0, 0, 0); //1��
    oddMagicSquare(n / 2, m, n / 2, n / 2);//2��
    oddMagicSquare(n / 2, 2 * m, n / 2, 0);//3��
    oddMagicSquare(n / 2, 3 * m, 0, n / 2);//4��

    //2. ���� ������ ����� ���� x���� �����ٰ� ������ x-1�� �������� ��ȯ�Ѵ�.
    //3. 1�� 4���� n/2�� �������� ��� ���� �� ��� ���ʰ��� ���� ��ȯ�Ѵ�.
    evenSwap(n, x, n / 4 + 1, n / 4 + 1);
}

int main() {
    int i, j;
    int n;

    cin >> n;

    //Ȧ�� ������
    if (n % 2 != 0) oddMagicSquare(n);

        //4�� ��� ������
    else if (n % 4 == 0) quadMagicSquare(n);

        //�� �ǿ� ��� ������
    else if (n % 2 == 0) evenMagicSquare(n);

    //���
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}