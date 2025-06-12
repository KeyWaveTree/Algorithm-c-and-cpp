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

        //lis수열이 비어져 있으므로 수열에 삽입 후 다음 과정
        if (i == 0) {
            lis.push_back(item);
            continue;
        }

        //lower bound (iter.begin(), iter.end(), find_value)
        auto bound_index = lower_bound(lis.begin(), lis.end(), item);

        //만약 bound_index가 end라면 데이터 push
        if (bound_index == lis.end()) lis.push_back(item);
            //아닐시 bound_index 자리에 덮어쓰기
        else *bound_index = item;
    }
    cout << lis.size();

    return 0;
}