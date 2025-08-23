#include<iostream>

using namespace std;

int main() {
    int a, b, c;
    int time;
    cin >> a >> b >> c;

    time = a * 60 + b + c;

    cout << time / 60 % 24 << ' ';
    cout << time % 60;

    return 0;
}