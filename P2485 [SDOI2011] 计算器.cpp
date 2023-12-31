#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, k;
int ksm(int a, int b, int mod)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
int x, y;
int exgcd(int a, int b)
{
	if(!b)
	{
		x = 1; y = 0;
		return a;
	}
	int g = exgcd(b, a % b);
	int z = x;
	x = y; y = z - a / b * y;
	return g;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T >> k;
	while(T--)
	{
		int a, b, p;
		cin >> a >> b >> p;
		if(k == 1) cout << ksm(a, b, p) << '\n';
		if(k == 2)
		{
			int g = exgcd(a, p), q = p / g;
			if(b % g) {cout << "Orz, I cannot find x!\n"; continue;}
			cout << (x * (b / g) % q + q) % q << '\n';
		}
		if(k == 3)
		{
			a %= p; b %= p;
			if(!a)
			{
				if(!b) cout << 1 << '\n';
				else if(b == 1) cout << 0 << '\n';
				else cout << "Orz, I cannot find x!\n";
				continue;
			}
			map<int, int> mp;
			int sz = sqrt(p), bs = 1;
			for(int i = 1; i <= sz; i++) bs = bs * a % p;
			for(int i = 0, base = 1; i < p; i += sz, base = base * bs % p)
				if(!mp[base]) mp[base] = i + sz;
			int ans = LLONG_MAX, t = a;
			for(int i = 0; i < sz; i++)
			{
				if(mp[b]) ans = min(ans, mp[b] - i - sz);
				b = b * t % p;
			}
			if(ans == LLONG_MAX) cout << "Orz, I cannot find x!\n";
			else cout << ans << '\n';
		}
	}
	return 0;
}