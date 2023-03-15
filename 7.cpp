#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<int>> &arr,int x,int y,int p)
{
    for(int i=0; i<arr[x].size(); i++)
    {
        if(arr[i][y]==p)
        {
            return false;
        }
    }
    for(int j=0; j<arr[y].size(); j++)
    {
        if(arr[x][j]==p)
        {
            return false;
        }
    }
    int smi=x/3*3;
    int smj=y/3*3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[smi+i][smj+j]==p)
            {
                return false;
            }
        }
    }
    return true;
}
void soltion(vector<vector<int>> &arr,int i,int j)
{
    if(i==arr.size())
    {
        return;
    }
    int ni=0;
    int nj=0;
    if(j==arr[0].size()-1)
    {
        nj=0;
        ni=i+1;
    }
    else
    {
        ni=i;
        nj=j+1;
    }
    if(arr[i][j]!=0)
    {
        soltion(arr,ni,nj);
    }
    else
    {
        for(int p=1; p<=9; p++)
        {
            if(isvalid(arr,i,j,p)==true)
            {
                arr[i][j]=p;
                soltion(arr,ni,nj);
                arr[i][j]=0;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }
    soltion(arr,0,0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}