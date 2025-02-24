#include<iostream>

using namespace std;

typedef struct layer
{
	int len;
	int arrow;
};

//최대 높이 3000개 
layer stick[3000];

int main()
{

	//반복 변수 
	int i;

	//너비 높이 
	int width, height;

	//사이 거리 
	int empty_len;
	//최대 공백의 길이를 저장하는 변수 
	int max_len = 0;

	//입력
	cin >> height >> width;

	for (i = 0; i < height; i++)
	{
		cin >> stick[i].len >> stick[i].arrow;
	}
	
	//인접한 방향은 패스 
	for (i = 0; i < height - 1; i++)
	{	
		//같은 방향이면 혹은 사이 거리가 0이면 pass
		if (stick[i].arrow == stick[i+1].arrow ||
			width - stick[i].len + stick[i+1].len == 0) continue;

		empty_len = (width - stick[i].len + stick[i + 1].len) / 2;

		if (empty_len > max_len) max_len = empty_len;
	}

	cout << max_len;

	return 0;
}