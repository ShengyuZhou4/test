#include<bits/stdc++.h>
using namespace std;
int m,n,d;
vector<vector<char> > v;
void solve()
{
    queue<pair<pair<int,int>,pair<int,int> > > q;
    q.push(make_pair(make_pair(0,d),make_pair(1,1)));
    vector<vector<int> > s(m+2,vector<int>(n+2,-1));
    s[1][1]=d;
    while(!q.empty())
    {
        pair<pair<int,int>,pair<int,int> > p=q.front();
        if(p.second.first==m&&p.second.second==n)
        {
            cout<<p.first.first<<'\n';
            return;
        }
        for(int i=1;i<=max(p.first.second,1);++i)
        {
            if(p.second.first-i==0)
                break;
            if(v[p.second.first-i][p.second.second]=='P'&&p.first.second-(i==1?0:i)>s[p.second.first-i][p.second.second])
            {
                s[p.second.first-i][p.second.second]=p.first.second-(i==1?0:i);
                q.push(make_pair(make_pair(p.first.first+1,p.first.second-(i==1?0:i)),make_pair(p.second.first-i,p.second.second)));
            }
        }
        for(int i=1;i<=max(p.first.second,1);++i)
        {
            if(p.second.first+i==m+1)
                break;
            if(v[p.second.first+i][p.second.second]=='P'&&p.first.second-(i==1?0:i)>s[p.second.first+i][p.second.second])
            {
                s[p.second.first+i][p.second.second]=p.first.second-(i==1?0:i);
                q.push(make_pair(make_pair(p.first.first+1,p.first.second-(i==1?0:i)),make_pair(p.second.first+i,p.second.second)));
            }
        }
        for(int i=1;i<=max(p.first.second,1);++i)
        {
            if(p.second.second-i==0)
                break;
            if(v[p.second.first][p.second.second-i]=='P'&&p.first.second-(i==1?0:i)>s[p.second.first][p.second.second-i])
            {
                s[p.second.first][p.second.second-i]=p.first.second-(i==1?0:i);
                q.push(make_pair(make_pair(p.first.first+1,p.first.second-(i==1?0:i)),make_pair(p.second.first,p.second.second-i)));
            }
        }
        for(int i=1;i<=max(p.first.second,1);++i)
        {
            if(p.second.second+i==n+1)
                break;
            if(v[p.second.first][p.second.second+i]=='P'&&p.first.second-(i==1?0:i)>s[p.second.first][p.second.second+i])
            {
                s[p.second.first][p.second.second+i]=p.first.second-(i==1?0:i);
                q.push(make_pair(make_pair(p.first.first+1,p.first.second-(i==1?0:i)),make_pair(p.second.first,p.second.second+i)));
            }
        }
        q.pop();
    }
    cout<<"impossible\n";
}
int main()
{
    cin>>m>>n>>d;
    v.resize(m+2,vector<char>(n+2));
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin>>v[i][j];
    solve();
    return 0;
}