#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, m, t;
int a[305][305];
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
void add(int &x, int y) {x = ((x + y) % mod + mod) % mod;}
int det()
{
	bool flag = 0;
	for(int i = 2; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
			if(!a[i][i] && a[j][i]) {swap(a[j], a[i]); flag ^= 1; break;}
		int inv = ksm(a[i][i], mod - 2);
		for(int j = i + 1; j <= n; j++)
		{
			int d = 1ll * a[j][i] * inv % mod;
			for(int k = i; k <= n; k++)
				add(a[j][k], -1ll * d * a[i][k] % mod);
		}
	}
	int ans = 1;
	for(int i = 2; i <= n; i++) ans = 1ll * ans * a[i][i] % mod;
	return (flag ? mod - ans : ans);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(a[u][v], -w); add(a[v][v], w);		
		if(!t) add(a[v][u], -w), add(a[u][u], w);
	}
	cout << det();
	return 0;
}