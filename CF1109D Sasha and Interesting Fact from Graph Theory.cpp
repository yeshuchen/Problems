#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, mod = 1e9 + 7;
int n, m, a, b;
int fac[N], inv[N];
int qpow(int a, int b)
{
	if(b < 0) return 1;
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
	if(x < y) return 0;
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	fac[0] = 1; inv[0] = 1;
	for(int i = 1; i <= max(n, m); i++) fac[i] = fac[i - 1] * i % mod, inv[i] = qpow(fac[i], mod - 2);
	int ans = 0;
	for(int i = 1; i <= min(n - 1, m); i++)
	{
		int res = C(m - 1, i - 1) * C(n - 2, i - 1) % mod * fac[i - 1] % mod;
		if(i != n - 1) res = res * (i + 1) % mod * qpow(n, n - i - 2) % mod * qpow(m, n - i - 1) % mod;
		ans += res;
		ans %= mod;
	}
	cout << ans;
	return 0;
}