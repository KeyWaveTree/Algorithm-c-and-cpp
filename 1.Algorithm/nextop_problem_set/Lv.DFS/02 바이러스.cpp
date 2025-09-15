#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> adjMatrix;//���� ���
vector<bool> check; //��ǻ�� �湮 �����
int vertex; //��ǻ��(���)�� �� - �湮�� ��带 ã�� ���� ���� ����
int edge; //��Ʈ��ũ(����)�� �� -���������� �����ص� ������.
int cnt;//������ ��ǻ���� ���� �����ϴ� ����

void dfs(int start) { //���� ���
    int end;

    check[start] = true; //start ��� üũ ǥ��
    cnt++; //���� ǥ�� ����

    //������ �湮�� ��� ã��
    for (end = 1; end <= vertex; end++) {
        //���� ����� �̿��Ͽ� ���� ��ġ�� ������ ������ �湮�� �� �ִ� �������� Ȯ��
        //���� ������İ��� true�̰� �湮�� ������ �湮�� �ѹ��� ���������� �湮�Ѵ�.
        if (adjMatrix[start][end] && !check[end]) {
            dfs(end);
        }

    }
}

int main() {

    int start, end; //��� ����, ���� ����
    int i;


    //���� ������ �Է�
    cin >> vertex >> edge;

    //���� �Ҵ�
    check.resize(vertex + 1); //üũ �迭 �Ҵ�
    adjMatrix.resize(vertex + 1);//���� ��� 1���� �Ҵ�
    //��������̹Ƿ� 2���� �Ҵ�
    for (i = 1; i <= vertex; i++) adjMatrix[i].assign(vertex + 1, false);

    //graph ���� �Է�
    for (i = 1; i <= edge; i++) {
        cin >> start >> end;//��� ���, ���� ��� �Է�
        //����� ���� ǥ��
        adjMatrix[start][end] = adjMatrix[end][start] = true;
    }


    dfs(1);//1����忡�� dfs����

    //dfs�� ���� �� ������ ��ǻ���� �� ��� 1�� ��带 ��
    cout << cnt - 1;

    return 0;
}