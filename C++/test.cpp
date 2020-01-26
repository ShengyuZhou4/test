#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n;
    vector<int> a(n+1),b(n+1),g(n+1),k(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    cin>>x>>y;
    for(int i=n;i>=1;--i)
        if(a[i]<=x&&x<a[i]+g[i]&&b[i]<=y&&y<b[i]+k[i])
        {
            cout<<i<<'\n';
            return 0;
        }
    cout<<"-1\n";
    return 0;
}