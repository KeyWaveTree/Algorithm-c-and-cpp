#include<iostream>

using namespace std;

struct point {
    long long x;
    long long y;
};

long long crossProduct(point one, point two, point three) {
    long long det = (two.x - one.x) * (three.y - one.y) - (three.x - one.x) * (two.y - one.y);
    return ((det == 0) ? 0 : (det >= 1) ? 1 : -1);
}

int main() {
    point xone, xtwo;
    point yone, ytwo;

    cin >> xone.x >> xone.y;
    cin >> xtwo.x >> xtwo.y;
    cin >> yone.x >> yone.y;
    cin >> ytwo.x >> ytwo.y;

    if (crossProduct(xone, xtwo, yone) * crossProduct(xone, xtwo, ytwo) == -1 &&
        crossProduct(yone, ytwo, xone) * crossProduct(yone, ytwo, xtwo) == -1) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}

