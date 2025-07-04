#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> itemData;
vector<int> dpTable;

int main() {
    int i;
    int n, item, maxItem;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> item;
        itemData.push_back(item);
    }

    dpTable.assign(n, 0);

    //0���� ������ ����
    maxItem = dpTable[0] = itemData[0];

    //������ġ ���������� �ִ밪�� ���� ��� ���� ���Ѵ�. �׸��� ���� ��Ұ��� ���ؼ� ���� �� ū���� ã�´�.
    //���ݱ��� ���Ѱ��� �� Ŭ���� ������ ���� ��Ұ��� �� Ŭ�� �ִ�.
    //�ִ밪 ã�� �˰���� ����ϴٴ� ������ ����.

    for (i = 1; i < n; i++) {
        //dpTable[i] = (int)max(dpTable[i - 1] + data[i], data[i]);
        //max���� short�� short���� ���� error�� ����. -> ���� Ÿ���ε� �� ������???
        //�ذ�: �˰��� java������ ����� �̾߱Ⱑ ���°� �˰Ե�. max�Լ�, Ȥ�� + �����ڸ� ��������� ����int������ ó���� �Ǵ� ���� �� 4byte�� ó��
        //���� ���� + ó���� ���������� short�� ó���ϰų� �� ���ڰ� ��� int�� �ٲ�� ��.
        //��>�� 4byte�� ó���ϴ°�? 2byte�� ó���ϴ°ͺ��� 4byte�� ó���ϴ°��� �������� ����. �� ���������� �𸣰���.
        //��>���� ����ε� �ذ� ������ ã���� �𸣰���.
        //�˻���: C++ will adding two shorts convert it to int
        //����ũ: https://stackoverflow.com/questions/39060852/why-does-the-addition-of-two-shorts-return-an-int

        //��ǻ� �������� 100,000 * 1000 �̱⿡ short������ �ʰ��ؼ� int������ ��� �ٲ�.
        //���� ���� ��ġ���� ���� �������� ����� ���� ������ �ִ밪
        dpTable[i] = max(dpTable[i - 1] + itemData[i], itemData[i]);
        //������ �ִ밪�� ���� ū ���� ��´�.
        maxItem = max(dpTable[i], maxItem);
    }

    cout << maxItem;

    return 0;
}