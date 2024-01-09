#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e7 + 5, mod = 998244353;
int n, k, cnt;
int pr[N], vis[N];
int f[N], g[N];
int ksm(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = 1ll * base * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return base;
}
void sieve(int V = 2 * n)
{
	f[1] = 1; g[1] = 1;
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) pr[++cnt] = i, f[i] = i - 1, g[i] = ksm(i, k);
		for(int j = 1; j <= cnt && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1;
			f[i * pr[j]] = 1ll * f[i] * f[pr[j]] % mod;
			g[i * pr[j]] = 1ll * g[i] * g[pr[j]] % mod;
			if(i % pr[j] == 0)
			{
				if((i / pr[j]) % pr[j]) f[i * pr[j]] = (-1ll * f[i / pr[j]] * pr[j] % mod + mod) % mod;
				else f[i * pr[j]] = 0;
				break;
			}
		}
	}
	// for(int i = 1; i <= 6; i++) cout << f[i] << ' ' << 1ll * f[i] * g[i] % mod << '\n';
	for(int i = 1; i <= V; i++) f[i] = 1ll * f[i] * g[i] % mod, g[i] = (g[i] + g[i - 1]) % mod;
	for(int i = 1; i <= V; i++) g[i] = (g[i] + g[i - 1]) % mod;
	// for(int i = 1; i <= 6; i++) cout << f[i] << ' ';
}
int G(int x) {return g[2 * x] - 2 * g[x];}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	sieve(); int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = (ans + 1ll * f[i] * (G(n / i) % mod + mod) % mod) % mod;
	cout << ans;
	return 0;
}