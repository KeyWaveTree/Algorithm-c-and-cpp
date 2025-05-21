#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

typedef struct node {
    int start;
    int end;
    long long weight;

    bool operator==(const node &op1) {
        return op1.start == start && op1.end == end;
    }

} node;

typedef struct compare {
    bool operator()(node &op1, node &op2) {
        return op1.weight > op2.weight;
    }
} compare;


//adjacency matrix
vector<node> adjMatrix[20001];
//dist 배열이란? 시작위치에서 갈 수 있는 최단 경로 비용 기록 배열 
long long dist[20001];
//체크 배열 
bool check[20001];

int main() {

    priority_queue<node, vector<node>, compare> heap;
    node empty, item;

    dist[0] = numeric_limits<long long>::max();

    int i;
    int vertex, edge;//노드 , 간선
    int init;//시작값
    int start, end;
    long long weight;//입력의 시작 끝
    long long min_weight = 0;
    //정점의 개수 v 간선의 개수 e
    cin >> vertex >> edge;

    //시작 정점 k
    cin >> init;

    //u -> v weight w
    for (i = 0; i < edge; i++) {
        cin >> start >> end >> weight;
        empty = (node) {start, end, weight};
        auto state = find(adjMatrix[start].begin(), adjMatrix[start].end(), empty);
        if (state != adjMatrix[start].end()) {
            int index = (int) (state - adjMatrix[start].begin());
            adjMatrix[start][index].weight = (empty.weight < adjMatrix[start][index].weight) ? empty.weight
                                                                                             : adjMatrix[start][index].weight;
        } else {
            adjMatrix[start].push_back(empty); //start-> end
        }

    }


    //각 정점의 최소 거리 inf값으로
    for (i = 1; i <= vertex; i++) {
        dist[i] = dist[0];
    }
    //예시로 여행을 할려고 하는데 1~6번까지 관광지가 있다고 할께요
    //저희는 모든 관광지를 한번씩 둘러볼 계획이에요.

    //1번에서 부터 시작
    //1번노드의 가중치를 0으로 하고 큐에 넣는다.
    //start번노드에서 갈 수 있는 목적지를 탐사한다.

    dist[init] = 0 + min_weight;
    check[init] = true;

    empty.end = init, empty.weight = dist[init];
    heap.push(empty);


    while (!heap.empty()) {

        item = heap.top();
        heap.pop();
        start = item.end;
        min_weight = item.weight;

        //현재 방문한 시작한 위치를 체크 표시한다.
        check[start] = true;

        //인접 리스트로 bfs
        for (node &n: adjMatrix[start]) {

            //만약 지금 현재 노드가 방문한 노드이면 건너뛰어라.(이미 모든 경우의 수 방문)
            if (check[n.end] == 1) continue;

            //현재 사용할려는 가중치와 최단 수치를 더했을때 지금 방문하는 목적지의 최단경로보다 더 적을때 방문 목적지의 최단 경로값을 갱신한다. 그리고 체크표시가 안되어 있을때 노드만 힙에 추가한다.
            if (n.weight + min_weight < dist[n.end] && check[n.end] == 0) {
                dist[n.end] = n.weight + min_weight;
                //바꾼후 값을 힙에다가 방문 노드번호와 현재 까지의 최단 거리를 넣는다.
                empty.end = n.end, empty.weight = dist[n.end];
                heap.push(empty);
            }

        }




        //노드중 가장 작은 값을 가지는 dist 노드를 뽑아라 단 체크가 안된 노드만
//        //min heap을 이용해서 구현하는 것이 좋음.
//        for (int j = 1; j <= vertex; j++) {
//            //만약 현재 위치를 방문안했고, 현재 최소값 위치보다 거리가 작다면 min_node 위치를 변경하라.
//            if (check[j] == 0 && dist[j] < dist[min_node]) min_node = j;
//        }
//
//        //만약 한번이라도 방문할 곳이 없다면 min_node가 0이므로 종료
//        if (min_node == 0) break;
//
//        //현재 가장 짧은 거리를 저장하고
//        min_weight = dist[min_node];
//        //자신이 방문한 곳을 체크 표시하고
//        check[min_node] = 1;
//        //시작노드로 변경한다.
//        start = min_node;

        //가장 맨 위에 있는 정보를 없앤다.


        /*
        for (end = 1; end <= vertex; end++)
        {
            //인접행렬에서 갈수 없는 방향이면
            if (adjMatrix[start][end] == 0 || check[end] == 1) continue;

            //시작 위치에서 탐사한 목적지까지의 비용을 dist 배열에 조건이 있다.
            //지금까지 현재 위치를 방문한 경로중 지금 방문한 비용이 최소라면 dist 배열에
            //지금의 비용을 삽입 한다.

            if (adjMatrix[start][end] + min_weight < dist[end])
            {
                dist[end] = adjMatrix[start][end] + min_weight;
            }
            //찾으면서 가장 작은 거리도 확인한다.
            //조건만약 체크에 포함 안된 노드와 dist 배열에 훨신 더 작은값이 있다면
            if (check[end] == 0 && dist[end] < min_node) min_node = min(min_node, dist[end]);
        }

        if (min_node == numeric_limits<int>::max()) break;

        min_weight += dist[min_node];
        check[min_node] = 1;
        start = min_node;
        */
    }

    for (i = 1; i <= vertex; i++) {
        if (dist[i] == dist[0]) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}