#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<char>> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool canplacehori(vector<vector<char>> &arr,string word,int i,int j)
{
    if(j-1>=0 && arr[i][j-1]!='+')
        return false;
    else if(j+word.length()<=arr[0].size() && arr[i][j+word.length()]!='+')
        return false;
    for(int f=0; f<word.length(); f++)
    {
        if(j+f>=arr[0].size())
            return false;
        if(arr[i][j+f]=='_' || arr[i][j+f] ==word[f])
            continue;
        else
            return false;
    }
    return true;
}
bool canplacehori(vector<vector<char>> &arr,string word,int i,int j)
{
    if(i-1>=0 && arr[i-1][j]!='+')
        return false;
    else if(i+word.length()<=arr[0].size() && arr[i+word.length()][j]!='+')
        return false;
    for(int f=0; f<word.length(); f++)
    {
        if(i+f>=arr[0].size())
            return false;
        if(arr[i+f][j]=='_' || arr[i+f][j] ==word[f])
            continue;
        else
            return false;
    }
    return true;
}
// place and unplace left ----------------------------------------------------------------------------
void solution(vector<vector<char>> &arr,vector<string> &words,int idx)
{
    if(idx==arr.size())
    {
        display(arr);
        return;
    }
    string word=words[idx];
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            if(arr[i][j]=='-' || arr[i][j]==word[0])
            {
                if(canplacehori(arr,word,i,j))
                {
                    placewordhori(arr,word,i,j);
                    solution(arr,words,idx+1);
                    unplacewordhori(arr,word,i,j);
                }
                if(canplaceverti(arr,word,i,j))
                {
                    placewordverti(arr,word,i,j);
                    solution(arr,words,idx+1);
                    unplacewordverti(arr,word,i,j);
                }
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char> (m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }
    int g;
    cin>>g;
    vector<string> words(g);
    for(int i=0; i<g; i++)
    {
        cin>>words[i];
    }
    solution(arr,words,0);
}