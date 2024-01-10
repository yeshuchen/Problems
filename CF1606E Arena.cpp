#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m;
int f[505][505], c[505][505];
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	c[0][0] = 1;
	for(int i = 1; i <= 500; i++)
	{
		c[i - 1][0] = 1;
		for(int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j], c[i][j] %= mod;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(j < i) f[i][j] = ((qpow(j, i) - qpow(j - 1, i)) % mod + mod) % mod;
			else
			{
				for(int k = 1; k <= i; k++)
				{
					f[i][j] += f[k][j - i + 1] * c[i][k] % mod * qpow(i - 1, i - k) % mod;
					f[i][j] %= mod;
				}
			}
		}
	int ans = 0;
	for(int i = 1; i <= m; i++) ans = (ans + f[n][i]) % mod;
	cout << ans;
	return 0;
}