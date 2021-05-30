#include<bits/stdc++.h>
using namespace std;
long long n,k,q;
vector<long long> a,p,aa,pp,temp;
long long merge(long long l,long long m,long long r);
long long rp(long long l,long long r)
{
	if(l==r)
		return 0;
	long long m=(l+r)/2;
	long long ln=rp(l,m),rn=rp(m+1,r),mn=merge(l,m,r);
	return ln+rn+mn;
}
long long merge(long long l,long long m,long long r)
{
	long long cnt=0,i,j;
	for(i=l;i<=r;++i)
		temp[i]=aa[i];
	long long k=l;
	for(i=l,j=m+1;i<=m&&j<=r;++k)
	{
		if(temp[i]>temp[j])
		{
			cnt+=m-i+1;
			aa[k]=temp[j];
			++j;
		}
		else
		{
			aa[k]=temp[i];
			++i;
		}
	}
	if(i>m)
		while(j<=r)
		{
			aa[k]=temp[j];
			++j;
			++k;
		}
	else
		while(i<=m)
		{
			aa[k]=temp[i];
			++i;
			++k;
		}
	return cnt;
}
int main()
{
	cin>>n>>k>>q;
	a.resize(n+1);
	p.resize(k+1);
	pp.resize(k+1);
	for(long long i=1;i<=k;++i)
	{
		p[i]=i;
		pp[p[i]]=i;
	}
	for(long long i=1;i<=n;++i)
		cin>>a[i];
	temp.resize(n+1);
	while(q--)
	{
		long long j;
		cin>>j;
		swap(p[j],p[j+1]);
		pp[p[j]]=j;
		pp[p[j+1]]=j+1;
		aa=a;
		for(long long i=1;i<=n;++i)
			aa[i]=pp[aa[i]];
		cout<<rp(1,n)<<'\n';
	}
	return 0;
}