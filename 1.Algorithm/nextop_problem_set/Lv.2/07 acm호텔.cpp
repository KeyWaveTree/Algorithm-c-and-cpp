#include<iostream>

using namespace std;

int main() {
    int t;
    int i;
    int w, h, n; //너비, 높이, 호수
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> h >> w >> n;
        //만약 방이 높이와 배수 관계라면 나머지가 0이므로 방호수를 제대로 관리할 수 없음.
        //-> 층을 높이로 바꾼다음 방 / 높이만큼 설정한다.
        if (n % h == 0) cout << (h * 100) + n / h;
        else cout << (n % h) * 100 + (n / h + 1);
        cout << '\n';
    }

    return 0;
}