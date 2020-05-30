#include<bits/stdc++.h>
using namespace std;
int n,maxn,a;
vector<vector<pair<int,int> > > g;
vector<int> aa;
void dfs(int x,int y,int z)
{
    if(z>maxn)
    {
        maxn=z;
        a=x;
    }
    for(int i=0;i<g[x].size();++i)
    {
        if(g[x][i].first==y)
            continue;
        dfs(g[x][i].first,x,z+g[x][i].second);
        aa[g[x][i].first]=max(aa[g[x][i].first],z+g[x][i].second);
    }
}
int main()
{
    cin>>n;
    g.resize(n+1);
    aa.resize(n+1);
    for(int y,l,i=2;i<=n;++i)
    {
        cin>>y>>l;
        g[i].push_back(make_pair(y,l));
        g[y].push_back(make_pair(i,l));
    }
    dfs(1,0,0);
    dfs(a,0,0);
    dfs(a,0,0);
    for(int i=1;i<=n;++i)
        cout<<aa[i]<<'\n';
    return 0;
}