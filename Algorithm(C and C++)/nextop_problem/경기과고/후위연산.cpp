//후위 연산 숫자 범위 21억까지
//괄호 연산 포함
//출력 결과- 계산 결과 
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

//토큰 숫자 stack
char data_stack[102];
int data_stack_top;

int pop(char stack[]);

int main()
{
	int i = 0;
	int cnt = 0;//토큰 분리 인덱스
	char c = 0;

	//입력
	char input_data[102] = { '\0' };

	//토큰 분리 데이터
	char op[500] = { '\0' };
	int data[500] = { 0 };

	//후위연산 한 데이터 
	char post_op[500] = { '\0' };
	int post_data[500] = { 0 };

	//stack으로 구한 숫자 토큰 데이터 저장 데이터 
	int sum_data = 0;

	//임의 저장 데이터 
	char temp = '\0';

	//입력 연산 
	cin >> input_data;
	//(c = input_data[i]) != '\0') 이 경우에는 
	//숫자데이터가 stack연산을 안할 수 있기에 입력데이터의 맨 마지막에는 의미없는 임의의데이터 ~를 넣어줄 생각이다. 
	input_data[strlen(input_data)] = '~';

	//마지막이 숫자데이터 일때 예외 처리 해줘야함 - 해결
	while ((c = input_data[i]) != '\0')
	{
		if (c >= '0' && c <= '9')
		{
			data_stack_top++;
			data_stack[data_stack_top] = c;

			// 다음 데이터가 숫자일 수 있기에 
		}
		//이전 데이터가 숫자였을때 
		else if ((temp >= '0' && temp <= '9') && (c == '(' || c == ')' || c == '*' || c == '/' || c == '+' || c == '-'))
		{
			sum_data = pop(data_stack);
			data[cnt++] = sum_data;
			op[cnt++] = c;

		}
		//이전 데이터가 연산자였을때 
		else
		{
			op[cnt++] = c;
		}

		temp = c;
		i++;
	}

	//후위 표기법으로 바꾸기 
	//아직 다 못품.


	return 0;
}

int pop(char stack[])
{
	int i = 0;
	int sum = 0;
	while (data_stack_top != 0)
	{
		sum += (stack[data_stack_top] * (int)pow(10, i));
		data_stack_top--;
		i++;
	}

	return sum;
}
