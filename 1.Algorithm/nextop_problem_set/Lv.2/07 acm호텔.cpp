#include<iostream>

using namespace std;

int main() {
    int t;
    int i;
    int w, h, n; //�ʺ�, ����, ȣ��
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> h >> w >> n;
        //���� ���� ���̿� ��� ������ �������� 0�̹Ƿ� ��ȣ���� ����� ������ �� ����.
        //-> ���� ���̷� �ٲ۴��� �� / ���̸�ŭ �����Ѵ�.
        if (n % h == 0) cout << (h * 100) + n / h;
        else cout << (n % h) * 100 + (n / h + 1);
        cout << '\n';
    }

    return 0;
}