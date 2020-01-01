#include<bits/stdc++.h>
using namespace std;
#define MAXN	30005
int order[MAXN], lca[MAXN], depth[MAXN], f[MAXN];
bool visited[MAXN];
vector <int> a[MAXN], q[MAXN], num[MAXN];
int F(int x) {
	if (x == f[x]) return x;
	return f[x] = F(f[x]);
}
void tarjan(int x, int dep, int father) {
	visited[x] = true;
	depth[x] = dep;
	for (unsigned i = 0; i < a[x].size(); i++)
		if (!visited[a[x][i]]) tarjan(a[x][i], dep + 1, x);
	for (unsigned i = 0; i < q[x].size(); i++)
		if (visited[q[x][i]]) lca[num[x][i]] = F(q[x][i]);
	f[x] = father;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &order[i]);
	for (int i = 1; i < m; i++) {
		q[order[i]].push_back(order[i + 1]);
		num[order[i]].push_back(i);
		q[order[i + 1]].push_back(order[i]);
		num[order[i + 1]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	tarjan(1, 0, 0);
	int ans = 0;
	for (int i = 1; i < m; i++)
		ans += depth[order[i]] + depth[order[i + 1]] - 2 * depth[lca[i]];
	printf("%d\n", ans);
	return 0;
}
