#include<bits/stdc++.h>
using namespace std;
vector<bool> mem,v;
bool win(long long x)
{
    if(v[x])
        return mem[x];
    v[x]=true;
    long long minn=LLONG_MAX,maxn=0,t=x;
    while(t)
    {
        if(t%10==0)
        {
            t/=10;
            continue;
        }
        minn=min(minn,t%10);
        maxn=max(maxn,t%10);
        t/=10;
    }
    return mem[x]=!(win(x-minn)&&win(x-maxn));
}
int main()
{
    long long G;
    cin>>G;
    while(G--)
    {
        long long n;
        cin>>n;
        mem.resize(n+1,false);
        v.resize(n+1,false);
        v[0]=true;
        cout<<(win(n)?"Yes\n":"No\n");
    }
    return 0;
}