#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 11111, Maxm = 55555;
struct edge {
	int v;
	edge *nxt;
} pool[Maxm], *tail = pool, *g[Maxn];
inline void addedge(const int &u, const int &v) {
	tail->v = v;
	tail->nxt = g[u], g[u] = tail++;
}

int n, m, color[Maxn], dfn[Maxn], low[Maxn], cur, st[Maxn];
int top, cnt, belong[Maxn], size[Maxn], outd[Maxn];

void tarjan(int v) {
	color[v] = -1, st[++top] = v, dfn[v] = low[v] = ++cur;
	for (edge *p = g[v]; p; p = p->nxt) {
		if (color[p->v] == 0) {
			tarjan(p->v);
			low[v] = min(low[v], low[p->v]);
		} else {
			if (color[p->v] == -1) {
				low[v] = min(low[v], dfn[p->v]);
			}
		}
	}
	if (dfn[v] == low[v]) {
		++cnt;
		size[cnt] = 1;
		while (st[top] != v) {
			color[st[top]] = 1;
			belong[st[top--]] = cnt;
			++size[cnt];
		}
		color[v] = 1;
		belong[st[top--]] = cnt;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (edge *p = g[i]; p; p = p->nxt) {
			if (belong[i] != belong[p->v]) {
				++outd[belong[i]];
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= cnt; ++i) {
		if (!outd[i]) {
			++sum;
		}
	}
	if (sum > 1) {
		puts("0");
	} else {
		for (int i = 1; i <= cnt; ++i) {
			if (!outd[i]) {
				printf("%d\n", size[i]);
				break;
			}
		}
	}
	return 0;
}
