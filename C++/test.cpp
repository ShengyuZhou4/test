#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
vector<vector<int> > v,ans;
void solve(int a,int b,int c)
{
    if(ans[a][b]<=c||a<1||a>n||b<1||b>m)
        return;
    ans[a][b]=c;
    solve(a-1,b,c+(v[a][b]==v[a-1][b]?0:1));
    solve(a+1,b,c+(v[a][b]==v[a+1][b]?0:1));
    solve(a,b-1,c+(v[a][b]==v[a][b-1]?0:1));
    solve(a,b+1,c+(v[a][b]==v[a][b+1]?0:1));
}
int main()
{
    cin>>n>>m>>x>>y;
    v.resize(n+2,vector<int>(m+2));
    ans.resize(n+2,vector<int>(m+2,INT_MAX));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>v[i][j];
    solve(x,y,0);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cout<<ans[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}