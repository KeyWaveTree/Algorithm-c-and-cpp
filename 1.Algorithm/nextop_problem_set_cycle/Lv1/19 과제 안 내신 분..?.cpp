#include<iostream>

using namespace std;

int main() {
    bool check[30 + 1] = {false};
    int not2[2] = {0};
    int i;
    int number;


    for (i = 0; i < 28; i++) {
        cin >> number; //������ �� �л� �Է�
        check[number] = true; //������ �л��� index ��ȣ�� true��
    }

    number = 0;//number�� �������� ���� �л��� ���� ���
    for (i = 1; i <= 30; i++) {
        //���� ���� ���� i ��ȣ�� false�� ǥ�� �Ǿ� �ִٸ� ������ ���� 2�� �� �� �л��̹Ƿ� not2 �迭�� ���������� ����
        if (!check[i]) not2[number++] = i;
    }

    //not2�� �ִ� 2���� ���� �������� 0������ �� ũ�ٸ� 1������ ���� ����� 0������ ���
    if (not2[0] > not2[1]) cout << not2[1] << '\n' << not2[0];
    else cout << not2[0] << '\n' << not2[1];

    return 0;
}