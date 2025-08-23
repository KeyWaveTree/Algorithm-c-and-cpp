#include<iostream>
#include<vector>

using namespace std;

int node;
vector<int> check;
vector<vector<int> > adjacencyList;

void dfs(int start) {

    //���� ����Ʈ�� ������ �� �湮��带 Ȯ���Ѵ�.
    for (auto end: adjacencyList[start]) {
        //���� ���� ������ ��� ��ȣ�� �湮 ���������� dfs�� �����Ѵ�.
        if (check[end] == 0) {
            check[end] = start; //�ڽ��� �湮�� ����� �θ�� start�̴�.
            dfs(end); //dfs����
        }
    }
}


int main() {
    int i;
    int start, end;

    cin >> node;
    check.assign(node + 1, 0);
    adjacencyList.resize(node + 1);

    for (i = 1; i < node; i++) {
        cin >> start >> end;
        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }

    check[1] = 1;//1����� �θ�� �ڱ� �ڽ�
    dfs(1);
    for (i = 2; i <= node; i++) {
        cout << check[i] << '\n';
    }

    return 0;
}