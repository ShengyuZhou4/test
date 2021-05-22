#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<bool> > v;
vector<pair<int,int> > p;
set<pair<int,int> > s;
void dfs(int x,int y)
{
	if(s.find(make_pair(x,y))!=s.end())
		return;
	s.insert(make_pair(x,y));
	p.push_back(make_pair(x,y));
	if(x==n&&y==m)
	{
		for(int i=0;i<p.size();++i)
			cout<<'('<<p[i].first<<','<<p[i].second<<")\n";
		cout<<"\n";
	}
	else
	{
		if(!v[x+1][y])
			dfs(x+1,y);
		if(!v[x-1][y])
			dfs(x-1,y);
		if(!v[x][y+1])
			dfs(x,y+1);
		if(!v[x][y-1])
			dfs(x,y-1);
	}
	s.erase(make_pair(x,y));
	p.pop_back();
	return;
}
int main()
{
	cin>>n>>m;
	v.resize(n+2,vector<bool>(m+2,true));
	for(int t,i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>t;
			v[i][j]=t;
		}
	dfs(1,1);
	return 0;
}
