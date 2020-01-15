#include <bits/stdc++.h>
#define INF 200000010
#define N 2010
using namespace std;
int tot(1), m, n, to[N], fir[N], nxt[N], l[N], d[N], used[N];

struct que {
	int id, dis;
	que (int a, int b) {
		id = a, dis = b;
	}
	bool operator < (const que &r) const {
		return dis > r.dis;
	}
};
void add(int u, int v, int w) {
	to[++tot] = v; nxt[tot] = fir[u]; fir[u] = tot; l[tot] = w;
	to[++tot] = u; nxt[tot] = fir[v]; fir[v] = tot; l[tot] = w;
}

priority_queue<que> q;
int dij(int s, int t) {
	for (int i = 1; i <= n; i++)
		d[i] = INF, used[i] = 1;
	d[s] = 0;
	q.push(que(s, 0));
	while (!q.empty()) {
		while (!q.empty() && !used[q.top().id])
			q.pop();
		int minn = q.top().dis, num = q.top().id;
		if (num == t) break;
		used[num] = 0; q.pop();
		for (int i = fir[num]; i; i = nxt[i])
			if (l[i] + minn < d[to[i]]) {
				d[to[i]] = l[i] + minn;
				q.push(que(to[i], d[to[i]]));
			}
	}
	return d[t];
}

int main() {
	int u, v, w, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	printf("%d\n", dij(s, t));
	return 0;
}
