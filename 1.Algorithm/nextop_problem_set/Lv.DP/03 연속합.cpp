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

    //0번지 데이터 삽입
    maxItem = dpTable[0] = itemData[0];

    //현재위치 이전까지의 최대값과 현재 요소 값을 더한다. 그리고 현재 요소값과 비교해서 둘중 더 큰값을 찾는다.
    //지금까지 더한값이 더 클수도 있지만 현재 요소값이 더 클수 있다.
    //최대값 찾는 알고리즘과 비슷하다는 느낌을 받음.

    for (i = 1; i < n; i++) {
        //dpTable[i] = (int)max(dpTable[i - 1] + data[i], data[i]);
        //max에서 short와 short끼리 계산시 error가 나옴. -> 같은 타입인데 왜 에러가???
        //해결: 알고보니 java에서도 비슷한 이야기가 나온걸 알게됨. max함수, 혹은 + 연산자를 사용했을때 값이int값으로 처리가 되는 문제 즉 4byte로 처리
        //따라서 연산 + 처리를 최종적으로 short로 처리하거나 두 인자값 모두 int로 바꿔야 함.
        //ㄴ>왜 4byte로 처리하는가? 2byte로 처리하는것보다 4byte로 처리하는것이 더빠르기 때문. 왜 빠른것인지 모르겠음.
        //ㄴ>내가 제대로된 해결 이유를 찾은지 모르겠음.
        //검색어: C++ will adding two shorts convert it to int
        //참고링크: https://stackoverflow.com/questions/39060852/why-does-the-addition-of-two-shorts-return-an-int

        //사실상 범위값도 100,000 * 1000 이기에 short범위를 초과해서 int값으로 모두 바꿈.
        //지금 현재 위치까지 값을 더했을때 만들어 지는 정제된 최대값
        dpTable[i] = max(dpTable[i - 1] + itemData[i], itemData[i]);
        //정제된 최대값중 가장 큰 값을 담는다.
        maxItem = max(dpTable[i], maxItem);
    }

    cout << maxItem;

    return 0;
}