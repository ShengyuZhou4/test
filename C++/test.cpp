#include<bits/stdc++.h>
using namespace std;
struct hole
{
    long long x,y,z;
};
int main()
{
    long long  T;
    cin>>T;
    while(T--)
    {
        long long n,h,r;
        cin>>n>>h>>r;
        vector<hole> cheese(n+1);
        for(long long i=1;i<=n;++i)
            cin>>cheese[i].x>>cheese[i].y>>cheese[i].z;
        vector<vector<long long> > graph(n+2);
        for(long long i=1;i<=n;++i)
        {
            if(cheese[i].z<=r)
            {
                graph[0].push_back(i);
                graph[i].push_back(0);
            }
            if(cheese[i].z+r>=h)
            {
                graph[n+1].push_back(i);
                graph[i].push_back(n+1);
            }
            for(long long j=i+1;j<=n;++j)
            {
                if(sqrt((cheese[i].x-cheese[j].x)*(cheese[i].x-cheese[j].x)+(cheese[i].y-cheese[j].y)*(cheese[i].y-cheese[j].y)+(cheese[i].z-cheese[j].z)*(cheese[i].z-cheese[j].z))<=2*r)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);   
                }
            }
        }
        queue<long long> q;
        q.push(0);
        set<long long> s;
        bool flag=false;
        while(!q.empty())
        {
            if(s.count(q.front()))
            {
                q.pop();
                continue;
            }
            if(q.front()==n+1)
            {
                flag=true;
                break;
            }
            s.insert(q.front());
            for(long long i=0;i<graph[q.front()].size();++i)
                q.push(graph[q.front()][i]);
            q.pop();
        }
        cout<<(flag==true?"Yes\n":"No\n");
    }
    return 0;
}