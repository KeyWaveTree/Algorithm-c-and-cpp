#include<iostream>
#include<string>

using namespace std;

int main() {
    //��ī�� ������ �� �ִ� ���� ����.
    string pikachuVoice[3] = {"pi", "ka", "chu"};

    string s;

    int i, j, k, temp;
    bool flag = true;

    cin >> s;

    //�Է� ���� ���� ��ҵ��� �ݺ��Ѵ�.
    for (i = 0; i < s.length();) {
        temp = i;//���� index���� �����Ѵ�.

        //��ī�� ������ �� �ִ� ���� �߿� �Է� ���� �κ� ���� �� �ϳ��� ��ġ�ϸ�
        //-> i �ε����� ��ī�� ���� ��ġ�� ������̸�ŭ �ǳʶٱ�
        for (j = 0; j < 3; j++) {

            //��ī�� ���� ��ġ Ȯ�� �ݺ���
            for (k = 0; k < pikachuVoice[j].length(); k++) {
                //���� ��ī�� ������ �Է¹��� ���ڿ� �� �κй��ڿ��� 1�� 1���� ������ ���� ���ڰ� ��ġ���� �ʴ´ٸ�
                if (s[i + k] != pikachuVoice[j][k]) break; //�ݺ��� ����
            }

            //���� k���� ���� ��ī�� �������̿� ��ġ�ߴٸ� �ѹ��̶� ������ ��߳����� ���ٴ� ���̹Ƿ� i�� ����
            if (k == pikachuVoice[j].length()) {
                //i���� ���� ���� ��ŭ ����
                i += pikachuVoice[j].length();
                //j�ݺ� ����
                break;
            }

        }

        //3���� ���ϰ� ���� �ε����� �ٲ��� �ʴ´ٸ� �Ҽ� ���ٴ� ǥ�ø� ���� �� break
        if (i == temp) {
            flag = false;
            break;
        }
    }

    if (flag) cout << "YES";//���� flag�� true��� YES�� ���
    else cout << "NO";//�ƴ϶�� NO�� ���
    return 0;
}