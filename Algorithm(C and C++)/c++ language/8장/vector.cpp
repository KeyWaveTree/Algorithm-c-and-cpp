#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v; //type 제너레이터 int, float, char, string, bool, class, typedef struct 등등 
	v.push_back(10); //push 하지만 할때마다 2제곱씩 늘어난다. 
	v.assign(10, 10); //앞에 개수, 뒤에 초기값, 이차원 백터.assign(size, vector<type>)
	v.pop_back(); //return void 타입
	//백터 요소 확인 v[]

	//백터 메소드 
	/*size() - 벡터의 요소의 개수를 반환한다.

	swap(vector객체) - 두 벡터의 내용을 교환(교체)한다.

	empty() - 벡터가 비었는지 여부를 반환한다.

	at(index) - index번째 요소에 접근한다.

	front() - 벡터의 첫 번째 요소를 반환한다.

	back() - 벡터의 마지막 요소를 반환한다.

	begin() - 벡터의 첫 번째 요소를 가리킨다.

	end() - 벡터의 마지막 요소를 가리킨다.
	
	//이차원 백터 
	vector<vector<int>> r;
	r.assign(3, vector<int>());
	
	*/



}