#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(register T &x){
    register long long ff=1;x=0;register char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')ff=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=ff;
}
template<typename T>inline void write(register T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>inline void writeln(register T x){
    write(x);
    putchar('\n');
}//快读 
const long long INF=0x3f3f3f3f;
struct Segtree{
	long long l,r,sum,tag;//结构体，l，r为该区间左右端点，sum为该区间和，tag为该区间上的标记 
}tree[400010]; 
long long a[400010],n,m;//n个数，m个操作 
void pushup(long long i){//向上修改 
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//修改区间和 
}
void pushdown(long long i){//向下传递 
	tree[i*2].tag+=tree[i].tag;
	tree[i*2+1].tag+=tree[i].tag;//向下传递标记 
	tree[i*2].sum+=(tree[i*2].r-tree[i*2].l+1)*tree[i].tag;
	tree[i*2+1].sum+=(tree[i*2+1].r-tree[i*2+1].l+1)*tree[i].tag;//修改下一层区间 
	tree[i].tag=0;//清除本级标记 
}
void build(long long i,long long l,long long r){//建树 
	tree[i].l=l;tree[i].r=r;//给每个节点赋初值 
	if(tree[i].l==tree[i].r){
		tree[i].sum=a[l];//处理叶子结点的值 
		return;
	}
	long long m=(tree[i].l+tree[i].r)/2;//二分左右区间 
	build(i*2,l,m);
	build(i*2+1,m+1,r);//分别递归 
	pushup(i);//向上修改 
}
void modify(long long i,long long l,long long r,long long add){//修改函数 
	if(l<=tree[i].l&&tree[i].r<=r){//如果全部包含在待修改区间里则直接修改 
		tree[i].sum+=(tree[i].r-tree[i].l+1)*add;//修改区间和 
		tree[i].tag+=add;//打上标记 
		return;//返回，不需继续向下 
	}
	if(tree[i].tag)pushdown(i);//向下传递标记 
	long long m=(tree[i].l+tree[i].r)/2;//二分左右区间 
	if(l<=m)modify(i*2,l,r,add);
	if(m+1<=r)modify(i*2+1,l,r,add);//如果满足要求则分别递归 
	pushup(i);//向上修改 
}
long long query(long long i,long long l,long long r){//查询函数 
	if(l<=tree[i].l&&tree[i].r<=r){//如果全部包含在待求区间里则直接返回 
		return tree[i].sum;//直接返回 
	}
	if(tree[i].tag)pushdown(i);//向下传递标记 
	long long m=(tree[i].l+tree[i].r)/2;//二分左右区间 
	long long res=0;
	if(l<=m)res+=query(i*2,l,r);
	if(m+1<=r)res+=query(i*2+1,l,r);//分别递归，统计答案 
	return res;//返回结果 
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	read(n);read(m);
	for(long long i=1;i<=n;i++)read(a[i]);//读入 
	
	build(1,1,n);//建树 
	
	for(long long i=1;i<=m;i++){//处理每个问题 
		long long opt;
		read(opt);//读入操作类型 
		if(opt==1){//修改操作 
			long long l,r,x;
			read(l);read(r);read(x);//读入 
			modify(1,l,r,x);//修改函数 
		}else{//查询操作 
			long long l,r;
			read(l);read(r);//读入 
			writeln(query(1,l,r));//查询函数 
		}
	} 
	return 0;
}
/*
本模板使用线段树+懒标记的方式解决区间加问题，时间O(nlogn)，此程序可直接通过luogu P3372 【模板】线段树 1
Copyright 2020 Robbie Huang , All rights reserved. 
*/ 
