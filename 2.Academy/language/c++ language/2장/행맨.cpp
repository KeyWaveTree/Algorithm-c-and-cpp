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
	string line(answer.length(), '_'); //�����ڴϱ� return ����.
	int life = answer.length();
	int find;
	char n ;

	while (1) 
	{
		cout << line<<"\n"<<"���� �Է�";
		cin >> n;
		
		if (answer.find(n) == string::npos) //string ������ �� ��ȯ 
		{ 
			life--;
			continue;
		}
		find = answer.find(n);
		line[find] = n;
		answer[find] = '\0';

		if (life == 0)
		{
			printf("����");
			break;
		}
		else if (copy_answer==line)
		{
			printf("���� ������� %d", life);
			break;
		}
	}
	
}