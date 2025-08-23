#include<iostream>

using namespace std;

int map[501][501];

//4, 6 마방진 규칙 참고:https://m.blog.naver.com/askmrkwon/220768685076

void oddMagicSquare(int n, int cnt = 0, int stepX = 0, int stepY = 0) {

    //숫자를 배치할 격자 좌표
    int y = stepY + 1, x = (n) / 2 + 1 + stepX;


    //1. 시작은 첫 행 , 중간 열 에서 1 을 두고
    //2. 행을 감소, 열을 증가하면서 순차적으로 수를 넣어간다.
    //3. 행은 감소하므로 행이 첫 행보다 작아지는 경우는 행은 마지막 행으로 넘어간다.
    //4. 열은 증가하므로 열이 끝 열을 넘어가는 경우 열은 첫 열로 넘어간다.
    //5. 테이블에 들어간 수가 n 의 배수이면 행만 증가(열은 변화없음)
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

    //원점 대칭끼리 swap
    temp = map[y][x];
    map[y][x] = map[n - y + 1][n - x + 1];
    map[n - y + 1][n - x + 1] = temp;

    //원점 대칭한 방향의 전치행렬 방향으로 swap
    temp = map[x][y];
    map[x][y] = map[n - x + 1][n - y + 1];
    map[n - x + 1][n - y + 1] = temp;
}

void quadMagicSquare(int n) {

    int i, j;
    int cnt = 0;

    //1.순차적으로 체워진 마방진의 행과 열을 순서대로 1:2:1로 나눈다.(4의 배수이므로 가능)
    int ratioOne = (25 * n) / 100;//1의 비율
    int ratioTwo = (50 * n) / 100;//2의 비율

    //2.n * n 마방진에 숫자를 순서대로 1~n*n까지 넣는다.
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            map[i][j] = ++cnt;
        }
    }

    //3. 각 행의 비율과 열의 비율에서 같지 않은 비율들끼리 원점 대칭으로 교환한다.
    for (i = 1; i <= ratioOne; i++) {//1의 비율
        for (j = ratioOne + 1; j <= ratioOne + ratioTwo; j++) {//2의 비율
            quadSwap(i, j, n);
        }
    }
}

void evenSwap(int n, int m, int x, int y) {
    int i, j;
    int temp;
    //n - n차 마방진 수치 n
    //m - 왼쪽 오른쪽 세로줄을 교환할 수치
    //x, y - 대각선의 합을 맞추기 위한 홀수 마방진의 가운데 숫자 위치

    //1. 세로 왼쪽 m개의 줄을 서로 교환
    //2. 세로 오른쪽 m-1개의 줄을 서로 교환
    for (i = 1; i < n / 2 + 1; i++) {
        //1. 세로 왼쪽 m개의 줄을 서로 교환
        for (j = 1; j <= m; j++) {
            temp = map[i][j];
            map[i][j] = map[i + n / 2][j];
            map[i + n / 2][j] = temp;
        }

        //2. 세로 오른쪽 m-1개의 줄을 서로 교환
        for (j = n; j > n - (m - 1); j--) {
            temp = map[i][j];
            map[i][j] = map[i + n / 2][j];
            map[i + n / 2][j] = temp;
        }
    }

    //3.대각선합을 맞추기 위해 1번 4번의 중앙과 중앙의 왼쪽을 서로 교환

    for (j = x - 1; j <= x; j++) {
        temp = map[y][j];
        map[y][j] = map[y + n / 2][j];
        map[y + n / 2][j] = temp;
    }

}

void evenMagicSquare(int n) {
    //x개의 세로줄을 바꾸기위한 변수
    int x = (n / 2 - 1) / 2;
    int m = n / 2 * n / 2;

    //1. n/2차 마방진을 만든다.
    oddMagicSquare(n / 2, 0, 0, 0); //1번
    oddMagicSquare(n / 2, m, n / 2, n / 2);//2번
    oddMagicSquare(n / 2, 2 * m, n / 2, 0);//3번
    oddMagicSquare(n / 2, 3 * m, 0, n / 2);//4번

    //2. 높이 절반을 나누어서 왼쪽 x개의 세로줄과 오른쪽 x-1의 세로줄을 교환한다.
    //3. 1번 4번의 n/2차 마방진의 가운데 숫자 및 가운데 왼쪽값을 서로 교환한다.
    evenSwap(n, x, n / 4 + 1, n / 4 + 1);
}

int main() {
    int i, j;
    int n;

    cin >> n;

    //홀수 마방진
    if (n % 2 != 0) oddMagicSquare(n);

        //4의 배수 마방진
    else if (n % 4 == 0) quadMagicSquare(n);

        //그 의외 배수 마방진
    else if (n % 2 == 0) evenMagicSquare(n);

    //출력
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}