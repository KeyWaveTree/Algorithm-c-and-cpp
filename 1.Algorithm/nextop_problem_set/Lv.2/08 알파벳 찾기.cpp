#include<iostream>

using namespace std;

int main()
{
    string word;
    int score[26] = { 0 };
    int i;

    cin>> word;

    for(i=0;i<26;i++)score[i]=-1;

    for(i=0;i<word.length();i++)
    {
        if(score[word[i]-'a'] != -1) continue;
        score[word[i]-'a'] = i;
    }

    for(i=0;i<26;i++)
    {
        cout<< score[i]<<' ';
    }

    return 0;
}