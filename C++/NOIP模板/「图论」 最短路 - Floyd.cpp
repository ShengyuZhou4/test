#include <bits/stdc++.h>
#define INF INT_MAX
#define N 310
using namespace std;
int m, n, f[N][N];

int floyd(int s, int t) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (i != j && j != k && i != k && f[j][i] != INF && f[i][k] != INF)
					f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
	return f[s][t];
}

int main() {
	int u, v, w, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = INF;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		f[u][v] = f[v][u] = w;
	}
	printf("%d\n", floyd(s, t));
	return 0;
}
