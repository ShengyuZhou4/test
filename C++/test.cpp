#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<int> > v,l;
void solve(int x,int y,int coin,bool magic)
{
    if(coin>=l[x][y]||x==0||y==0||x==m+1||y==m+1)
        return;
    l[x][y]=coin;
    if(x==m&&y==m)
        return;
    if(v[x][y]==v[x-1][y])
        solve(x-1,y,coin,true);
    else
        if(v[x-1][y]!=2)
            solve(x-1,y,coin+1,true);
        else if(magic)
        {
            int t=v[x-1][y];
            v[x-1][y]=v[x][y];
            solve(x-1,y,coin+2,false);
            v[x-1][y]=t;
        }
    if(v[x][y]==v[x+1][y])
        solve(x+1,y,coin,true);
    else
        if(v[x+1][y]!=2)
            solve(x+1,y,coin+1,true);
        else if(magic)
        {
            int t=v[x+1][y];
            v[x+1][y]=v[x][y];
            solve(x+1,y,coin+2,false);
            v[x+1][y]=t;
        }
    if(v[x][y]==v[x][y-1])
        solve(x,y-1,coin,true);
    else
        if(v[x][y-1]!=2)
            solve(x,y-1,coin+1,true);
        else if(magic)
        {
            int t=v[x][y-1];
            v[x][y-1]=v[x][y];
            solve(x,y-1,coin+2,false);
            v[x][y-1]=t;
        }
    if(v[x][y]==v[x][y+1])
        solve(x,y+1,coin,true);
    else
        if(v[x][y+1]!=2)
            solve(x,y+1,coin+1,true);
        else if(magic)
        {
            int t=v[x][y+1];
            v[x][y+1]=v[x][y];
            solve(x,y+1,coin+2,false);
            v[x][y+1]=t;
        }
    return;
}
int main()
{
    cin>>m>>n;
    v.resize(m+2,vector<int>(m+2,2));
    l.resize(m+2,vector<int>(m+2,INT_MAX));
    for(int x,y,i=0;i<n;++i)
    {
        cin>>x>>y;
        cin>>v[x][y];
    }
    solve(1,1,0,true);
    cout<<(l[m][m]==INT_MAX?-1:l[m][m])<<'\n';
    return 0;
}