#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline int power(int a, int b)
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
int fac[505];
inline int get(int x, int y)
{
	return fac[x] * power(fac[y] * fac[x - y] % mod, mod - 2) % mod;
}
int n, k;
int a[200005], sum[200005], p[505], f[505][505];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = 1;
	fac[0] = 1;
	for(int i = 1; i <= k; i++) fac[i] = fac[i - 1] * i % mod;
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= i; j++)
			f[i][j] = get(i, j);
	for(int i = 1; i <= n; i++)
	{
		int base = 1;
		for(int j = 0; j <= k; j++)
		{
			p[j] = (p[j] + base) % mod;
			base = base * a[i] % mod;
		}
	}
	for(int q = 1; q <= k; q++)
	{
		int res = 0, ans = 0;
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i] * 2 * a[i] % mod, res = (res + sum[i]) % mod;
		for(int i = q; i >= 0; i--)
			ans = (ans + f[q][q - i] * p[i] % mod * p[q - i]) % mod;	
		cout << ((ans - res) * power(2, mod - 2) % mod + mod) % mod << '\n';
	}
	return 0;
}