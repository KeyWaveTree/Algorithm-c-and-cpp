#include<iostream>
#include<deque>

using namespace std;

deque<int> parser(string array) {
    deque<int> arr;
    int cnt = 0;
    int temp = 0;
    if (array == "[]") return arr;
    for (int i = array.length() - 2; i >= 0; i--) {
        if (array[i] == ',' || array[i] == '[') {
            arr.push_front(temp);
            cnt = 0;
            temp = 0;
        } else {
            temp += ((int) array[i] - '0') * (int) powf(10, cnt);
            cnt++;
        }
    }
    return arr;
}


int main() {
    int i, j;
    int cur[2] = {0};
    int state;
    int t, d = 1;
    int len;
    string command;
    string array;
    cin >> t;
    for (i = 0; i < t; i++) {
        deque<int> que;
        cin >> command;
        cin >> len;
        cin >> array;
        cur[0] = cur[1] = 0;
        state = 0;

        d = 1;
        que = parser(array);
        for (j = 0; j < command.length(); j++) {
            if (command[j] == 'R') state++;
            else if (que.empty()) {
                d = 0;
                break;
            } else if (state % 2 == 0) que.pop_front();
            else if (state % 2 == 1)que.pop_back();
        }

        if (d == 0) cout << "error" << '\n';
        else if (state % 2 == 0) {
            cout << "[";
            for (j = 0; j < que.size(); j++) {
                cout << que[j];
                if (j < que.size() - 1) cout << ',';
            }
            cout << "]" << '\n';
        } else {
            cout << "[";
            for (j = que.size() - 1; j >= 0; j--) {
                cout << que[j];
                if (j > 0) cout << ',';
            }
            cout << "]" << '\n';
        }
    }

}