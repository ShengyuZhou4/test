#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int v,w;
};
vector<vector<edge> > g;
int n,m,l,cnt;
vector<int> f;
void dfs(int u,int fa)
{
    multiset<int> s;
    vector<edge>::iterator it;
    for(it=g[u].begin();it!=g[u].end();++it)
    {
        int v=it->v,w=it->w;
        if(v==fa)
            continue;
        dfs(v,u);
        if(f[v]+w>=l)
            ++cnt;
        else
            s.insert(f[v]+w);
    }
    while(!s.empty())
    {
        multiset<int>::iterator i1=s.begin();
        s.erase(i1);
        multiset<int>::iterator i2=s.lower_bound(l-*i1);
        if(i2==s.end())
            f[u]=max(f[u],*i1);
        else
        {
            ++cnt;
            s.erase(i2);
        }
        
    }
}
bool check()
{
    for(int i=0;i<=n;++i)
        f[i]=0;
    cnt=0;
    dfs(1,0);
    return cnt>=m;
}
int main()
{
    int lt=0,rt=0,ans=0,mid;
    cin>>n>>m;
    g.resize(n+1);
    f.resize(n+1);
    for(int u,v,w,i=1;i<n;++i)
    {
        cin>>u>>v>>w;
        g[u].push_back((edge){v,w});
        g[v].push_back((edge){u,w});
        rt+=w;lt=min(lt,w);
    }
    while (lt<=rt)
    {
        mid=(lt+rt)/2;
        l=mid;
        if(check())
        {
            ans=mid;
            lt=mid+1;
        }
        else
            rt=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}