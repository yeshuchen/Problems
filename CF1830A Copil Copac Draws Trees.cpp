#include<bits/stdc++.h>
using namespace std;
int T, n, tot;
int x[200005], y[200005];
int ver[400005], val[400005], nxt[400005], head[400005];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int ans, dp[200005];
inline void dfs(int x, int fa, int Z)
{
	ans = max(ans, dp[x]);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y != fa)
		{
			if(z < Z) dp[y] = dp[x] + 1;
			else dp[y] = dp[x];
			dfs(y, x, z);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n; ans = 0;
		tot = 0;
		cin >> n;
		for(int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			add(x, y, i);
			add(y, x, i);
		}
		dp[1] = 1;
		dfs(1, 0, 0);
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) head[i] = 0;
	}
	return 0;
}