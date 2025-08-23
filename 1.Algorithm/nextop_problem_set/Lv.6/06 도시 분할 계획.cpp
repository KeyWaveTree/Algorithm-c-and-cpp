#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����� ����
struct Node {
    int start; //���� ����
    int end;   //�� ����
    int weight;//����ġ
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

    Node empty; //�Է°��� �ޱ� ���� ����

    int i;
    int temp1, temp2;
    int value = 0;
    int max_value;
    int cnt = 0; //��� ���� Ȯ��
    cin >> vertex >> edge; //���� ����, ���� ���� �Է�

    //�Է�
    for (i = 0; i < edge; i++) {
        cin >> empty.start >> empty.end >> empty.weight;
        mst.push_back(empty);
    }

    //������ �������� ����
    sort(mst.begin(), mst.end(), compare);

    //union ������ �ڽ����� �ʱ�ȭ
    for (i = 1; i <= vertex; i++) {
        uni[i] = i;
    }

    //������ ���� ��ŭ
    for (i = 0; i < edge; i++) {
        //��������
        temp1 = union_find(mst[i].start);
        temp2 = union_find(mst[i].end);

        //���������� �ٸ� ��쿡�� ��ȥ�� �� �� ����.
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