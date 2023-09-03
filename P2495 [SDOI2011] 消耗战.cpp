#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, k;
int f[250005][20];
struct Edge {
	int tot, ver[N], val[N], nxt[N], head[N];
	inline void add(int x, int y, int z)
	{
		ver[++tot] = y;
		val[tot] = z;
		nxt[tot] = head[x];
		head[x] = tot;
	}
} e, E;
int res, dfn[N], dep[N], minn[250005][20];
inline void dfs(int x, int fa)
{
	dfn[x] = ++res; f[x][0] = fa; dep[x] = dep[fa] + 1;
	for(int i = 1; i <= 17; i++) f[x][i] = f[f[x][i - 1]][i - 1], minn[x][i] = min(minn[f[x][i - 1]][i - 1], minn[x][i - 1]);
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i], z = e.val[i];
		if(y == fa) continue;
		minn[y][0] = z;
		dfs(y, x);
	}
}
int t[N], dp[N], tmp[N], vis[N];
inline bool cmp(int x, int y) {return dfn[x] < dfn[y];}
inline int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	int d = dep[x] - dep[y];
	for(int i = 17; i >= 0; i--)
		if(d & (1 << i))
			x = f[x][i];
	if(x == y) return x;
	for(int i = 17; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline void DFS(int x)
{
	dp[x] = 0;
	for(int i = E.head[x]; i; i = E.nxt[i])
	{
		int y = E.ver[i], z = E.val[i];
		DFS(y);
		if(vis[y]) dp[x] += z;
		else dp[x] += min(dp[y], z);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		e.add(x, y, z);
		e.add(y, x, z);
	}
	for(int i = 0; i <= 17; i++) minn[0][i] = minn[1][i] = LLONG_MAX;
	dfs(1, 0);
	cin >> m;
	t[1] = tmp[1] = 1;
	for(int i = 1; i <= m; i++)
	{
		cin >> k; k++; int res = 1;
		for(int j = 2; j <= k; j++)
			cin >> t[j], tmp[++res] = t[j], vis[t[j]] = 1;
		sort(t + 1, t + k + 1, cmp);
		for(int j = 2; j <= k; j++)
			tmp[++res] = LCA(t[j], t[j - 1]);
		sort(tmp + 1, tmp + res + 1, cmp);
		res = unique(tmp + 1, tmp + res + 1) - tmp - 1;
		for(int j = 2; j <= res; j++)
		{
			int lca = LCA(tmp[j], tmp[j - 1]);
			int x = tmp[j], mn = LLONG_MAX;
			for(int k = 17; k >= 0; k--)
				if(dep[f[x][k]] >= dep[lca])
					mn = min(mn, minn[x][k]), x = f[x][k];
			E.add(lca, tmp[j], mn);
			// cout << lca << ' ' << tmp[j] << ' ' << mn << '\n';
		}
		// for(int j = 1; j <= res; j++) cout << tmp[j] << ' ';
		// cout << '\n';

		DFS(1);
		cout << dp[1] << '\n';
		E.tot = 0;
		for(int j = 1; j <= res; j++)
			E.head[tmp[j]] = vis[tmp[j]] = 0;
	}
	for(int i = 1; i <= n; i++)
	return 0;
}