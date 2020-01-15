#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
int x[MAXN], y[MAXN], f[MAXN], rk[MAXN];
long long z[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
bool cmp(int x, int y) {
	return z[x] < z[y];
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &x[i], &y[i], &z[i]);
		rk[i] = i;
	}
	sort(rk + 1, rk + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	long long ans = 0;
	for (int i = 1, j = rk[1]; i <= m; i++, j = rk[i])
		if (F(x[j]) != F(y[j])) {
			ans += z[j];
			f[F(x[j])] = F(y[j]);
		}
	cout << ans << endl;
	return 0;
}
