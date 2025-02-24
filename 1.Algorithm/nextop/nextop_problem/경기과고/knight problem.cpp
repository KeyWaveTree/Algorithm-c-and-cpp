#include <iostream>
#include <vector>

using namespace std;

int xx[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
int yy[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

int main() {
    long long n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    x--;
    y--;
    cin >> k;
    unsigned long long an = n * m;

    vector<vector<int>> mp;
    if (n < 401) {
        mp.resize(n);
        if (m < 401) {
            for (int i = 0; i < n; i++)
                mp[i].resize(m, -1);
        }
        else {
            if (y > 200)
                y = 200;
            for (int i = 0; i < n; i++) {
                mp[i].resize(401, -1);
            }
        }
    }
    else {
        if (x > 200)
            x = 200;
        mp.resize(401);
        if (m < 401) {
            for (int i = 0; i < 401; i++)
                mp[i].resize(m, -1);
        }
        else {
            if (y > 200)
                y = 200;
            for (int i = 0; i < 401; i++) {
                mp[i].resize(401, -1);
            }
        }
    }

    vector<pair<int, pair<int, int>>> l;
    l.push_back(make_pair(0, make_pair(x, y)));
    int idx = 0;

    while (idx < l.size())
    {
        int x = l[idx].second.first;
        int y = l[idx].second.second;
        for (int i = 0; i < 8; i++) {
            if (x + xx[i] >= 0 and x + xx[i] < 401 and y + yy[i] < 401 and y + yy[i] >= 0) {
                if (mp[x + xx[i]][y + yy[i]] == -1 and l[idx].first < k)
                {
                    l.push_back(make_pair(l[idx].first + 1, make_pair(x + xx[i], y + yy[i])));
                    mp[x + xx[i]][y + yy[i]] = l[idx].first + 1;
                    if ((l[idx].first) % 2 != k % 2) an--;
                }
            }
        }
        idx++;
    }

    //for (int i = 0; i < n; i++) {
    //        for (int j = 0; j < m; j++) {
    //                if (mp[i][j] == -1)
    //                        cout << "x ";
    //                else
    //                        cout << mp[i][j] << ' ';
    //        }
    //        cout << endl;
    //}

    cout << an;
    return 0;
}