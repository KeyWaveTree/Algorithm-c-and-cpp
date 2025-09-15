#include<iostream>
#include<vector>

using namespace std;

int people, relation;
int cur1, cur2;
int dis;
bool exist;

vector<vector<bool> > adjacencyMatrix;
vector<bool> check;

void dfs(int start, int count = 0) {
    //���� ���� ��ġ�� check ǥ�õ� ����� ���� ��� ��� ����
    //Ȥ�� �̹� �ڽ��� ã�ƾ� �ϴ� ��ġ�� ã�Ҵٸ� ����
    if (check[start] || exist) return;

    //���� ���� ��ġ�� �ڽ��� ã�� �ִ� cur2 ����(ģô���� Ȯ���ϰ� ���� ��)���
    if (start == cur2) {
        exist = true; //ģô ���� ���� true�� �ٲٰ�
        dis = count;//���� ���� dfs�� �̵��� �Ÿ��� �����Ѵ�.
        return;//dfs ��� ����
    }

    //���� start(���:���)��ġ�� checkǥ�� �Ѵ�.
    check[start] = true;

    for (int end = 1; end <= people; end++) {
        //���� adjacencyMatrix���� ������ ��ġ�� �� �� �ִٸ� dfs���� ������ �湮�Ѵ�.
        if (adjacencyMatrix[start][end]) {
            //���� ��ġ�� �� �� �ִ� ��� ��ġ�� ����, ���� �湮 Ƚ�� ����
            dfs(end, count + 1);
        }
    }

}

int main() {

    int node, edge;//��� ��, ���� �ݺ���
    int start, end;

    cin >> people; //�� ��� ����� ����
    cin >> cur1 >> cur2; //�̼� ����� �� ����� ����
    cin >> relation; //graph edge ����

    //���� ��� ���� �Ҵ�
    adjacencyMatrix.resize(people + 1);
    //�湮��� Ȯ�� check vector ���� �Ҵ�
    check.assign(people + 1, false);
    for (node = 1; node <= people; node++) {
        adjacencyMatrix[node].assign(people + 1, false);
    }

    //���� ���� �Է�
    for (edge = 1; edge <= relation; edge++) {
        cin >> start >> end;
        adjacencyMatrix[start][end] = adjacencyMatrix[end][start] = true;
    }

    //dfs ����
    dfs(cur1);

    //dfs�� ����� exist�� false �̸� -1���(ģô���谡 �ƴϴٶ�� ǥ��)
    if (!exist) cout << -1;
        //false�� �ƴҽ� ���� ���
    else cout << dis;

    return 0;
}