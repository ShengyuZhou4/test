#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 11111, Maxm = 55555;
struct edge {
	int v;
	edge *nxt;
} pool[Maxm<<1], *tail = pool, *g[Maxn];
inline void addedge(int v1, int v2) {
	tail->v = v2;
	tail->nxt = g[v1], g[v1] = tail++;
}

int n, m, dfn[Maxn], low[Maxn], cur, ans, color[Maxn], st[Maxn];

void tarjan(int v, int fa) {
	dfn[v] = low[v] = ++cur, color[v] = -1;
	for (edge *p = g[v]; p; p = p->nxt) {
		if (color[p->v] == 0) {
			tarjan(p->v, v);
			low[v] = min(low[v], low[p->v]);
		} else {
			if (color[p->v] == -1 && p->v != fa) {
				low[v] = min(low[v], dfn[p->v]);
			}
		}
	}
	if (low[v] == dfn[v]) {
		++ans;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	tarjan(1, 0);
	printf("%d\n", ans-1);
	return 0;
}
