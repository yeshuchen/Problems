#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a == 0 && c == 0) {cout << 0 << '\n'; continue;}
		else if(a == 0 || c == 0) {cout << 1 << '\n'; continue;}
		ll gcd = __gcd(a, b);
		a /= gcd; b /= gcd;
		gcd = __gcd(c, d);
		c /= gcd; d /= gcd;
		if(a == c && b == d)
		{
			cout << 0 << '\n';
			continue;
		}
		if(b % d == 0) c *= (b / d), d *= (b / d);
		if(d % b == 0) a *= (d / b), b *= (d / b);
		if(b == d && (a % c == 0 || c % a == 0)) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}