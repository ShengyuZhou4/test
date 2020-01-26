#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n;
    for(int i=n;i>=0;--i)
    {
        cin>>t;
        if(t==0)
            continue;
        if(i!=n&&t>0)
            cout<<'+';
        if(t<0)
            cout<<'-';
        t=abs(t);
        if((i>=1&&t!=1)||i==0)
            cout<<t;
        if(i>1)
            cout<<"x^"<<i;
        if(i==1)
            cout<<'x';
    }
    cout<<'\n';
    return 0;
}