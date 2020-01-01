#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
char a[MAXN], b[MAXN];
int nxt[MAXN];
int main() {
	scanf("%s\n%s", a + 1, b + 1);
	int la = strlen(a + 1);
	int lb = strlen(b + 1);
	for (int i = 2; i <= lb; i++) {
		int p = nxt[i - 1];
		while (p && b[p + 1] != b[i])
			p = nxt[p];
		if (b[p + 1] == b[i]) p++;
		nxt[i] = p;
	}
	int pos = 0, ans = 0;
	for (int i = 1; i <= la; i++) {
		if (a[i] == b[pos + 1]) {
			pos++;
			if (pos == lb) {
				ans++;
				pos = nxt[lb];
			}
		} else {
			while (pos && b[pos + 1] != a[i])
				pos = nxt[pos];
			if (b[pos + 1] == a[i]) pos++;
		}
	}
	cout << ans << endl;
	return 0;
}
