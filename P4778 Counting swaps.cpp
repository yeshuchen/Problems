#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 9;
int T, n, res;
int p[N], t[N], vis[N], fac[N];
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
void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1; res++;
	dfs(p[x]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	fac[0] = 1;
	for(int i = 1; i <= 100000; i++) fac[i] = fac[i - 1] * i % mod;
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i], vis[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			res = 0;
			if(!vis[i])
			{
				dfs(i);
				t[++cnt] = res;
			}
		}
		// cout << cnt << '\n';
		int ans = 1;
		for(int i = 1; i <= cnt; i++)
			ans = ans * qpow(t[i], t[i] - 2) % mod;
		for(int i = 1; i <= n - cnt; i++) ans = ans * i % mod;
		for(int i = 1; i <= cnt; i++)
			ans = ans * qpow(fac[t[i] - 1], mod - 2) % mod;
		cout << ans << '\n';
	}
	return 0;
}