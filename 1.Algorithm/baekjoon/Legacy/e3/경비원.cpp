#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int N, M, K;
int dongun, market[MAX];

int move_info(int dir, int x);
int dist(int c1, int c2);

int main() {
    int dir, x;
    int sum = 0;

    scanf("%d %d", &N, &M);     // 블록의 가로와 세로크기
    scanf("%d", &K);                 // 상점의 수

    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &dir, &x);           // 상점의 방향과 위치
        market[i] = move_info(dir, x);
    }

    scanf("%d %d", &dir, &x);              // x의 방향과 위치
    dongun = move_info(dir, x);


    for (int i = 0; i < K; i++)
    {
        sum += dist(dongun, market[i]);
    }
    printf("%d\n", sum);

    return 0;
}

int move_info(int dir, int x)
{
    switch (dir)
    {

        // 북쪽을 가리킴, 왼쪽위에서 오른쪽으로 
    case 1:
        return x;

        // 동쪽에 상점이 있음을 의미, 위쪽으로부터 거리로 블록의 총 가로길이N에 x를 더함
    case 4:
        return N + x;

        // 남쪽에 상점이 있음을 의미, 남쪽으로부터의 거리로 블록의 가로N+세로M+가로에서 x를 뺀 값
    case 2:
        return N + M + (N - x);

        // 서쪽을 상점이 있음을 의미, 블록의 남쪽으로부터의 거리를 반환
    case 3:
        return N + M + N + (M - x);
    }

    return 0;
}

int dist(int c1, int c2)
{
    int a, b;

    a = abs(c1 - c2);
    b = (N + M + N + M) - a;     // 총 거리에서 차이값을 뺀다

    if (a < b)
        return a;
    else
        return b;
}