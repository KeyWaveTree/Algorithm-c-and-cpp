#include<iostream>
#include<vector>

using namespace std;

vector<int> items;

int main() {

    int n, m;
    int i, item;
    long long low = 0, mid, high = 0, cnt;

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> item;
        if (item > high) high = item;
        items.push_back(item);
    }
    while (low <= high) {
        cnt = 0;
        mid = (low + high) / 2;

        for (i = 0; i < n; i++) {
            //���� ������ ������ ������ ���̸�ŭ �߶����� ����� ���´ٸ� ���� �κ��� �־��ְ�,
            // ������ ������ ������ ���� �ڸ��� ���̺��� �۴ٴ� ���̹Ƿ� ���߷����ٴ� �ǹ��� 0�� �־��ش�.
            cnt += (items[i] - mid > 0 ? items[i] - mid : 0);
        }

        //���� ���� ������ ������ ������ �������� ũ�ٸ� ���̸� ��ũ�� �Ѵ�.
        if (cnt >= m) low = mid + 1;
        else high = mid - 1;
        //10 -> 10, 5, 0, 7 = 7 < 22 //�� ũ��
    }
    cout << low - 1;
    return 0;
}