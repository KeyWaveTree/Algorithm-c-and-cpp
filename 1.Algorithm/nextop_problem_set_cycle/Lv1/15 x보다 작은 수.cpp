#include<iostream>

using namespace std;

//�� �迭�� ���� �ϳ��ϳ��� �����ϰ� ����ϴ� �ͺ��� (4ms)
//�Է��ϰ� �ٷ� ����ϴ� ���� �� ������? (260ms)
// -> i/o �۾��� ������� �� ���۸� ����
//c++ �� cin/ cout�� �⺻������ ���� ���� ����(tied)
// -> cin���� �Է¹ޱ� ���� cout ��� ���ۿ� ���� �ִ� ������ �ִٸ� ������ ��� ȭ�鿡 ��� ���
//
int main() {
    ios_base::sync_with_stdio(false); //stdio.h�� �ִ� scanf, printf�� ����ȭ ��Ȱ��
    //cin�� cout�� ����(����ȭ) ���� �׷����� flash ���� ����
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    int i;
    int item;

    cin >> n >> x;
    for (i = 0; i < n; i++) {
        cin >> item;
        //���� �Է��� item ���� x������ �۴ٸ� ���
        if (item < x) {
            cout << item << ' ';
        }
    }

    return 0;
}