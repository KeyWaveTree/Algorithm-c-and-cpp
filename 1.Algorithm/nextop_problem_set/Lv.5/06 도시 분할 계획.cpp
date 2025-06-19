#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//노드의 정보
struct Node {
    int start; //시작 정점
    int end;   //끝 정점
    int weight;//가중치
};

int uni[100001];
int vertex, edge;
vector<Node> mst;

int union_find(int my) {
    if (uni[my] == my) return my;
    return uni[my] = union_find(uni[my]);
}

bool compare(const Node &a, const Node &b) {
    return a.weight < b.weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node empty; //입력값을 받기 위한 변수

    int i;
    int temp1, temp2;
    int value = 0;
    int max_value;
    int cnt = 0; //노드 개수 확인
    cin >> vertex >> edge; //정점 개수, 간선 개수 입력

    //입력
    for (i = 0; i < edge; i++) {
        cin >> empty.start >> empty.end >> empty.weight;
        mst.push_back(empty);
    }

    //유지비 기준으로 정렬
    sort(mst.begin(), mst.end(), compare);

    //union 조상을 자신으로 초기화
    for (i = 1; i <= vertex; i++) {
        uni[i] = i;
    }

    //간선의 개수 만큼
    for (i = 0; i < edge; i++) {
        //가족연결
        temp1 = union_find(mst[i].start);
        temp2 = union_find(mst[i].end);

        //직계조상이 다른 경우에는 결혼을 할 수 없다.
        if (temp1 != temp2) {
            uni[temp1] = temp2;
            value += mst[i].weight;
            max_value = mst[i].weight;
            cnt++;
        }
        if (vertex - 1 == cnt) break;
    }

    cout << value - max_value;

    return 0;
}