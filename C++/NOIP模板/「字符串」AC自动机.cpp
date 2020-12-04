#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T> inline void read(T &FF) {
    int RR = 1; FF = 0; char CH = getchar();
    for(; !isdigit(CH); CH = getchar()) if(CH == '-') RR = -RR;
    for(; isdigit(CH); CH = getchar()) FF = FF * 10 + CH - 48;
    FF *= RR;
}
inline void file(string str) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 1e6 + 10;
char s[N]; int n, ch[N][26], cnt, num[N], fail[N];
void insert(char *si) { //Trie树的构建 
    int m = strlen(si + 1), now = 0;
    for(int i = 1; i <= m; i++) {
        if(!ch[now][si[i] - 'a'])
            ch[now][si[i] - 'a'] = ++cnt;
        now = ch[now][si[i] - 'a'];
    }
    num[now]++;
}
void build() {
    queue<int> qi;
    for(int i = 0; i < 26; i++)
        if(ch[0][i]) qi.push(ch[0][i]);//先把第一层预处理出来 
    while(!qi.empty()) {
        int p = qi.front(); qi.pop();
        for(int i = 0; i < 26; i++) {
            if(ch[p][i]) {//如果这个儿子存在 
                fail[ch[p][i]] = ch[fail[p]][i];//儿子的fail指针指向父亲的 fail指针的那个儿子 
                qi.push(ch[p][i]);//入队 
            }
            else ch[p][i] = ch[fail[p]][i];//否则就把儿子改成 fail指针的那个儿子, 起到路径压缩的作用 
        }
    }
}
int solve() {
    int m = strlen(s + 1), now = 0, res = 0;
    for(int i = 1; i <= m; i++) {
        now = ch[now][s[i] - 'a'];//不断向下遍历 
        for(int j = now; j && num[j] != -1; j = fail[j])
            res += num[j], num[j] = -1;//从这个点的 fail 指针不断往上跳, 并进行记录, 直到起点或有过记录为止 
    }
    return res;
}
int main() {
    //file("");
    read(n);
    for(int i = 1; i <= n; i++)
        cin >> (s + 1), insert(s);//插入模式串 
    cin >> (s + 1); build();//构建 AC自动机 
    cout << solve() << endl;//输出模式串在文本串中一共出现过几次 
    return 0;
}
//Copyright (C) 2020 MagicDuck

