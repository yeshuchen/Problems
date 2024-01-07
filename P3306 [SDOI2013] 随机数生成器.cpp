#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
int T, p, a, b, x0, t;
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
int inv(int a, int mod) {return ksm(a, mod - 2, mod);}
int BSGS(int a, int b, int p)
{
	a %= p; b %= p;
	// cout << a << ' ' << b << '\n';
	int sz = sqrt(p) + 1, bs = 1;
	gp_hash_table<int, int> mp;
	for(int i = 1; i <= sz; i++) mp[b * (bs = bs * a % p) % p] = i;
	for(int i = 1, base = bs; i <= sz; i++, base = base * bs % p)
		if(mp.find(base) != mp.end()) return i * sz - mp[base];
	return -2;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;	
	while(T--)
	{
		cin >> p >> a >> b >> x0 >> t;
		if(x0 == t) {cout << 1 << '\n'; continue;}
		if(a == 0) {cout << (b == t ? 2 : -1) << '\n'; continue;}
		if(a == 1)
		{
			int g = __gcd(b, p); t = ((t - x0) % p + p) % p;
			if(t % g) {cout << -1 << '\n'; continue;}
			cout << (t * inv(b, p) % p) + 1 << '\n';
			continue;
		}
		if(b == 0) {cout << BSGS(a, t * inv(x0, p) % p + p, p) + 1 << '\n'; continue;}
		cout << BSGS(a, ((a - 1) * t + b) % p * inv(((a - 1) * x0 + b) % p, p) % p + p, p) + 1 << '\n';
	}
	return 0;
}
/*
7 2 2 2 0
*/