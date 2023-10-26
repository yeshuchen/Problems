#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
map<int, int> mp;
int qpow(int a, int b, int mod)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = (__int128)base * a % mod;
		a = (__int128)a * a % mod;
		b >>= 1;
	}
	return base;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	n = (n * 9 + 1) % m;
	// cout << n << ' ';
	int sz = ceil(sqrt(m));
	int base = 1;
	for(int i = 0; i < sz; i++)
	{
		mp[base] = i;
		base = base * 10 % m;
	}
	for(int i = 0; i <= m; i += sz)
	{
		int x = (__int128)n * qpow(qpow(10, i, m), m - 2, m) % m;
		if(mp[x])
		{
			cout << i + mp[x];
			return 0;
		}
	}
	return 0;
}