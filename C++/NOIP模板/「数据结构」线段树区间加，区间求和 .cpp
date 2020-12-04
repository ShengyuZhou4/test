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
}//��� 
const long long INF=0x3f3f3f3f;
struct Segtree{
	long long l,r,sum,tag;//�ṹ�壬l��rΪ���������Ҷ˵㣬sumΪ������ͣ�tagΪ�������ϵı�� 
}tree[400010]; 
long long a[400010],n,m;//n������m������ 
void pushup(long long i){//�����޸� 
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;//�޸������ 
}
void pushdown(long long i){//���´��� 
	tree[i*2].tag+=tree[i].tag;
	tree[i*2+1].tag+=tree[i].tag;//���´��ݱ�� 
	tree[i*2].sum+=(tree[i*2].r-tree[i*2].l+1)*tree[i].tag;
	tree[i*2+1].sum+=(tree[i*2+1].r-tree[i*2+1].l+1)*tree[i].tag;//�޸���һ������ 
	tree[i].tag=0;//���������� 
}
void build(long long i,long long l,long long r){//���� 
	tree[i].l=l;tree[i].r=r;//��ÿ���ڵ㸳��ֵ 
	if(tree[i].l==tree[i].r){
		tree[i].sum=a[l];//����Ҷ�ӽ���ֵ 
		return;
	}
	long long m=(tree[i].l+tree[i].r)/2;//������������ 
	build(i*2,l,m);
	build(i*2+1,m+1,r);//�ֱ�ݹ� 
	pushup(i);//�����޸� 
}
void modify(long long i,long long l,long long r,long long add){//�޸ĺ��� 
	if(l<=tree[i].l&&tree[i].r<=r){//���ȫ�������ڴ��޸���������ֱ���޸� 
		tree[i].sum+=(tree[i].r-tree[i].l+1)*add;//�޸������ 
		tree[i].tag+=add;//���ϱ�� 
		return;//���أ������������ 
	}
	if(tree[i].tag)pushdown(i);//���´��ݱ�� 
	long long m=(tree[i].l+tree[i].r)/2;//������������ 
	if(l<=m)modify(i*2,l,r,add);
	if(m+1<=r)modify(i*2+1,l,r,add);//�������Ҫ����ֱ�ݹ� 
	pushup(i);//�����޸� 
}
long long query(long long i,long long l,long long r){//��ѯ���� 
	if(l<=tree[i].l&&tree[i].r<=r){//���ȫ�������ڴ�����������ֱ�ӷ��� 
		return tree[i].sum;//ֱ�ӷ��� 
	}
	if(tree[i].tag)pushdown(i);//���´��ݱ�� 
	long long m=(tree[i].l+tree[i].r)/2;//������������ 
	long long res=0;
	if(l<=m)res+=query(i*2,l,r);
	if(m+1<=r)res+=query(i*2+1,l,r);//�ֱ�ݹ飬ͳ�ƴ� 
	return res;//���ؽ�� 
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	read(n);read(m);
	for(long long i=1;i<=n;i++)read(a[i]);//���� 
	
	build(1,1,n);//���� 
	
	for(long long i=1;i<=m;i++){//����ÿ������ 
		long long opt;
		read(opt);//����������� 
		if(opt==1){//�޸Ĳ��� 
			long long l,r,x;
			read(l);read(r);read(x);//���� 
			modify(1,l,r,x);//�޸ĺ��� 
		}else{//��ѯ���� 
			long long l,r;
			read(l);read(r);//���� 
			writeln(query(1,l,r));//��ѯ���� 
		}
	} 
	return 0;
}
/*
��ģ��ʹ���߶���+����ǵķ�ʽ�����������⣬ʱ��O(nlogn)���˳����ֱ��ͨ��luogu P3372 ��ģ�塿�߶��� 1
Copyright 2020 Robbie Huang , All rights reserved. 
*/ 
