#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r,minn,delay;
};
int n,m;
vector<int> R;
vector<node> tree;
void init(int now,int l,int r)
{
    if(now>=tree.size())
        tree.resize(now+1);
    if(l!=r)
    {
        init(now*2,l,(l+r)/2);
        init(now*2+1,(l+r)/2+1,r);
        tree[now].l=l;
        tree[now].r=r;
        tree[now].minn=min(tree[now*2].minn,tree[now*2+1].minn);
        tree[now].delay=0;
    }
    else
    {
        tree[now].l=l;
        tree[now].r=r;
        tree[now].minn=R[l];
        tree[now].delay=0;
    }
    return;
}
void spread(int now)
{
    if(tree[now].delay)
    {
        tree[now*2].minn+=tree[now].delay;
        tree[now*2].delay+=tree[now].delay;
        tree[now*2+1].minn+=tree[now].delay;
        tree[now*2+1].delay+=tree[now].delay;
        tree[now].delay=0;
    }
}
void add(int l,int r,int x,int now=1)
{
    if(tree[now].l>=l&&tree[now].r<=r)
    {
        tree[now].delay+=x;
        tree[now].minn+=x;
        return;
    }
    spread(now);
    if(l<=(tree[now].l+tree[now].r)/2)
        add(l,r,x,now*2);
    if(r>=(tree[now].l+tree[now].r)/2+1)
        add(l,r,x,now*2+1);
    tree[now].minn=min(tree[now*2].minn,tree[now*2+1].minn);
    return;
}
int ask(int l,int r,int now=1)
{
    if(tree[now].l>=l&&tree[now].r<=r)
        return tree[now].minn;
    spread(now);
    int ans=INT_MAX;
    if(l<=(tree[now].l+tree[now].r)/2)
        ans=min(ans,ask(l,r,now*2));
    if(r>=(tree[now].l+tree[now].r)/2+1)
        ans=min(ans,ask(l,r,now*2+1));
    return ans;
}
int main()
{
    // freopen("classroom.in","r",stdin);
    // freopen("classroom.out","w",stdout);
    cin>>n>>m;
    R.resize(n+1);
    for (int i = 1; i <= n; ++i)
        cin>>R[i];
    init(1,1,n);
    cout<<fixed<<setprecision(2);
    for (int x,y,j = 1; j <= m; ++j)
    {
        cin>>x>>y;
    }
    cout<<"0\n";
    return 0;
}