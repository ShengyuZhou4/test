#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long> head,ver(1,0),nxt(1,0),edge(1,0),d;
void add(unsigned long long x,unsigned long long y,unsigned long long z)
{
    ver.push_back(y);
    edge.push_back(z);
    nxt.push_back(head[x]);
    head[x]=ver.size()-1;
    return;
}
int main()
{
    unsigned long long n,k;
    char c;
    cin>>n>>k;
    head.resize(n+1,0);
    d.resize(n+1,UINT_MAX);
    vector<unsigned long long> b(n+1);
    for(unsigned long long i=1;i<=n;++i)
        cin>>b[i];
    vector<vector<bool> > s(k+1,vector<bool>(k+1));
    for(unsigned long long i=1;i<=k;++i)
        for(unsigned long long j=1;j<=k;++j)
        {
            cin>>c;
            s[i][j]=(c=='1');
        }
    vector<bool> v(n+1,false);
    for(unsigned long long i=1;i<=n;++i)
        for(unsigned long long j=1;j<=n;++j)
            if(i!=j&&s[b[i]][b[j]])
                add(i,j,max(i,j)-min(i,j));
    d[1]=0;
    priority_queue<pair<unsigned long long,unsigned long long>,vector<pair<unsigned long long,unsigned long long> >,greater<pair<unsigned long long,unsigned long long> > > q;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        unsigned long long x=q.top().second;
        q.pop();
        if(v[x])
            continue;
        v[x]=true;
        for(unsigned long long i=head[x];i;i=nxt[i])
            if(d[ver[i]]>d[x]+edge[i])
            {
                d[ver[i]]=d[x]+edge[i];
                q.push(make_pair(d[ver[i]],ver[i]));
            }
    }
    if(d[n]==UINT_MAX)
        cout<<"-1\n";
    else
        cout<<d[n]<<'\n';
    return 0;
}