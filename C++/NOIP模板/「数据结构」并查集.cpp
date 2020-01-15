#include<bits/stdc++.h>
using namespace std;
#define MAXN	4000005
#define P	998244353
int f[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 0; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int opt, x, y;
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 0) f[F(x)] = F(y);
		else ans = (ans * 2 + (F(x) == F(y))) % P;
	}
	printf("%d\n", ans);
	return 0;
}
