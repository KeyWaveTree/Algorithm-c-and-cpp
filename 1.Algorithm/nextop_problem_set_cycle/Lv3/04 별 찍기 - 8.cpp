#include <iostream>

using namespace std;

int main() {
    int n;
    int p, q;
    int i, j;

    cin >> n;
    p = 0;
    q = n * 2;

    for (i = 1; i <= n * 2 - 1; i++) {
        //���� �ݺ����� n���� �ʰ��Ѵٸ� �������� 2 ����, ���� 2����
        if (i > n) {
            p -= 2;
            q += 2;
        }
            //���� �ݺ����� n�� ���ϸ� �������� 2 ����, ���� 2����
        else {
            p += 2;
            q -= 2;
        }
        //�������� ���� �߶� �� ������ŭ �ݺ�
        for (j = 1; j <= p / 2; j++) {
            cout << '*';
        }
        //������ ���� ���
        for (j = 1; j <= q; j++) {
            cout << ' ';
        }
        //�������� ������ ���� ���
        for (j = 1; j <= p / 2; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}