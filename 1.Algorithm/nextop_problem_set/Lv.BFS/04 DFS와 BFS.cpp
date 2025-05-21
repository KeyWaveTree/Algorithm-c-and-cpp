#include<iostream>
#include<vector>
using namespace std;

void dfs(int node);
void bfs(int node);

int n, m, v;
vector< vector<bool> > adjMatrix;
vector<bool> check;
int main()
{
    int i;
    int start, end;
    cin>> n>>m>>v;

    //노드 수만큼 방문 기록 지정
    check.assign(n+1, false);
    //인접 행렬 지정
    adjMatrix.resize(n+1);
    for(i=0;i<=n;i++) adjMatrix[i].assign(n+1, 0);

    //노드 연결
    for(i=0;i<m;i++)
    {
        cin>> start>> end;
        adjMatrix[start][end] = adjMatrix[end][start] = 1;
    }

    //dfs
    dfs(v);
    cout<< '\n';

    //노드 초기화 후 다시 resize 지정
    check.clear();
    check.resize(n+1);

    //bfs
    bfs(v);

}


void dfs(int node)
{
    int end;

    if(check[node] == 1) return;

    cout<< node<<' ';
    check[node] = 1;

    for(end =1;end<=n;end++)
    {
        if(adjMatrix[node][end] ==1 && check[end] == 0)
        {
            dfs(end);
        }
    }
}
void bfs(int node)
{
    vector<int> queue;
    int front=0, rear=0;
    int start, end;
    queue.assign(n*n, 0);

    rear++;
    queue[rear] = node;
    check[node] = 1;
    while(true)
    {
        if(front == rear) break;
        front++;

        start = queue[front];

        cout<< start<<' ';

        for(end = 1; end<=n;end++)
        {
            if( adjMatrix[start][end]== 1 && check[end] ==0)
            {
                rear++;
                queue[rear] = end;
                check[end] = 1;
            }
        }
    }
}
