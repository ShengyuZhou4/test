#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long x,ans=0;
    cin>>x;
    ans+=2*(x/11);
    x%=11;
    if(x==0)
        ;
    else if(x<=6)
        ++ans;
    else
        ans+=2;
    cout<<ans<<'\n';
    return 0;
}