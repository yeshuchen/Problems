#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
const int N = 2e5 + 5;
int tot;
int ver[N], nxt[N], head[N];
int f[5005][5005], s[5005];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int x, int fa)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		for(int j = 1; j <= m; j++)
		{
			if(!f[x][j]) continue;
			f[x][j] = 1ll * f[x][j] * ((s[y] - f[y][j]) % mod + mod) % mod;
			f[x][j] %= mod;
		}
	}
	for(int i = 1; i <= m; i++) s[x] += f[x][i], s[x] %= mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int k, x;
		cin >> k;
		for(int j = 1; j <= k; j++)
			cin >> x, f[i][x] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	int ans = 0;
	dfs(1, 0);
	for(int i = 1; i <= m; i++)
		ans += f[1][i], ans %= mod;
	cout << ans;
	return 0;
}