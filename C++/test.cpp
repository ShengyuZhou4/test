#include<bits/stdc++.h>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(1);
	q.push(2);
	cout<<q.top();
	return 0;
}