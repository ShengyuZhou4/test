#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 400000;
bool s[N+1][256];
ull myRand(ull &k1, ull &k2)
{
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
void gen(int n, ull a1, ull a2)
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 256; j++)
            s[i][j] = (myRand(a1, a2) & (1ull << 32)) ? 1 : 0;
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ull n,m,a1,a2;
    cin>>n>>m>>a1>>a2;
    gen(n,a1,a2);
    bitset<256> ss[N+1];
    for(ull i=1;i<=n;++i)
        for(ull j=0;j<256;++j)
            ss[i][255-j]=s[i][j];
    bool lastans=false;
    map<char,ull> c;
    c['0']=0;
    c['1']=1;
    c['2']=2;
    c['3']=3;
    c['4']=4;
    c['5']=5;
    c['6']=6;
    c['7']=7;
    c['8']=8;
    c['9']=9;
    c['A']=10;
    c['B']=11;
    c['C']=12;
    c['D']=13;
    c['E']=14;
    c['F']=15;
    bitset<256> tt,re(string(256,'1'));
    for(ull k,i=1;i<=m;++i)
    {
        char ch;
        for(ull j=0;j<64;++j)
        {
            cin>>ch;
            tt[255-4*j]=(c[ch]>>3)&1;
            tt[255-4*j-1]=(c[ch]>>2)&1;
            tt[255-4*j-2]=(c[ch]>>1)&1;
            tt[255-4*j-3]=(c[ch]>>0)&1;
        }
        cin>>k;
        if(lastans)
            tt^=re;
        lastans=false;
        for(ull j=1;j<=n;++j)
            if((ss[j]^tt).count()<=k)
            {
                lastans=true;
                break;
            }
        cout<<lastans<<'\n';
    }
    return 0;
}