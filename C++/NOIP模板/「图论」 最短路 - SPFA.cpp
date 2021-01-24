#include<bits/stdc++.h>
using namespace std;
const int MAXN = 310;
const int MAXM = 2010;
int n, m, tot = 0, h[MAXN], d[MAXN], in[MAXN];

struct edge {
	int to, ne, co;
}e[MAXM];

void add(int x, int y, int z) {
	e[++tot].to = y; e[tot].ne = h[x]; e[tot].co = z; h[x] = tot;
	e[++tot].to = x; e[tot].ne = h[y]; e[tot].co = z; h[y] = tot;
}

deque<int> q;
long long sum = 0;

int dij(int s, int t) {
	int u;
	memset(in, 0, sizeof(in));
	for(int i = 1; i <= n; i++)
		d[i] = INT_MAX, sum += (long long)d[i];
	in[s] = 1; sum -= (long long)d[s];
	d[s] = 0; sum += (long long)d[s];
	q.push_back(s);
	while (!q.empty()) {
		u = q.front();
		q.pop_front();
		while (d[u]*n > sum) {
			q.push_back(u); u = q.front();
			q.pop_front();
		}
		in[u] = 0;
		for(int i = h[u]; i; i = e[i].ne)
			if (d[u] + e[i].co < d[e[i].to]) {
				sum += d[e[i].to];
				d[e[i].to] = d[u] + e[i].co;
				sum -= d[e[i].to];
				if (!in[e[i].to]) {
					in[e[i].to] = 1;
					if (d[e[i].to] < d[q.front()])
						q.push_front(e[i].to);
					else
						q.push_back(e[i].to);
				}
			}
	}
	return d[t];
}
int main() {
	int s, t, u, v, w;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	printf("%d\n", dij(s, t));
	return 0;
} 
