#include<iostream>

using namespace std;

int arr[1001];
int main()
{
    int n, k;
    int i, j;
    int temp;

    cin>> n>> k;
    for(i=1;i<=n;i++) cin >> arr[i];

    //내림차순 정렬
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            //만약 앞에있는 값이 뒤에 있는 값보다 훨신 작다면
            if(arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<< arr[k];
    return 0;
}