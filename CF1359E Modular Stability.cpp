#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353, N = 5e5 + 5;
int n, m;
int fac[N], inv[N];
int qpow(int a, int b)
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
int C(int x, int y)
{
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; int ans = 0;
	fac[0] = 1; inv[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod, inv[i] = qpow(fac[i], mod - 2);
	for(int i = 1; i <= n; i++)
	{
		if(n / i < m) break;
		ans += C(n / i - 1, m - 1);
		ans %= mod;
	}
	cout << ans;
	return 0;
}