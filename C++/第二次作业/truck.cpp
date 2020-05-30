#include<bits/stdc++.h>
using namespace std;
int w[100001][21],p[100001][21],head[1000001],deep[1000001],fa[1000001];
struct nodea
{
    int x,y,c;
}t[1000001];
struct nodeb
{ 
    int x,y,c,g; 
}h[1000001];
int inf=999999999,len=0,n=0,m=0,q=0;
void px(int l,int r)
{
    int x=l,y=r,mid=t[(l+r)/2].c;
    while(x<=y)
    {
        while(t[x].c>mid)
            ++x;
        while(t[y].c<mid)
            --y;
        if(x<=y)
        {
            nodea pt=t[x];
            t[x]=t[y];
            t[y]=pt;
            ++x;
            --y;
        }
    }
    if(l<y)
        px(l,y);
    if(x<r)
        px(x,r);
}
int min(int x,int y)
{
    return x<y?x:y;
}
int init()
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        head[i]=0;
        deep[i]=0;
    }
}
void ins(int x,int y,int c)
{
    len++;
    h[len].x=x;
    h[len].y=y;
    h[len].c=c;
    h[len].g=head[x];
    head[x]=len;
}
int find(int t)
{
    if(fa[t]==t)
        return t;
    else
        return fa[t]=find(fa[t]);
}
void kruskal()
{
    int p=0;
    for(int i=1;i<=m;++i)
    {
        int tx=find(t[i].x);
        int ty=find(t[i].y);
        if(tx!=ty)
        {
            fa[tx]=ty;
            ins(t[i].x,t[i].y,t[i].c);
            ins(t[i].y,t[i].x,t[i].c);
            ++p;
            if(p==n-1)
                break;
        }
    }
}
void dfs(int u)
{
    for(int i=head[u];i>0;i=h[i].g)
    {
        int y=h[i].y;
        if(deep[y]==0)
        {
            deep[y]=deep[u]+1;
            p[y][0]=u;
            w[y][0]=h[i].c;
            dfs(y);
        }
    }
}
void ycl()
{
    for(int i=1;i<=n;++i)
    {
        if(deep[i]==0)
        {
            deep[i]=1;
            p[i][0]=0;
            dfs(i);
        }    
    }
    dfs(1);
    for(int i=1;i<=20;++i)
    {
        for(int x=1;x<=n;++x)
        {
            p[x][i]=p[p[x][i-1]][i-1];
            w[x][i]=min(w[x][i-1],w[p[x][i-1]][i-1]);
        }
    }
}
int lca(int x,int y)
{
    int ans=inf;
    if(deep[x]<deep[y])
    {
        int t=x;
        x=y;
        y=t;
    }
    for(int i=20;i>=0;--i)
    {
        if(deep[p[x][i]]>=deep[y])
        {
            ans=min(ans,w[x][i]);
            x=p[x][i];
        }
    }
    if(x==y)
    {
        return ans;
    }
    for(int i=20;i>=0;--i)
    {
        if(p[x][i]!=p[y][i])
        {
            ans=min(ans,min(w[x][i],w[y][i]));
            x=p[x][i];
            y=p[y][i];
        }
    }
    ans=min(ans,min(w[x][0],w[y][0]));
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>t[i].x>>t[i].y>>t[i].c;
    }
    px(1,m);
    init();
    kruskal();
    ycl();
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        int dx=0,dy=0;
        cin>>dx>>dy;
        if(find(dx)!=find(dy))
            cout<<"-1\n";
        else
            cout<<lca(dx,dy)<<'\n';
    }
    return 0;
}