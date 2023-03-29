#include<bits/stdc++.h>
using namespace std;
int c=0;
void solution(int i,int n,vector<bool> &vis,string ans)
{
    if(i>n)
    {
        cout<<ans<<endl;
        c++;
        return;
    }
    if(vis[i])
    {
        solution(i+1,n,vis,ans);
    }
    else
    {
        vis[i]=true;
        solution(i+1,n,vis,ans+"("+to_string(i)+")");
        for(int j=i+1; j<=n; j++)
        {
            vis[j]=true;
            solution(i+1,n,vis,ans+"("+to_string(i)+to_string(j)+")");
            vis[j]=false;
        }
        vis[i]=false;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<bool> vis(n+1,false);
    solution(1,n,vis,"");
    cout<<c<<endl;
}