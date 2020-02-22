#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 11111, Maxm = 55555;
struct edge {
	int v;
	edge *nxt;
} pool[Maxm<<1], *tail = pool, *g[Maxn];

int n, m, dfn[Maxn], low[Maxn], st[Maxn], top, cur, tot, color[Maxn];

inline void addedge(int v1, int v2) {
	tail->v = v2;
	tail->nxt = g[v1];
	g[v1] = tail++;
}
void tarjan(int v, int last) {
	st[++top] = v, dfn[v] = low[v] = ++cur, color[v] = -1;
	for (edge *p = g[v]; p; p = p->nxt) {
		if (p->v != last) {
			if (color[p->v] == 0) {
				tarjan(p->v, v);
				low[v] = min(low[v], low[p->v]);
			} else {
				if (color[p->v] == -1) {
					low[v] = min(low[v], dfn[p->v]);
				}
			}
		}
	}
	if (dfn[v] == low[v]) {
		++tot;
		while (st[top] != v) {
			color[st[top--]] = 1;
		}
		color[v] = 1;
		--top;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		addedge(v1, v2);
		addedge(v2, v1);
	}
	tarjan(1, -1);
	printf("%d\n", tot);
	return 0;
}

