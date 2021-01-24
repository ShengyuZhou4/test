#include<bits/stdc++.h>
using namespace std;
const double delta=0.999,t_end=0.001;
long double ans,ans_e;
long double f(long double x)
{
	return 0.001*x*x*x*x-x*x+x;
}
void sa()
{
	srand(clock());
	long double t=100,x=ans;
	while(t>t_end)
	{
		long double x_temp=x+(rand()*2-RAND_MAX)*t;
		long double de=f(x)-f(x_temp);
		if(de>=0)
		{
			x=x_temp;
			if(f(x)<=ans_e)
			{
				ans_e=f(x);
				ans=x;
			}
		}
		else if(exp(de/t)*RAND_MAX>rand())
			x=x_temp;
		t*=delta;
	}
}
int main()
{
	int T=100;
	while(T--)
		sa();
	cout<<fixed<<ans<<' '<<ans_e<<'\n';
	return 0;
}
