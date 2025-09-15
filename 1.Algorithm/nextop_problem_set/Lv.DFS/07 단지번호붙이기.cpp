//dfs로 푸는 버전

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<bool> > houseMap, check;//단지 지도, 단지 방문 확인 유무

//단지 그룹안에 있는 집의 수 저장 벡터 (n의 크기가 얼마 되지 않고(5<= n <= 25) 최대 312개의 그룹이 만들어 질 수 있다.)
//따라서 기본 정렬 알고리즘들 중 하나를 써도 시간초과가 걸리지 않는다.(단 안정성은 성립되야 한다. 또한 빠른정렬 알고리즘을 써도 상관없다.)
vector<int> houseComplex;

int n; //n의 개수

//상하좌우
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
int houseCnt;

void dfs(int x, int y) {
    int posx, posy;
    int i;

    //만약 현재 위치가 이미 check표시 되어 있다면 함수를 종료한다.
    if (check[y][x]) return;
    houseCnt++;
    //한번도 방문 안한 현재 위치를 방문하였으므로 check표시를 한다.
    check[y][x] = true;

    //인접한 상하좌우 중 1이 표시된 지역으로 재귀를 돌린다.
    for (i = 0; i < 4; i++) {
        posx = vx[i] + x;
        posy = vy[i] + y;
        //만약 다음 위치값이 지도 지역 밖을 벗어난다면
        if (posx < 0 || posx >= n || posy < 0 || posy >= n) continue;
        if (houseMap[posy][posx]) dfs(posx, posy);

    }
}

int main() {
    string line;
    int i, j;//반복수

    cin >> n;

    //지도, 방문 확인 2d vector를 동적할당한다.
    houseMap.resize(n);
    check.resize(n);

    for (i = 0; i < n; i++) {
        houseMap[i].assign(n, false);
        check[i].assign(n, false);
    }

    //지도 정보 입력
    //모든 지도 정보를 다 입력해야 dfs를 돌릴 수 있기에 이중 반복문으로 정보 입력 후 dfs를 처리
    for (i = 0; i < n; i++) {
        cin >> line;
        for (j = 0; j < line.length(); j++) {
            //vector<bool> 형태를 cin으로 입력할 시 처리 못함.
            houseMap[i][j] = (bool) ((int) line[j] - '0');
        }
    }

    int item = 0;//단지 그룹 개수를 저장하는 변수로 초기화 한다.
    //dfs 처리
    //지도에 표시되어 있는 정보를 하나씩 하나씩 방문하며 현재 방문한 정보가 1이고 dfs로 방문 한적이없다면
    //새로운 그룹이므로 dfs를 한다. 만약 현재 방문한 정보가 1이고 이미 dfs로 방문한적 있다면 이미 확인한 단지이기에 다른 정보를 확인한다.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            //만약 현재 지도 지점이 집이고 한번이라도 dfs로 방문한 적이 없다면 dfs를 한다.
            if (houseMap[i][j] && !check[i][j]) {
                dfs(j, i);
                item++;//dfs가 끝나고 그룹 수 증가
                houseComplex.push_back(houseCnt);
                houseCnt = 0;
            }
        }
    }

    //각 단지 그룹의 집 개수 오름차 정렬
    sort(houseComplex.begin(), houseComplex.end());

    //출력
    cout << item << '\n';
    for (auto temp: houseComplex) {
        cout << temp << '\n';
    }
    return 0;
}