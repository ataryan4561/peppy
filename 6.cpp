#include<bits/stdc++.h>
using namespace std;
int maxi=0;
void solution(vector<vector<int>> &arr,int i,int j,vector<vector<bool>> &vis,vector<int> &bag)
{
    if(i<0 || j<0 || j>=arr[i].size() || i>=arr.size() || vis[i][j]==true || arr[i][j]==0)
    {
        return;
    } 
    vis[i][j]=true;
    bag.push_back(arr[i][j]);
    solution(arr,i+1,j,vis,bag);
    solution(arr,i,j+1,vis,bag);
    solution(arr,i-1,j,vis,bag);
    solution(arr,i,j-1,vis,bag);
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
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]!=0 && vis[i][j]==false)
            {
                vector<int> bag;
                solution(arr,i,j,vis,bag);
                int s=0;
                for(auto e: bag)
                {
                    s+=e;
                }
                maxi=max(maxi,s);
            }
        }
    }
    cout<<maxi<<endl;
}