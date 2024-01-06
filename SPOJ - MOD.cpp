#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
int x, y;
int exgcd(int a, int b)
{
	if(a % b == 0) return x = 0, y = 1, b;
	int g = exgcd(b, a % b), z = x;
	x = y; y = z - a / b * x;
	return g;
}
int inv(int a, int mod)
{
	exgcd(a, mod);
	return (x % mod + mod) % mod;
}
int BSGS(int a, int b, int mod)
{
	gp_hash_table <int, int> mp;
	a %= mod; b %= mod;
	int sz = sqrt(mod) + 1, bs = 1, base = 1;
	for(int i = 1; i <= sz; i++) mp[b * (bs = bs * a % mod) % mod] = i;
	for(int i = 1; i <= sz; i++)
	{
		base = base * bs % mod;
		if(mp.find(base) != mp.end()) return i * sz - mp[base];
	}
	return -1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a, b, p;
	while(cin >> a >> p >> b)
	{
		if(!a && !b && !p) break;
		int v, cnt = 0, flag = 0, res = 1;
		while((v = exgcd(a, p)) > 1)
		{
			if(b == 1) {flag = 2; break;}
			if(b % v) {flag = 1; break;}
			p /= v; cnt++;
			b = b / v * inv(a / v, p) % p;
		}
		if(flag == 2) {cout << cnt << '\n'; continue;}
		int w = BSGS(a, b, p);
		if(w == -1 || flag) cout << "No Solution\n";
		else cout << w + cnt << '\n'; 
	}
	return 0;
}