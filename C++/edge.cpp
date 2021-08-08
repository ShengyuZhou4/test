#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
vector<long long> dep;
vector<vector<long long> > fa,g;
long long lg(long long x)
{
    return log(x)/log(2);
}
void dfs(long long f,long long x)
{
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    for(long long i=1;(1<<i)<=dep[x];++i)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(long long i=1;i<=n;++i)
    {
        if(g[x][i]==-1)
            continue;
        dfs(x,i);
    }
    return;
}
long long lca(long long x,long long y)
{
    if(dep[x]>dep[y])
        swap(x,y);
    for(long long i=20;i>0;--i)
        if(dep[x]<=dep[y]-(1<<i))
            y=fa[y][i];
    if(x==y)
        return x;
    for(long long i=20;i>=0;--i)
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int main()
{
    freopen("edge.in","r",stdin);
    freopen("edge.out","w",stdout);
    long long T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        dep.clear();
        dep.resize(n+1,0);
        fa.resize(n+1,vector<long long>(21));
        g.clear();
        g.resize(n+1,vector<long long>(n+1,-1));
        for(long long u,v,i=1;i<n;++i)
        {
            cin>>u>>v;
            g[u][v]=0;
            g[v][u]=0;
        }
        dfs(0,1);
        for(long long op,a,b,i=1;i<=m;++i)
        {
            cin>>op>>a>>b;
            long long l=lca(a,b);
            if(op==1)
            {
                for(long long j=a;j!=l;j=fa[j][0])
                    for(long long k=1;k<=n;++k)
                        if(g[j][k]!=-1)
                            g[j][k]=g[k][j]=0;
                for(long long j=b;j!=l;j=fa[j][0])
                    for(long long k=1;k<=n;++k)
                        if(g[j][k]!=-1)
                            g[j][k]=g[k][j]=0;
                for(long long k=1;k<=n;++k)
                    if(g[l][k]!=-1)
                        g[l][k]=g[k][l]=0;
                for(long long j=a;j!=l;j=fa[j][0])
                    g[j][fa[j][0]]=g[fa[j][0]][j]=1;
                for(long long j=b;j!=l;j=fa[j][0])
                    g[j][fa[j][0]]=g[fa[j][0]][j]=1;
            }
            else
            {
                long long ans=0;
                for(long long j=a;j!=l;j=fa[j][0])
                    ans+=g[j][fa[j][0]];
                for(long long j=b;j!=l;j=fa[j][0])
                    ans+=g[j][fa[j][0]];
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}