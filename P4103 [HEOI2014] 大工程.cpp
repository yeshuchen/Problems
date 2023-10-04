// Problem: P4103 [HEOI2014] 大工程
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4103
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e6 + 5;
int n, res;
bool vis[N];
int f[N][4], g[N][4];
int father[N], dep[N], dfn[N], son[N], top[N];
struct Graph {
	int tot, sz[N];
	int ver[N], val[N], nxt[N], head[N];
	inline void add(int x, int y, int z)
	{
		ver[++tot] = y;
		val[tot] = z;
		nxt[tot] = head[x];
		head[x] = tot;
	}
}E, e;
inline void dfs1(int x, int fa)
{
	dfn[x] = ++res; e.sz[x] = 1;
	father[x] = fa; dep[x] = dep[fa] + 1;
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
		if(y == fa) continue;
		dfs1(y, x); e.sz[x] += e.sz[y];
		if(e.sz[y] > e.sz[son[x]]) son[x] = y;
	}
}
inline void dfs2(int x, int t)
{
	top[x] = t;
	if(son[x]) dfs2(son[x], t);
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
		if(y == father[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}
inline void dfs3(int x, int fa)
{
	for(int i = E.head[x]; i; i = E.nxt[i])
	{
		int y = E.ver[i], z = E.val[i];
		if(y == fa) continue;
		dfs3(y, x);
		f[x][0] += f[y][0];
		f[x][0] += E.sz[x] * (g[y][0] + z * E.sz[y]) + E.sz[y] * g[x][0];
		if(g[x][1]) f[x][1] = max(f[x][1], g[x][1] + g[y][1] + z);
		if(g[x][2])
		{
			if(!f[x][2]) f[x][2] = g[x][2] + g[y][2] + z;
			else f[x][2] = min(f[x][2], g[x][2] + g[y][2] + z);
		}
		E.sz[x] += E.sz[y];
		g[x][0] += g[y][0] + E.sz[y] * z;
		g[x][1] = max(g[y][1] + z, g[x][1]);
		if(!g[x][2]) g[x][2] = g[y][2] + z;
		else g[x][2] = min(g[y][2] + z, g[x][2]);
	}
	E.sz[x] += vis[x];
	if(vis[x])
	{
		f[x][0] += g[x][0];
		f[x][1] = max(f[x][1], g[x][1]);
		if(!f[x][2]) f[x][2] = g[x][2];
		else f[x][2] = min(f[x][2], g[x][2]);
		g[x][2] = 0;
	}
}
/*
g[x][0]: maxn
g[x][1]: minn
*/
inline int LCA(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = father[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
inline bool cmp(int x, int y) {return dfn[x] < dfn[y];}
int a[N], tmp[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		e.add(x, y, 1);
		e.add(y, x, 1);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	int q, k;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cin >> k; int len = 0;
		for(int j = 1; j <= k; j++)
			cin >> a[j], vis[a[j]] = 1;
		// for(int j = 1; j <= n; j++)
		// 	cout << vis[j] << ' ';
		// cout << '\n';
		sort(a + 1, a + k + 1, cmp);
		for(int j = 1; j < k; j++)
			tmp[++len] = a[j], tmp[++len] = LCA(a[j], a[j + 1]);
		tmp[++len] = a[k];
		sort(tmp + 1, tmp + len + 1, cmp);
		len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
		for(int j = 1; j < len; j++)
		{
			int lca = LCA(tmp[j], tmp[j + 1]);
			// cout << tmp[j] << ' ' << tmp[j + 1] << '\n';
			E.add(lca, tmp[j + 1],  dep[tmp[j + 1]] - dep[lca]);
			// cout << lca << '-' << tmp[j + 1] << '\n';
		}
		dfs3(tmp[1], 0);
		// for(int j = 1; j <= len; j++) cout << tmp[j] << ' ' << E.sz[tmp[j]] << '\n';
		int ans1 = f[tmp[1]][0], ans2 = 0, ans3 = INT_MAX;
		for(int j = 1; j < len; j++)
		{
			if(E.sz[tmp[j]] > 1 && f[tmp[j]][2])
				ans2 = max(ans2, f[tmp[j]][1]), ans3 = min(ans3, f[tmp[j]][2]);
		}
		cout << ans1 << ' ' << ans3 << ' ' << ans2 << '\n';
		E.tot = 0;
		for(int j = 1; j <= len; j++)
		{
			E.head[tmp[j]] = vis[tmp[j]] = E.sz[tmp[j]] = 0;
			f[tmp[j]][0] = f[tmp[j]][1] = f[tmp[j]][2] = 0;
			g[tmp[j]][0] = g[tmp[j]][1] = g[tmp[j]][2] = 0;
		}
	}
	return 0;
}