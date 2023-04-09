#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> graph;
void addedges(int u,int v,int w)
{
    pair<int,int> p1(v,w);
    pair<int,int> p2(u,w);
    graph[u].push_back(p1);
    graph[v].push_back(p2);
}
void display()
{
    for(int i=0; i<graph.size(); i++)
    {
        cout<<" "<<i<<" -> "; 
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j].first<<" "<<graph[i][j].second<<" ";
        }
        cout<<endl;
    }
}
void dfs(int i,vector<bool> &vis,string ans,int dis)
{
    if(i==graph.size()-1)
    {
        cout<<ans<<" "<<dis<<endl;
        return;
    }
    vis[i]=true;
    for(pair<int,int> e : graph[i])
    {
        if(!vis[e.first])
            dfs(e.first,vis,ans+"->"+to_string(e.first),dis+e.second);
    }
}
vector<pair<int,int>> bfs(int i,vector<bool> &vis)
{
    vector<pair<int,int>> ans;
    queue<pair<int,int>> q;
    pair<int,int> g(i,0);
    q.push(g);
    vis[i]=true;
    while(!q.empty())
    {
        pair<int,int> x=q.front();
        q.pop();
        ans.push_back(x);
        for(pair<int,int> e : graph[x.first])
        {
            if(!vis[e.first])
            {
                pair<int,int> p1(e.first,e.second);
                q.push(p1);
                vis[e.first]=true;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        vector<pair<int,int>> ar;
        graph.push_back(ar);
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l,r,w;
        cin>>l>>r>>w;
        addedges(l,r,w);
    }
    display();
    vector<bool> vis(n,false);
    vector<bool> vis1(n,false);
    dfs(0,vis,"0",0);
    vector<pair<int,int>> as=bfs(0,vis1);
    int d=0;
    for(pair<int,int> e : as)
    {
        d+=e.second;
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<d<<endl;
}