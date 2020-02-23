#include<bits/stdc++.h>
using namespace std;
struct position
{
    int a,b,c,d,e,f,g,h,i;
    long long step;
}f,t,mb;
bool vis[400000];
queue<position> q;
int ans;
inline int jc(int n)
{
    int num=1;
    for(int i=2;i<=n;i++)
        num*=i;
    return num;
}
inline int ktzk(position f)
{
    int a[15],num=0;
    bool v[15];
    for(int i=0;i<=10;i++)
        a[i]=v[i]=0;
    a[0]=f.a,a[1]=f.b,a[2]=f.c,a[3]=f.d,a[4]=f.e,a[5]=f.f,a[6]=f.g,a[7]=f.h,a[8]=f.i;   
    for(int j=0;j<9;j++)
    {
        int x=a[j]; 
        int s=0;
        for(int i=0;i<x;i++)
            if(v[i]==0)
                s++;
        v[x]=1;
        num+=s*jc(9-j-1);
    }
    return num;
} 
int main()
{
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d",&f.a,&f.b,&f.c,&f.d,&f.e,&f.f,&f.g,&f.h,&f.i);
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d",&mb.a,&mb.b,&mb.c,&mb.d,&mb.e,&mb.f,&mb.g,&mb.h,&mb.i);
    f.step=0;
    q.push(f);
    ans=ktzk(mb);//1 2 3 8 0 4 7 6 5
    while(!q.empty())
    {
        f=q.front();
        q.pop();
        int x=ktzk(f);
        if(x==ans)
        {
            printf("%lld\n",f.step);
            return 0;
        }
        if(vis[x]==1)
            continue;
        vis[x]=1;
        f.step++;
        if(f.a==0)
        {
            t=f;
            swap(t.a,t.b);
            q.push(t);
            t=f;
            swap(t.a,t.d);
            q.push(t);
        }
        else if(f.b==0)
        {
            t=f;
            swap(t.b,t.a);
            q.push(t);
            t=f;
            swap(t.b,t.c);
            q.push(t);
            t=f;
            swap(t.b,t.e);
            q.push(t);
        }
        else if(f.c==0)
        {
            t=f;
            swap(t.c,t.b);
            q.push(t);
            t=f;
            swap(t.c,t.f);
            q.push(t);  
        }
        else if(f.d==0)
        {
            t=f;
            swap(t.d,t.a);
            q.push(t);
            t=f;
            swap(t.d,t.e);
            q.push(t);
            t=f;
            swap(t.d,t.g);
            q.push(t);
        }
        else if(f.e==0)
        {
            t=f;
            swap(t.e,t.b);
            q.push(t);
            t=f;
            swap(t.e,t.d);
            q.push(t);
            t=f;
            swap(t.e,t.f);
            q.push(t);
            t=f;
            swap(t.e,t.h);
            q.push(t);
        }
        else if(f.f==0)
        {
            t=f;
            swap(t.f,t.c);
            q.push(t);
            t=f;
            swap(t.f,t.e);
            q.push(t);
            t=f;
            swap(t.f,t.i);
            q.push(t);
        }
        else if(f.g==0)
        {
            t=f;
            swap(t.g,t.d);
            q.push(t);
            t=f;
            swap(t.g,t.h);
            q.push(t);
        }
        else if(f.h==0)
        {
            t=f;
            swap(t.h,t.i);
            q.push(t);
            t=f;
            swap(t.h,t.e);
            q.push(t);
            t=f;
            swap(t.h,t.g);
            q.push(t);
        }
        else if(f.i==0)
        {
            t=f;
            swap(t.i,t.h);
            q.push(t);
            t=f;
            swap(t.i,t.f);
            q.push(t);
        }
    }
    printf("impossible\n");
    return 0;
}