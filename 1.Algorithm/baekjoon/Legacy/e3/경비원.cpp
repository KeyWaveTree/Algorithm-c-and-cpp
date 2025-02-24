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

    scanf("%d %d", &N, &M);     // ����� ���ο� ����ũ��
    scanf("%d", &K);                 // ������ ��

    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &dir, &x);           // ������ ����� ��ġ
        market[i] = move_info(dir, x);
    }

    scanf("%d %d", &dir, &x);              // x�� ����� ��ġ
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

        // ������ ����Ŵ, ���������� ���������� 
    case 1:
        return x;

        // ���ʿ� ������ ������ �ǹ�, �������κ��� �Ÿ��� ����� �� ���α���N�� x�� ����
    case 4:
        return N + x;

        // ���ʿ� ������ ������ �ǹ�, �������κ����� �Ÿ��� ����� ����N+����M+���ο��� x�� �� ��
    case 2:
        return N + M + (N - x);

        // ������ ������ ������ �ǹ�, ����� �������κ����� �Ÿ��� ��ȯ
    case 3:
        return N + M + N + (M - x);
    }

    return 0;
}

int dist(int c1, int c2)
{
    int a, b;

    a = abs(c1 - c2);
    b = (N + M + N + M) - a;     // �� �Ÿ����� ���̰��� ����

    if (a < b)
        return a;
    else
        return b;
}