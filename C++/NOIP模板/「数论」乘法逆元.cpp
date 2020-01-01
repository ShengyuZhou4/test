#include<bits/stdc++.h>
using namespace std;
#define MAXN	3000005
int n, p;
long long inv[MAXN];
int main() {
	scanf("%d%d", &n, &p);
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = (p - p / i) * inv[p % i] % p;
	for (int i = 1; i <= n; i++)
		printf("%lld\n", inv[i]);
	return 0;
}
