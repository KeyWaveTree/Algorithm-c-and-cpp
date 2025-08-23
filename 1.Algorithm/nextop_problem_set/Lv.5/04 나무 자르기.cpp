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
            //만약 지정한 나무를 지정한 높이만큼 잘랐을때 양수가 나온다면 남은 부분을 넣어주고,
            // 음수면 지정된 나무가 현재 자르는 높이보다 작다는 것이므로 안잘려진다는 의미의 0을 넣어준다.
            cnt += (items[i] - mid > 0 ? items[i] - mid : 0);
        }

        //만약 남은 나무의 개수가 가져갈 나무보다 크다면 높이를 더크게 한다.
        if (cnt >= m) low = mid + 1;
        else high = mid - 1;
        //10 -> 10, 5, 0, 7 = 7 < 22 //더 크게
    }
    cout << low - 1;
    return 0;
}