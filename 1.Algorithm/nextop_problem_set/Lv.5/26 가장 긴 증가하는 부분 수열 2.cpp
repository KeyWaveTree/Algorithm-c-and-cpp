#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> lis;

int main() {
    int n;
    int i;
    int item;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> item;

        //lis������ ����� �����Ƿ� ������ ���� �� ���� ����
        if (i == 0) {
            lis.push_back(item);
            continue;
        }

        //lower bound (iter.begin(), iter.end(), find_value)
        auto bound_index = lower_bound(lis.begin(), lis.end(), item);

        //���� bound_index�� end��� ������ push
        if (bound_index == lis.end()) lis.push_back(item);
            //�ƴҽ� bound_index �ڸ��� �����
        else *bound_index = item;
    }
    cout << lis.size();

    return 0;
}