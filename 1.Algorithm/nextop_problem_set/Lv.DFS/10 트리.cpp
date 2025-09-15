#include<iostream>
#include<vector>

using namespace std;

vector<vector<int >> adjacencyList;
vector<bool> disable;
int n, node, delNode;
int cnt;

//���� Ǯ��
//1. ��������Ʈ�� ��������� ���� Ʈ���� ���踦 ǥ���Ѵ�.
//2. ������ ��带 ��ȸ�ϸ鼭 ��带 ���������� �����. dfs�� �湮�ص� �ǰ� ��ȸ�˰����� ���� �����ص� ������.
//3. ������ �� �Ϸ��� �� -1�� ǥ�õ� �� ���� dfs�� �۾��Ѵ�.
//4. dfs�� ��� ��忡�� ������ ���������� �湮�� ��尡 �־����ٸ� dfs�� �湮�ϰ�
//   �湮�� ��尡 �־��� ���� ������ ��������� �Ǵ��Ѵ�.

void delDfs(int start) {
    //������ ���� �׵��� �ڽĵ��� ��� ��Ȱ��ȭó���Ѵ�.
    disable[start] = true;
    for (int end: adjacencyList[start]) delDfs(end);
}

void dfs(int start) {
    //���� ��ġ ��尡 ��Ȱ��ȭ ǥ�õ� �����
    if (disable[start]) return;

    bool flag = false;//�ѹ��̶� dfs�� ���� �ٸ� ���� �̵��ߴ°��� Ȯ���ϴ� ǥ��
    //�ݺ��� ����� ������ ���� ����� ���̴�.
    for (int end: adjacencyList[start]) {
        //���� ��Ȱ��ȭ ǥ���� ��尡 �ƴϸ� dfs�� �Ѵ�.
        if (!disable[end]) {
            flag = true;
            dfs(end);
        }
    }

    //�ݺ��� ���ϰ��� �ѹ��̶� dfs�� ������ �ʾҴٸ� ������� ����
    if (!flag) cnt++;

}

int main() {
    int i, start;

    cin >> n;

    //���� �Ҵ�
    disable.assign(n, false);
    adjacencyList.resize(n + 1);

    //�� ���� ��������Ʈ ���� ����
    for (i = 0; i < n; i++) {
        cin >> node;
        if (node == -1) {
            start = i;
            continue;
        }
        adjacencyList[node].push_back(i);
    }
    cin >> delNode;

    delDfs(delNode);
    dfs(start);
    cout << cnt;

    return 0;
}
