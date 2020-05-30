#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<vector<char> > v(n,vector<char>(n));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>v[i][j];
    }
    return 0;
}