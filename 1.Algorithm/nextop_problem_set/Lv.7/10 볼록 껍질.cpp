#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct point {
    long long x;
    long long y;

    bool operator()(const point &f) {
        return (f.x == this->x) && (f.y == this->y);
    }
};

vector<point> convex1;
vector<point> convex2;
vector<point> input;
point item;

//cross prodcut
int crossProduct(point one, point two, point three) {
    long long det = (two.x - one.x) * (three.y - one.y) - (three.x - one.x) * (two.y - one.y);

    return ((det == 0) ? 0 : (det >= 1) ? 1 : -1);
}

bool compare(const point &a, const point &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    long long n;
    long long i;
    int arrow;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> item.x >> item.y;
        input.push_back(item);
    }

    //x축 기준으로 정렬
    sort(input.begin(), input.end(), compare);

    convex1.push_back(input[0]);
    convex1.push_back(input[1]);
    for (i = 2; i < n;) {
        item = convex1.back();
        convex1.pop_back();
        if (convex1.empty()) {
            convex1.push_back(item);
            convex1.push_back(input[i]);
            i++;
            continue;
        }

        if (crossProduct(convex1.back(), item, input[i]) >= 0)continue;
        else {
            convex1.push_back(item);
            convex1.push_back(input[i]);
            i++;
        }


    }

    reverse(input.begin(), input.end());

    convex2.push_back(input[0]);
    convex2.push_back(input[1]);

    for (i = 2; i < n;) {

        item = convex2.back();
        convex2.pop_back();
        if (convex2.empty()) {
            convex2.push_back(item);
            convex2.push_back(input[i]);
            i++;
            continue;
        }

        if (crossProduct(convex2.back(), item, input[i]) >= 0) continue;
        else {
            convex2.push_back(item);
            convex2.push_back(input[i]);
            i++;
        }


    }

    cout << convex1.size() + convex2.size() - 2;
    return 0;
}