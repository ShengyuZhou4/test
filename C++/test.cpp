#include<bits/stdc++.h>
using namespace std;
int c[100005],e[1000005];
int main()
{
	int n;
	unsigned long long s=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>c[i];
	for (int i=1;i<=n;i++)
	cin>>e[i];
	for (int i=1;i<=n;i++)
	{
		s+=c[i]*e[i]*2006/10086;
		s=s%907282877488;
	}
	cout<<s<<endl;
	return 0;
}