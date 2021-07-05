#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<pair<pair<long long,long long>,long long> > n,e;
	long long N;
	cin>>N;
	vector<long long> ans(N+1,LLONG_MAX);
	for(long long x,y,i=1;i<=N;++i)
	{
		char c;
		cin>>c;
		cin>>x>>y;
		if(c=='N')
			n.push_back(make_pair(make_pair(x,y),i));
		else
			e.push_back(make_pair(make_pair(x,y),i));
	}
	for(long long i=0;i<n.size();++i)
	{
		for(long long j=0;j<e.size())
			if(e[j].first.second-n[i].first.second+e[j].first.first>n[i].first.first)
				ans[n[i].second]=min(ans[n[i].second],e[j].first.second-n[i].first.second);
		for(long long j=0;j<n.size();++j)
		{
			if(i==j)
				continue;
			if(n[i].first.first==n[j].first.first&&n[i].first.second<n[j].first.second)
				ans[n[i].second]=min(ans[n[i].second],n[j].first.second-n[i].first.second);
		}
	}
	// for(long long i=0;i<e.size();++i)
	// {
	// 	for(long long j=0;j<n.size())
	// 		if(n[j].first.second-n[i].first.second+e[j].first.first>n[i].first.first)
	// 			ans[n[i].second]=min(ans[n[i].second],e[j].first.second-n[i].first.second);
	// 	for(long long j=0;j<n.size();++j)
	// 	{
	// 		if(i==j)
	// 			continue;
	// 		if(n[i].first.first==n[j].first.first&&n[i].first.second<n[j].first.second)
	// 			ans[n[i].second]=min(ans[n[i].second],n[j].first.second-n[i].first.second);
	// 	}
	// }
	return 0;
}