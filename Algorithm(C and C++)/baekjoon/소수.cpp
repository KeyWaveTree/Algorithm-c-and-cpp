#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int min = 99999;
    int n, m;
    int j;
    bool flag = true;

    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        for (j = 2; j <= i * i; j++)
        {
            if (i % j == 0) break;
        }
        if (i == j)
        {
            sum += i;
        }

        if (i == j && min > i) min = i;
    }
    if (flag) {
        cout << sum << ' ' << min;
    }
    else if(sum==0){
        cout << -1;
    }

    return 0;
}