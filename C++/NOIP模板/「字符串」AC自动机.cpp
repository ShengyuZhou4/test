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
void insert(char *si) { //Trie���Ĺ��� 
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
        if(ch[0][i]) qi.push(ch[0][i]);//�Ȱѵ�һ��Ԥ������� 
    while(!qi.empty()) {
        int p = qi.front(); qi.pop();
        for(int i = 0; i < 26; i++) {
            if(ch[p][i]) {//���������Ӵ��� 
                fail[ch[p][i]] = ch[fail[p]][i];//���ӵ�failָ��ָ���׵� failָ����Ǹ����� 
                qi.push(ch[p][i]);//��� 
            }
            else ch[p][i] = ch[fail[p]][i];//����ͰѶ��Ӹĳ� failָ����Ǹ�����, ��·��ѹ�������� 
        }
    }
}
int solve() {
    int m = strlen(s + 1), now = 0, res = 0;
    for(int i = 1; i <= m; i++) {
        now = ch[now][s[i] - 'a'];//�������±��� 
        for(int j = now; j && num[j] != -1; j = fail[j])
            res += num[j], num[j] = -1;//�������� fail ָ�벻��������, �����м�¼, ֱ�������й���¼Ϊֹ 
    }
    return res;
}
int main() {
    //file("");
    read(n);
    for(int i = 1; i <= n; i++)
        cin >> (s + 1), insert(s);//����ģʽ�� 
    cin >> (s + 1); build();//���� AC�Զ��� 
    cout << solve() << endl;//���ģʽ�����ı�����һ�����ֹ����� 
    return 0;
}
//Copyright (C) 2020 MagicDuck

