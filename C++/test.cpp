#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > a((1<<n)+1); 
    for (int i = 1; i < a.size(); ++i)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin()+1,a.begin()+(1<<n)/2+1);
    sort(a.begin()+(1<<n)/2+1,a.end());
    cout<<(a[(1<<n)/2].first<a.back().first?a[(1<<n)/2].second:a.back().second)<<'\n';
    return 0;
}