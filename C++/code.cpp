#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=998244353;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    unsigned long long c;
    while(b)
    {
        c=b;
        b=a%c;
        a=c;
    }
    return a;
}
struct fraction;
fraction operator+(fraction a,fraction b);
bool operator==(fraction a,fraction b);
fraction operator-(fraction a,fraction b);
struct fraction
{
    unsigned long long numerator,denominator;

    fraction(unsigned long long n=0,unsigned long long d=1)
    {
        numerator=n;
        denominator=d;
    }
    void reduct()
    {
        unsigned long long temp=gcd(numerator,denominator);
        numerator/=temp;
        denominator/=temp;
        return;
    }
    fraction reciprocal()
    {
        return fraction(denominator,numerator);
    }
    fraction operator+=(fraction x)
    {
        return (*this)=(*this)+x;
    }
    fraction operator-=(fraction x)
    {
        return (*this)=(*this)-x;
    }
};
fraction operator+(fraction a,fraction b)
{
    a.numerator*=b.denominator;
    b.numerator*=a.denominator;
    fraction c(a.numerator+b.numerator,a.denominator*b.denominator);
    c.reduct();
    return c;
}
bool operator==(fraction a,fraction b)
{
    a.reduct();
    b.reduct();
    return a.denominator==b.denominator&&a.numerator==b.numerator;
}
fraction operator-(fraction a,fraction b)
{
    a.numerator*=b.denominator;
    b.numerator*=a.denominator;
    fraction c(a.numerator-b.numerator,a.denominator*b.denominator);
    c.reduct();
    return c;
}
fraction f(vector<fraction> a)
{
    while(a.size()>1)
    {
        a[a.size()-2]+=a.back().reciprocal();
        a.pop_back();
    }
    return a.front();
}
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    unsigned long long n,q;
    cin>>n>>q;
    string oprt;
    cin>>oprt;
    vector<fraction> a={0,1};
    for(unsigned long long i=0;i<oprt.size();++i)
    {
        if(oprt[i]=='W')
            a.back()+=1;
        else if(a.back()==1)
            a[a.size()-2]+=1;
        else
        {
            a.back()-=1;
            a.push_back(1);
            a.push_back(1);
        }
    }
    fraction ans=f(a);
    cout<<ans.numerator%mod<<' '<<ans.denominator%mod<<'\n';
    while(q--)
    {
        string chg;
        cin>>chg;
        if(chg=="APPEND")
        {
            char c;
            cin>>c;
            oprt.push_back(c);
            if(c=='W')
                a.back()+=1;
            else if(a.back()==1)
                a[a.size()-2]+=1;
            else
            {
                a.back()-=1;
                a.push_back(1);
                a.push_back(1);
            }
            ans=f(a);
            cout<<ans.numerator%mod<<' '<<ans.denominator%mod<<'\n';
        }
        else
        {
            unsigned long long l,r;
            cin>>l>>r;
            --l;
            --r;
            if(chg=="FLIP")
                for(unsigned long long i=l;i<=r;++i)
                    oprt[i]=(oprt[i]=='W'?'E':'W');
            else
                for(unsigned long long i=0;l+i<r-i;++i)
                    swap(oprt[l+i],oprt[r-i]);
            a={0,1};
            for(unsigned long long i=0;i<oprt.size();++i)
            {
                if(oprt[i]=='W')
                    a.back()+=1;
                else if(a.back()==1)
                    a[a.size()-2]+=1;
                else
                {
                    a.back()-=1;
                    a.push_back(1);
                    a.push_back(1);
                }
            }
            ans=f(a);
            cout<<ans.numerator%mod<<' '<<ans.denominator%mod<<'\n';
        }
    }
    return 0;
}