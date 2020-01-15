#include<bits/stdc++.h>
using namespace std;
#define MAXN	30005
#define MAXLOG	20
int depth[MAXN], father[MAXN][MAXLOG];
vector <int> a[MAXN];
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[x][i]] >= depth[y]) x = father[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	return father[x][0];
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
	work(1, 0);
	int m, last, ans = 0;
	scanf("%d%d", &m, &last);
	for (int i = 2; i <= m; i++) {
		int now;
		scanf("%d", &now);
		ans += depth[now] + depth[last] - 2 * depth[lca(now, last)];
		last = now;
	}
	printf("%d\n", ans);
	return 0;
}
