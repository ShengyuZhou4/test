#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
#define P	1000000007
long long fac[MAXN], inv[MAXN];
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
long long getc(int x, int y) {
	return fac[x] * inv[y] % P * inv[x - y] % P;
}
int main() {
	int n = 1000000;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % P;
	int T; scanf("%d", &T);
	while (T--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", getc(x, y));
	}
	return 0;
}
