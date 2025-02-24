#include<iostream>
#include<vector>

//주석을 코드 위에 적는것은 설명
//코드 오른쪽에 적는 것은 말고 풀이한 것이다.

using namespace std;

vector<int> visited;

int main()
{
    //블로그 시작한 날짜, 많이 방문했는지 알고싶은 기간
    int n, x;
    //누적한 값을 저장하는 변수
    int prefix_sum=0;
    //최대 방문수를 저장하는 변수
    int max;
    //최대값이 몇개 있는지 새는 변수
    int max_cnt;
    //반복가능한 변수
    int i;

    cin>>n>>x;

    //크기를 2배로 안해도 됨. -> 순환 되는 형식은 아니기에
    //최대 방문할 날짜만큼 벡터 크기 할당
    visited.assign((n+1), 0);

    //벡터 1번지에서 부터 삽입 하는 것이 좋음. 인덱스 에러가 날 수 있기에
    //ㄴ-> 다음 위치에 있는 요소 값 - (현재 위치 - k위치):
    //다음값을 더하고 길이 k를 벗어나는 이전값을 빼준다.

    //입력
    for(i = 1;i <= n;i++)
    {
        //하루 방문 횟수 기록 입력
        cin >> visited[i];

        //k길이 만큼 먼저 누적 : 미리 구하는 이유-> 연산량을 줄이기 위해서(k개만큼 더해야 하는 일을 입력하는 그 즉시 하기 위함)
        if(i <= x) //만약 i값이 x보다 작다면(x개만큼 입력 안했다면)
        {
            prefix_sum += visited[i];
        }
    }
    //최대값을 지금까지 더한 누적합으로 지정한다.
    max = prefix_sum;
    max_cnt=1;
    //처리
    //x거리 까지의 합은 이미 구해놓았으므로 x+1위치에서 부터 한다.
    for(i=x+1;i<=n;i++)//i값이 지금까지 더한 위치 +1에서 부터 n까지 1씩 증가하면서 반복한다.
    {

        prefix_sum += visited[i]-visited[i-x]; //현재 일수 위치 요소값을 더하고 x거리에 있는값을 뺀다.

        //최대값 변경이 일어났다는 뜻은 이전에 똑같은 값이 안나왔다는 뜻이므로 최대값이 변경되었을때 최대값기간을 1로 설정 한다.
        if(prefix_sum == max)max_cnt++;//만약 현재 최대값이랑 똑같다면 최대값 기간 증가를 한다.
        else if(prefix_sum> max)//뺐을때 값이 최대값보다 크다면 최대값으로 바꾼다.
        {
            max = prefix_sum;
            max_cnt =1;
        }


    }

    if(prefix_sum == 0) cout<< "SAD";
    else
    {
        cout<< max<< '\n';
        cout<<max_cnt;
    }

    return 0;
}