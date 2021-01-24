#include<bits/stdc++.h>
using namespace std;
#define MAXN	3000005
int total, prime[MAXN], f[MAXN], phi[MAXN];
int main() {
	int n = 3000000;
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) {
			f[i] = i;
			prime[++total] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= total && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
			if (prime[j] == f[i]) phi[tmp] = phi[i] * prime[j];
			else phi[tmp] = phi[i] * (prime[j] - 1);
		}
	}
	for (scanf("%d", &n); n != 0; scanf("%d", &n))
		printf("%d\n", phi[n]);
	return 0;
}
