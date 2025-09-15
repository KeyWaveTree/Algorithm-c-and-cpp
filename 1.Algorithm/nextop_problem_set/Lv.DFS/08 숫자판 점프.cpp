#include<iostream>
#include<vector>
#include<set>

using namespace std;


//방문기록을 할필요가 없음.
//방문기록으로 각 칸 이동을 제어 -> 불필요한 제한
//칸 이동시 이미 방문한 칸도 방문해야 정답이 나올 수 있기때문에 불필요한 제한이다.
//5*5칸에 2가 한칸 나머지칸은 1로 채워져 있는 경우 예시: 212121

vector<vector<char> > cellMap;//칸 정보를 저장하는 2차원 벡터
set<string> digitSet;//6자리 문장들을 저장할 수 있는 set

//상하좌우
int vx[4] = {0, -1, 0, 1};
int vy[4] = {1, 0, -1, 0};

void dfs(int x, int y, string cells = "", int cnt = 0) {

    //만약 지금 6개의 문자열을 만들었다면 문자열을 set에다가 넣고 현재 노드 종료
    if (cnt == 6) {
        digitSet.insert(cells);//set에다가 현재 문장을 넣으면 똑같은 문장을 자동으로 걸러준다.
        return;//노드 종료
    }

    //지금 문자열 길이가 6이 아니라면다면 현재 x, y위치에 있는 셀 문자를 문장에 넣기
    cells += cellMap[y][x];

    int posx, posy;
    //지금 칸에서 상하좌우 이동
    for (int next = 0; next < 4; next++) {
        posx = x + vx[next];
        posy = y + vy[next];

        //만약 다음에 갈 칸 정보가 지정된 칸 범위가 아니라면 반복하나를 건너뛰어라
        if (posx < 0 || posx >= 5 || posy < 0 || posy >= 5) continue;
        //그게 아니라면 다음칸으로 이동할때 필요한 정보를 재귀문에다 작성한다.
        dfs(posx, posy, cells, cnt + 1);// (다음x위치, 다음y위치, 지금까지 저장한 문장, 문자열의 삽입 횟수)
    }
    //다음 노드를 방문하고 돌아왔을때 현재 문자열을 삽입 해제한다.
    cells.back();
}

int main() {
    int i, j;

    //입력
    cellMap.resize(5);
    for (i = 0; i < 5; i++) {
        cellMap[i].assign(5, 0);

        for (j = 0; j < 5; j++) {
            cin >> cellMap[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) dfs(j, i);
    }

    //dfs를 다돌았을때 지금까지 만들 수 있는 문자열 개수를 출력한다. -> set안에 들어있는 요소 개수
    cout << digitSet.size();

    return 0;
}