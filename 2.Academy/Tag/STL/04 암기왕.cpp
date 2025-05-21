#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> note;
int n;
int binary_search(int find)
{
    int flag = 0;

    int start, end, mid;
    start=0;
    end = n-1;

    while(start <= end)
    {
        mid = (start+end)/2;
        if(note[mid] == find)
        {
            return 1;
        }
        else if(note[mid] > find)
        {
            end= mid-1;
        }
        else if(note[mid] < find)
        {
            start = mid+1;
        }

    }

    return flag;
}

bool compare(const int& a, const int& b)
{
    return a< b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);

    int i, j;
    int t;
    int m;

    int in, out;

    note.assign(1000000, 0);

    cin>>t;

    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>note[j];
        }

        sort(note.begin(), note.begin()+n, compare);

        cin>>m;
        for(j=0;j<m;j++)
        {
            cin >> out;
            cout<< binary_search(out)<<'\n';
        }
    }

    return 0;
}