#include <bits/stdc++.h>
#define INF 200000010
#define N 2010
using namespace std;
struct node{
	int v,w;
};
vector <node> a[1001];
int dis[10001];
int main() {
	node t;
	int u,v,w,n,m,s,minn;
	cin>>n>>m>>s;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>w;
		t.v=v;t.w=w;
		a[u].push_back(t);
		t.v=u;t.w=w;
		a[v].push_back(t);		
	}
	
	for(int i=1;i<=n;i++){
		dis[i]= INF;
	}
	dis[s]=0;
	for (int i=1;i<n;i++){
		minn=INF;
		for (int j=1;j<=n;j++){
			if (minn>dis[j]&&h[j]==0){
				u=j;
				minn=dis[j];
			}
		}
		//u¹ý¶É
		h[u] =1;
		for (int j=0;j<a[u].size();j++){
			v=a[u][j].v;
			w=a[u][j].w;
			if (dis[v]>dis[u]+w) dis[v]=dis[u]+w;			
		}
	}
	return 0;
}
