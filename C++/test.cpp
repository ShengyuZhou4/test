#include<bits/stdc++.h>
using namespace std;
int d,ans;
vector<int> v;
vector<char> c;
void solve()
{
    if(c.size()==d-1)
    {
        int s=0,t=v[0];
        for(int i=0;i<d-1;++i)
        {
            if(c[i]=='+')
            {
                s+=t;
                t=v[i+1];
            }
            if(c[i]=='-')
            {
                s+=t;
                t=-v[i+1];
            }
            if(c[i]=='*')
                t*=v[i+1];
        }
        s+=t;
        if(s==24)
            ++ans;
        return;
    }
    c.push_back('+');
    solve();
    c.pop_back();
    c.push_back('-');
    solve();
    c.pop_back();
    c.push_back('*');
    solve();
    c.pop_back();
    return;
}
int main()
{
    cin>>d;
    v.resize(d);
    for(int i=0;i<d;++i)
        cin>>v[i];
    solve();
    cout<<ans<<'\n';
    return 0;
}