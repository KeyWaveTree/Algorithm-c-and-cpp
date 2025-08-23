//Âü°í https://0lrlokr.tistory.com/87
// https://degurii.tistory.com/47
#include<iostream>

using namespace std;

struct point {
    int x;
    int y;
};

int crossProduct(point one, point two, point three) {
    //ad * bc
    int det = (two.x - one.x) * (three.y - one.y) - (three.x - one.x) * (two.y - one.y);

    return ((det == 0) ? 0 : (det >= 1) ? 1 : -1);
}

int main() {
    point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    cout << crossProduct(a, b, c);

    return 0;
}