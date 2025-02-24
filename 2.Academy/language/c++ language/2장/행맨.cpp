#include<iostream>
#include<string>
#include<time.h>

using namespace std;

int main()
{

	srand(time(NULL));

	string list[] =
	{
		"string",
		"problem",
		"Programming",
		"good",
	};
	string answer = list[rand() % 4];
	string copy_answer = answer;
	string line(answer.length(), '_'); //생성자니까 return 없다.
	int life = answer.length();
	int find;
	char n ;

	while (1) 
	{
		cout << line<<"\n"<<"글자 입력";
		cin >> n;
		
		if (answer.find(n) == string::npos) //string 쓰레기 값 반환 
		{ 
			life--;
			continue;
		}
		find = answer.find(n);
		line[find] = n;
		answer[find] = '\0';

		if (life == 0)
		{
			printf("죽음");
			break;
		}
		else if (copy_answer==line)
		{
			printf("성공 남은목숨 %d", life);
			break;
		}
	}
	
}