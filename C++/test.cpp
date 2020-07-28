#include<bits/stdc++.h>

using namespace std;

int read() {

    char c=getchar();while(c!='-'&&!isdigit(c)) c=getchar();

    int neg=0;if (c=='-') neg=1,c=getchar();

    int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();

    return neg?-num:num;

}

int head[200001], ver[5000001], nxt[5000001], sz;

void addedge(int u, int v) {

    ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;

}

int backup[200001], backupsz;

int cnt, rt;

int dfn[200001], low[200001], now;

int stk[200001], top;

int vis[200001], scc[200001], size[200001], num;

void tarjan(int x) {

    dfn[x] = low[x] = ++now;

    stk[++top] = x;

    vis[x] = 1;

    for (int i = head[x]; i; i = nxt[i])

        if (!vis[ver[i]]) tarjan(ver[i]), low[x] = min(low[x], low[ver[i]]);

        else if (vis[ver[i]] == 1) low[x] = min(low[x], dfn[ver[i]]);

    if (dfn[x] == low[x]) {

        ++num;

        while (stk[top] != x) {

            vis[stk[top]] = 2;

            scc[stk[top--]] = num;

        }

        vis[x] = 2, scc[x] = num, --top;

    }

}

vector<int> e1[200001], e2[200001];

int first[100001], maxlen;

int x[100001], l[100001], r[100001], last;

int single[200001], t1[200001], t2[200001];

int n, x0;

void link(int x0, int l0, int r0, int len) {

    if (l0 > r0) return;

    if (r0 - l0 + 1 < len) {

        link(x0, l0, r0, len >> 1);

        return;

    }

    int l1 = (l0-1)/len+1;

    if (len * (l1-1) + 1 == l0) addedge(x0, first[len] + l1), link(x0, len * l1 + 1, r0, len);

    else link(x0, l0, len * l1, len), link(x0, len * l1 + 1, r0, len);

    return;

}

long long check(int mid) {

    memcpy(backup, head, sizeof(backup));

    backupsz = sz;

    for (int i = last + 1; i <= mid; i++) link(x[i], l[i], r[i], maxlen);

    memset(vis, 0, sizeof(vis)), memset(size, 0, sizeof(size)), now = num = 0;

    for (int i = 1; i <= cnt; i++)

        if (!vis[i]) tarjan(i);

    for (int i = 1; i <= num; i++) single[i] = 0;

    for (int i = 1; i <= cnt; i++) e1[i].clear(), e2[i].clear();

    for (int i = 1; i <= n; i++) single[scc[i]] = 1, ++size[scc[i]];

    for (int i = 1; i <= cnt; i++)

        for (int j = head[i]; j; j = nxt[j]) {

            int u = scc[i], v = scc[ver[j]];

            if (u != v) e1[u].push_back(v), e2[v].push_back(u);

            if (i <= n && ver[j] <= n && u == v) single[u] = 0; 

        }

    memset(t1, 0, sizeof(t1)), memset(t2, 0, sizeof(t2));

    t1[scc[x0]] = t2[scc[x0]] = 1;

    int cnt1 = 0, cnt2 = 0, c1 = n, c2 = n;

    for (int i = 1; i <= num; i++)

        if (t2[i]) {

            c2 -= size[i];

            for (int j = 0; j < e2[i].size(); j++) t2[e2[i][j]] = 1;

        }

    for (int i = 1; i <= num; i++)

        if (single[i] || !size[i]) t2[i] = 0;

    for (int i = 1; i <= num; i++)

        if (t2[i]) {

            cnt2 += size[i];

            for (int j = 0; j < e2[i].size(); j++) t2[e2[i][j]] = 1;

        }

    for (int i = num; i >= 1; i--)

        if (t1[i]) {

            c1 -= size[i];

            for (int j = 0; j < e1[i].size(); j++) t1[e1[i][j]] = 1;

        }

    for (int i = num; i >= 1; i--)

        if (single[i] || !size[i]) t1[i] = 0;

    for (int i = num; i >= 1; i--)

        if (t1[i]) {

            cnt1 += size[i];

            for (int j = 0; j < e1[i].size(); j++) t1[e1[i][j]] = 1;

        }

    return 1ll * (n-cnt1) * (n-cnt2) + 1ll * cnt1 * c2 + 1ll * cnt2 * c1;

}

void reset() {

    memcpy(head, backup, sizeof(head));

    sz = backupsz;

}

int main() {

    int m, q;

    long long k;

    cin >> n >> m >> x0 >> q >> k;

    for (int i = 1; i <= m; i++) {

        int u, v;

        u = read(), v = read();

        addedge(u, v);

    }

    cnt = n, maxlen = 1;

    for (int i = 2; i <= n; i <<= 1) {

        first[i] = cnt, maxlen = i;

        for (int j = 1; j + i - 1 <= n; j += i) {

            ++cnt;

            for (int k = j; k < j + i; k++) addedge(cnt, k);

        }

    }

    for (int i = 1; i <= q; i++) x[i] = read(), l[i] = read(), r[i] = read();

    int l0 = 0, r0 = q + 1;

    while (l0 < r0) {

        int mid = (l0 + r0 + 1) / 2;

        if (check(mid - 1) >= k) l0 = mid, last = mid - 1;

        else r0 = mid - 1, reset();

    }

    cout << l0 << endl;

}

