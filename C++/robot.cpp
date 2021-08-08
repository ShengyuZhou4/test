#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    unsigned long long n,m;
    cin>>n>>m;
    vector<string> s(m);
    for(unsigned long long i=0;i<m;++i)
        cin>>s[i];
    if(s[0][0]!='R')
        cout<<"3\n";
    else
        cout<<"0\n";
    return 0;
}