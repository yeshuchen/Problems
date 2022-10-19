#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, c, k;
ll x, y;
inline ll exgcd(ll a, ll b)
{
	if(a % b == 0)
	{
		x = 0; y = 1;
		return b;
	}
	ll gcd = exgcd(b, a % b);
	ll z = x; x = y; y = z - a / b * y;
	return gcd;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> a >> b >> c >> k)
	{
		if(!a && !b && !c && !k) break;
		ll base = 1;
		for(int i = 1; i <= k; i++) base *= 2;
		ll p = b - a;
		ll gcd = exgcd(c, base);
		if(p % gcd != 0)
		{
			cout << "FOREVER\n";
			continue;
		}
		base /= gcd;
		if(base < 0) base = -base; 
		cout << (x * (p / gcd) % base + base) % base << '\n';
	}
	return 0;
}