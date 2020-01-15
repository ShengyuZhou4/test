#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t,sum,ans=1;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>t;
        if(sum+t>m)
        {
            ++ans;
            sum=t;
        }
        else
            sum+=t;
    }
    cout<<ans<<'\n';
    return 0;
}