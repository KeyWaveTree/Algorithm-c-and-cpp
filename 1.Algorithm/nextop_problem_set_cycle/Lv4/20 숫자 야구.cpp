#include<iostream>
#include<vector>

using namespace std;

struct Info {
    string number;
    int strike;
    int ball;
};

//��ǥ ��� �ĺ� ���� �߿� �Է��� ���ɼ��� ��Ȯ�� ��ġ�ϴ� ������ ������ ���ϴ� ��.

int main() {
    vector<Info> question;
    int n;
    int i, j, x, y;
    int strike, ball;
    string number, quest;
    int ansStrike, ansBall;
    bool isValid;
    int cnt = 0;

    cin >> n;
    question.assign(n, (Info) {"", 0, 0});

    //�Է� ���� ����Ʈ
    for (i = 0; i < n; i++) {
        cin >> question[i].number >> question[i].strike >> question[i].ball;
    }

    //��� ����� �� ����
    for (i = 123; i <= 987; i++) {
        number = to_string(i);

        //���� ������ ���� ���ڰ� �ִٸ� �ݺ��� �ǳʶپ��
        //���� ������ 0�� ���ڰ� �ִٸ� �ǳʶپ��
        if (number[0] == number[1] || number[1] == number[2] || number[0] == number[2]) continue;
        if (number[1] == '0' || number[2] == '0') continue;


        isValid = true; // ���� i���ڰ� ���� ���� �ĺ����̶�� ����
        //���� ����Ʈ ���� �� ��� ���� ����Ʈ�� ����� �´� ���ڰ� �ִٸ� �������� ���� �ĺ����̴�.
        //���� i���ڰ� n���� �������� ��� ���غ��� ��Ʈ����Ʈ, �� ������ �´��� �ƴ��� Ȯ���ϴ� �ݺ���
        //�ϳ��� �����̶� ���� �ʴ� i���ڴ� �ĺ����� ����
        for (j = 0; j < n; j++) {
            strike = 0, ball = 0;
            //j���� �������� ������ ������ �´�.
            quest = question[j].number;
            ansStrike = question[j].strike;
            ansBall = question[j].ball;
            //�������� ���ڿ� i���ڰ� ��Ʈ����ũ�� ����� ball�� ����� ���Ѵ�.
            for (x = 0; x < 3; x++) { //i������ �� �ڸ�
                for (y = 0; y < 3; y++) { //������ ������ �� 3�ڸ�
                    //���� ���� ���ڰ� �ִٸ�
                    if (quest[y] == number[x]) {
                        //��Ʈ����ũ �� ��� -> �� ���� �ڸ��� ��ġ�� ���
                        if (x == y) strike++;
                            //���ϰ��
                        else ball++;
                    }
                }
            }

            //��� ����� ���� �� �ϰ� ���� ���ڰ� ��Ʈ����ũ�� �� ������ �´��� �ƴ��� �˻�
            //���� ���� ���� ��Ʈ����ũ �� ������ ��Ʈ����ũ�� ��ġ���� �ʴٸ� �Ǵ� ���� ���� ���� ������ ���� ��ġ ���� �ʴٸ�
            // -> ���� ���� ���̻� ���� ����Ʈ�� ������ �� ��ġ�� �����Ƿ�(���ɼ� ���ڰ� �ƴϱ� ����) ���� �ݺ� ���� �� ���� ���� �ĺ��� �ݿ� ���� ����.
            if (strike != ansStrike || ball != ansBall) {
                isValid = false; //���� �ĺ��� ���� ǥ��
                break;
            }
        }

        //��� ������ �� ����� ���� �ĺ��� ���� ����
        if (isValid) cnt++;
    }
    cout << cnt;
    return 0;
}