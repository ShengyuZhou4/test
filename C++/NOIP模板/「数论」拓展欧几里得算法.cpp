#include<bits/stdc++.h>
using namespace std;
void exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	long long q = a / b, r = a % b;
	exgcd(b, r, y, x);
	y -= q * x;
}
int main() {
	long long a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	cout << x << ' ' << y << endl;
	return 0;
}
