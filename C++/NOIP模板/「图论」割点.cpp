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

int n, m, dfn[Maxn], low[Maxn], cur, ans, color[Maxn];

void tarjan(int v) {
	dfn[v] = low[v] = ++cur;
	color[v] = -1;
	int cnum = 0;
	bool sta = false;
	for (edge *p = g[v]; p; p = p->nxt) {
		if (p->v != v) {
			++cnum;
			if (color[p->v] == 0) {
				tarjan(p->v);
				low[v] = min(low[v], low[p->v]);
				if (v == 1 && cnum >= 2) {
					sta = true;
				}
				if (v != 1 && low[p->v] >= dfn[v]) {
					sta = true;
				}
			}
			else {
				if (color[p->v] == -1) {
					low[v] = min(low[v], dfn[p->v]);
				}
			}
		}
	}
	if (sta) {
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
	tarjan(1);
	printf("%d\n", ans);
	return 0;
}
