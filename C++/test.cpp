#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    list<pair<int,int> > d;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0)
        {
            d.push_back(make_pair(b,c));
            ans+=b;
        }
        else
        {
            bool f=true;
            for(list<pair<int,int> >::iterator i=d.begin();i!=d.end();)
            {
                if(i->second+45<c)
                {
                    list<pair<int,int> >::iterator t=i;
                    ++i;
                    d.erase(t);
                }
                else if(i->first>=b)
                {
                    f=false;
                    d.erase(i);
                    break;
                }
                else
                    ++i;
            }
            if(f)
                ans+=b;
        }
    }
    cout<<ans<<'\n';
    return 0;
}