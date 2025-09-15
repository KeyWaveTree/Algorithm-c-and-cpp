#include<iostream>
#include<vector>

using namespace std;

//�׷����� ���� ��� - ���� ������ �����ϴ� �������� ����
//1. ���ǵ� ���(edge)�� ����� �������� �����ҿ� ���Ѵ�.
//2. 1�� ������ �����ϸ鼭 ������ �߰��� �� ����.
//   ��> 2�� ������ �������� �κ������� �����ؾ� �ȴٴ� ���̴�.
//�� ���� ����Ǿ��ִ� ���յ��� �׷����� �������̴�.

//�̹� ������ �־��� ���� �� ��� �׷����� �ִ°��� ���ϴ� �����̴�.

int vertex, edge;
vector<bool> check;
vector<vector<bool>> adjacencyMatrix;

void dfs(int start) {
    //���� �̹� start ������ �湮�ߴٸ� �Լ� return
    if (check[start]) return;

    //�湮�� ���� �����϶� checkǥ��
    check[start] = true;

    //start���� �� �� �ִ� �������� Ȯ���Ѵ�.
    for (int end = 1; end <= vertex; end++) {
        //���� ������Ŀ��� end ��ġ�� �̵��� �� �������� dfs�� �Ѵ�
        if (adjacencyMatrix[start][end]) {
            dfs(end);
        }
    }
}

int main() {
    int i;
    int start, end;
    int count = 0;

    cin >> vertex >> edge;
    //������� ���� �Ҵ�
    check.assign(vertex + 1, false);
    adjacencyMatrix.resize(vertex + 1);
    for (i = 1; i <= vertex; i++) adjacencyMatrix[i].assign(vertex + 1, false);

    //�Է�
    for (i = 1; i <= edge; i++) {
        cin >> start >> end;
        //������� ���� ǥ��
        adjacencyMatrix[start][end] = adjacencyMatrix[end][start] = true;
    }

    //������ ���� ����
    for (start = 1; start <= vertex; start++) {
        //���� ���� ������ �湮���� �����̶��
        if (!check[start]) {
            //dfs�� start ������ ����� �������� ǥ��
            dfs(start);
            count++; //���� ��� �׷��� ���� �߰�
        }
    }

    cout << count;
    return 0;
}