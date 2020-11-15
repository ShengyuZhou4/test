#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans;
vector<bool> vis;
vector<vector<int> > g;
void dfs(int t)
{
    ++x;
    vis[t]=true;
    y+=g[t].size();
    for(int i=0;i<g[t].size();++i)
        if(!vis[g[t][i]])
            dfs(g[t][i]);
    return;
}
int main()
{
    cin>>n>>m;
    vis.resize(n+1);
    g.resize(n+1);
    for(int u,v,i=0;i<m;++i)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            x=y=0;
            dfs(i);
            if(x==y/2+1)
                ++ans;
        }
    cout<<ans<<'\n';
    return 0;
}