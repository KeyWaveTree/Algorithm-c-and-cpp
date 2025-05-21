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
//dist �迭�̶�? ������ġ���� �� �� �ִ� �ִ� ��� ��� ��� �迭 
long long dist[20001];
//üũ �迭 
bool check[20001];

int main() {

    priority_queue<node, vector<node>, compare> heap;
    node empty, item;

    dist[0] = numeric_limits<long long>::max();

    int i;
    int vertex, edge;//��� , ����
    int init;//���۰�
    int start, end;
    long long weight;//�Է��� ���� ��
    long long min_weight = 0;
    //������ ���� v ������ ���� e
    cin >> vertex >> edge;

    //���� ���� k
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


    //�� ������ �ּ� �Ÿ� inf������
    for (i = 1; i <= vertex; i++) {
        dist[i] = dist[0];
    }
    //���÷� ������ �ҷ��� �ϴµ� 1~6������ �������� �ִٰ� �Ҳ���
    //����� ��� �������� �ѹ��� �ѷ��� ��ȹ�̿���.

    //1������ ���� ����
    //1������� ����ġ�� 0���� �ϰ� ť�� �ִ´�.
    //start����忡�� �� �� �ִ� �������� Ž���Ѵ�.

    dist[init] = 0 + min_weight;
    check[init] = true;

    empty.end = init, empty.weight = dist[init];
    heap.push(empty);


    while (!heap.empty()) {

        item = heap.top();
        heap.pop();
        start = item.end;
        min_weight = item.weight;

        //���� �湮�� ������ ��ġ�� üũ ǥ���Ѵ�.
        check[start] = true;

        //���� ����Ʈ�� bfs
        for (node &n: adjMatrix[start]) {

            //���� ���� ���� ��尡 �湮�� ����̸� �ǳʶپ��.(�̹� ��� ����� �� �湮)
            if (check[n.end] == 1) continue;

            //���� ����ҷ��� ����ġ�� �ִ� ��ġ�� �������� ���� �湮�ϴ� �������� �ִܰ�κ��� �� ������ �湮 �������� �ִ� ��ΰ��� �����Ѵ�. �׸��� üũǥ�ð� �ȵǾ� ������ ��常 ���� �߰��Ѵ�.
            if (n.weight + min_weight < dist[n.end] && check[n.end] == 0) {
                dist[n.end] = n.weight + min_weight;
                //�ٲ��� ���� �����ٰ� �湮 ����ȣ�� ���� ������ �ִ� �Ÿ��� �ִ´�.
                empty.end = n.end, empty.weight = dist[n.end];
                heap.push(empty);
            }

        }




        //����� ���� ���� ���� ������ dist ��带 �̾ƶ� �� üũ�� �ȵ� ��常
//        //min heap�� �̿��ؼ� �����ϴ� ���� ����.
//        for (int j = 1; j <= vertex; j++) {
//            //���� ���� ��ġ�� �湮���߰�, ���� �ּҰ� ��ġ���� �Ÿ��� �۴ٸ� min_node ��ġ�� �����϶�.
//            if (check[j] == 0 && dist[j] < dist[min_node]) min_node = j;
//        }
//
//        //���� �ѹ��̶� �湮�� ���� ���ٸ� min_node�� 0�̹Ƿ� ����
//        if (min_node == 0) break;
//
//        //���� ���� ª�� �Ÿ��� �����ϰ�
//        min_weight = dist[min_node];
//        //�ڽ��� �湮�� ���� üũ ǥ���ϰ�
//        check[min_node] = 1;
//        //���۳��� �����Ѵ�.
//        start = min_node;

        //���� �� ���� �ִ� ������ ���ش�.


        /*
        for (end = 1; end <= vertex; end++)
        {
            //������Ŀ��� ���� ���� �����̸�
            if (adjMatrix[start][end] == 0 || check[end] == 1) continue;

            //���� ��ġ���� Ž���� ������������ ����� dist �迭�� ������ �ִ�.
            //���ݱ��� ���� ��ġ�� �湮�� ����� ���� �湮�� ����� �ּҶ�� dist �迭��
            //������ ����� ���� �Ѵ�.

            if (adjMatrix[start][end] + min_weight < dist[end])
            {
                dist[end] = adjMatrix[start][end] + min_weight;
            }
            //ã���鼭 ���� ���� �Ÿ��� Ȯ���Ѵ�.
            //���Ǹ��� üũ�� ���� �ȵ� ���� dist �迭�� �ν� �� �������� �ִٸ�
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