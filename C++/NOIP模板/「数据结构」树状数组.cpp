#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&-x
const int maxn=1e5+10;
int c[maxn],a[maxn],sum[maxn];
int n,m;
void add(int p)
{
	for(;p<=n;p+=lowbit(p))c[p]++;
}
int q(int p)
{
	int ans=0;
	for(;p;p-=lowbit(p))ans+=c[p];
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
	while(m--)
	{
		int opt,l,r;
		cin>>opt>>l;
		if(opt==1)
		{
			add(l);
		}
		else
		{
			cin>>r;
			cout<<q(r)-q(l-1)+sum[r]-sum[l-1]<<endl;
		}
	}
	return 0;
}
