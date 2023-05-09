#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v, back;
    int N, input;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
        back.push_back(input);
    }


    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); //중복제거

    for (int i = 0; i < N; i++) {
        printf("%d ", lower_bound(v.begin(), v.end(), back[i]) - v.begin());
    }

	return 0;
}

//내가 한 방식 - 틀림
//struct Infor
//{
//	long long value=0; //값 
//	int seqIn=0; //입력 순서
//	int seqPoint=0; //좌표 순서 
//};
//
//vector<Infor> sortSize; //크기
//
//bool compareValue(Infor &i, Infor &j)
//{
//	return i.value < j.value;
//}
//
//bool compareIn(Infor& i, Infor& j)
//{
//	return i.seqIn < j.seqIn;
//}
//
//int main()
//{
//	Infor inf;
//	int n;
//	int i;
//	int cnt = 0;
//	long long m;
//	scanf("%d", &n);
//
//	sortSize.assign(n, inf);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%ld", &m);
//		inf.value=m;
//		inf.seqIn = i;
//		
//		sortSize[i] = inf;
//	}
//	
//	sort(sortSize.begin(), sortSize.end(), compareValue);
//
//	for (i = 0; i < n - 1; i++)
//	{
//		if (sortSize[i].value == sortSize[i + 1].value)
//		{
//			sortSize[i].seqPoint = cnt;
//			continue;
//		}
//		sortSize[i].seqPoint = cnt;
//		cnt++;
//	}
//
//	sort(sortSize.begin(), sortSize.end(), compareIn);
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", sortSize[i].seqPoint);
//	}
//
//	return 0;