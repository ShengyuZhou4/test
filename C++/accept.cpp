#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,c;
double p,d,ans=0;
void solve(long long x,long long y,double z,long long sum)
{
    if(y==0)
    {
        ans+=sum*z;
        return;
    }
    if(x==0)
    {
        solve(0,y-1,z*(1-p),sum+a);
        solve(m,y-1,z*p,sum+a);
    }
    else
    {
        solve(m-1,y-1,z*(1-d),sum+b);
        solve(m-1,y-1,z*d,sum+c);
    }
    return;
}
int main()
{
    cin>>n>>m>>p>>d>>a>>b>>c;
    solve(0,n,1-p,0);
    solve(m,n,p,0);
    cout<<fixed<<setprecision(4)<<ans<<'\n';
    return 0;
}