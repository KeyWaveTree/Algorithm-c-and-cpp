#include<iostream>

using namespace std;

int main() {
    string pokemons[70];
    int n;
    int i;
    int k, m;
    int total = 0;
    int max = 0, maxIndex = 0;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> pokemons[i];//포켓몬 이름
        cin >> k >> m;//포켓몬에 필요한 캔디, 현재 가지고 있는 캔디

        //m마리 포켓몬에다가 캔디-2 만큼 나눠준 몫을 구한다.
        //필요한 캔디수를 -2를 하는 이유: 포켓몬이 진화할때마다 2개씩 캔디를 반환됨. 그러면
        //돌려받는 캔디 개수 + 진화하고 남은 캔디 = 진화하기 이전 캔디 - (진화에 필요한 캔디 - 2)이므로 가능함.

        //돌려받는 캔디는 진화 할때 계속 돌려 받으므로 사실상 진화에 필요한 캔디에서 -2를 한거나 마찬가지이다.
        //단 예외적으로 처음 필요한 사탕 수보다 현재 가지고 있는 사탕이 작으면 이 규칙은 성립할 수 없다.

        //만약 지금 진화를 할 수 없다면 continue를 한다.(만약 현재 필요한 캔디가 더 많다면)
        if (k > m) continue;
        //진화할 수 있는 포켓몬 개수를 세어 누적변수에 누적한다.
        total += (m - k) / (k - 2) + 1;

        //지금 진화한 포켓몬 마리가 max변수 보다 크다면
        if (max < (m - k) / (k - 2) + 1) {
            max = (m - k) / (k - 2) + 1; //max 값을 갱신
            maxIndex = i; //가장 많이 진화한 포켓몬 위치 갱신
        }
    }

    cout << total << '\n';
    cout << pokemons[maxIndex];

    return 0;
}