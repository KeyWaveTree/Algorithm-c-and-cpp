#include<iostream>
#include<vector>

using namespace std;

typedef struct sheep
{
    int x, y;
}sheep;

int height, width;
char map[101][101];
vector< vector<bool> > check;
vector<sheep> bfsQueue;

void bfs(int x, int y)
{
    // ¾Æ·¡, ¿Þ, À§, ¿À
    int vx[4] = {0, -1, 0, 1};
    int vy[4] = {1, 0, -1, 0};
    int front=0, rear = 0;
    int i;
    int posX, posY;

    rear++;
    bfsQueue[rear] = (sheep){x, y};
    check[y][x] = true;

    while(true)
    {
        if(front == rear) break;
        front++;
        x = bfsQueue[front].x;
        y = bfsQueue[front].y;


        for(i=0;i<4;i++)
        {
            posX = vx[i] + x;
            posY = vy[i] + y;
            if(posX >= width || posX < 0 || posY>= height || posY <0) continue;
            if(map[posY][posX] == '#' && !check[posY][posX])
            {
                rear++;
                bfsQueue[rear].x = posX;
                bfsQueue[rear].y = posY;
                check[posY][posX] = true;
            }
        }
    }

}

int main()
{
    int t;

    int i, j, k;

    int group;

    bfsQueue.assign(101* 101, (sheep){0, 0});

    cin>> t;
    for(i=0;i<t;i++)
    {
        cin>> height>> width;
        check.resize(height);
        for(j =0; j<width;j++)
        {
            check[i].assign(width, false);
        }
        group =0;
        for(j=0;j<height;j++)
        {
            for(k=0;k<width;k++)
            {
                cin>> map[j][k];
            }
        }

        //bfs ÁÂÇ¥
        for(j=0;j<height;j++)
        {
            for(k=0;k<width;k++)
            {
               if(map[j][k] != '#' || check[j][k] == true) continue;
               bfs(k, j);
               group++;
            }
        }

        //check ÃÊ±âÈ­
        check.clear();

        cout<< group<<'\n';

    }

    return 0;
}