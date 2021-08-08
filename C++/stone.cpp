#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,sum=0,tt=0,ans=ULLONG_MAX;
    cin>>n;
    vector<unsigned long long> a(n);
    for(unsigned long long i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(unsigned long long i=2;i<=sum;++i)
    {
        if(sum%i)
            continue;
        sum/=i;
        tt=0;
        for(unsigned long long j=0;j<n;++j)
            tt+=min(a[j]%i,i-a[j]%i);
        ans=min(ans,tt/2);
    }
    cout<<ans<<'\n';
    return 0;
}