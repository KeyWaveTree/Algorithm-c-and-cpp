#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<long long> items;

    int k, n;
    int i, item, cnt;
    long long low = 0, mid, high;

    cin >> k >> n;
    for (i = 0; i < k; i++) {
        cin >> item;
        items.push_back(item);
        if (item > high) high = item;
    }

    //ÀÌÁø Å½»ö
    while (low < high) {
        cnt = 0;
        mid = (low + high) / 2;

        for (i = 0; i < k; i++) {
            cnt += items[i] / mid;
        }

        if (cnt >= n) low = mid + 1;
        else high = mid - 1;
    }
    cout << low - 1;
    return 0;
}