#include<iostream>

using namespace std;

int main()
{
	//g- 십간
	//z - 십이지
	int g[10] = { 0,1,2,3,4,5,6,7,8,9 }; 
	char z[12] = { 'A','B','C','D','E','F','G','H','I', 'J','K','L' };
	int n; //입력받는 년도 

	int cnt = 0; //어디까지 할 것인가?
	cin >> n;
	n += 60;// 1,2,3,4 초기화 문제 60을 더하여 포함 되게 한다. 
	// 간지의 주기
	printf("%c%d", z[(n-4) % 12], g[(n-4) % 10]);
	return 0;
}