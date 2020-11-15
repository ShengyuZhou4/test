#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,maxn=0,sum=0;
    cin>>n;
    vector<int> w(n+1);
    vector<vector<int> > tree(n+1);
    for(int u,v,i=1;i<n;++i)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        cin>>w[i];
    for(int i=1;i<=n;++i)
    {
        int sum1=0,sum2=0,max1=0,max2=0;
        for(int j=0;j<tree[i].size();++j)
        {
            if(w[tree[i][j]]>max1)
            {
                max2=max1;
                max1=w[tree[i][j]];
            }
            else if(tree[i][j]>max2)
                max2=w[tree[i][j]];
            sum1+=w[tree[i][j]]%10007;
            sum1%=10007;
            sum2+=w[tree[i][j]]%10007*w[tree[i][j]]%10007;
            sum2%=10007;
        }
        sum1*=sum1;
        sum1%=10007;
        maxn=max(maxn,max1*max2);
        sum+=sum1-sum2;
        sum%=10007;
    }
    cout<<maxn<<' '<<sum;
    return 0;
}