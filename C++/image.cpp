#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        vector<vector<char> > A(N,vector<char>(N)),B(M,vector<char>(M));
        bool ans=false;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                cin>>A[i][j];
        for(int i=0;i<M;++i)
            for(int j=0;j<M;++j)
                cin>>B[i][j];
        for(int i=0;i<=N-M;++i)
        {
            for(int j=0;j<=N-M;++j)
            {
                bool flag=true;
                for(int x=0;x<M;++x)
                {
                    for(int y=0;y<M;++y)
                        if(A[x+i][y+j]!=B[x][y])
                        {
                            flag=false;
                            break;
                        }
                    if(!flag)
                        break;
                }
                if(flag)
                {
                    ans=true;
                    break;
                }
            }
            if(ans)
                break;
        }
        cout<<(ans?"Yes\n":"No\n");
    }
    return 0;
}