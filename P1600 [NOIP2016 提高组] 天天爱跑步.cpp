#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int f[N], sz[N], dep[N], son[N], top[N];
inline void dfs1(int x, int fa)
{
	f[x] = fa; sz[x] = 1; dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}
inline void dfs2(int x, int t)
{
	top[x] = t;
	if(son[x]) dfs2(son[x], t);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == f[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}
inline int LCA(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = f[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int w[N], ans[N];
vector<int> gl[2][N];
vector<int> gr[2][N];
map<int, int> mp1[N], mp2[N];
inline void action(int x, int y, int t, int v)
{
	int flag = (v == 0 ? 1 : -1);
	gl[v][x].push_back(t + flag * dep[x]);
	gr[v][y].push_back(t + flag * (dep[x] - dep[y]));
}
inline void merge(int x, int y, map<int, int> *mp)
{
	if(mp[x].size() < mp[y].size()) swap(mp[x], mp[y]);
	for(auto [u, cnt] : mp[y])
		mp[x][u] += cnt;
}
inline void dfs(int x, int fa)
{
	for(int i : gl[0][x]) ++mp1[x][i];
	for(int i : gl[1][x]) ++mp2[x][i];
	for(int i : gr[0][x]) --mp1[x][i];
	for(int i : gr[1][x]) --mp2[x][i];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		merge(x, y, mp1);
		merge(x, y, mp2);
	}
	ans[x] = mp1[x][w[x] + dep[x]] + mp2[x][w[x] - dep[x]];
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	for(int i = 1; i <= n; i++) cin >> w[i];
	dfs1(1, 0); dfs2(1, 1);
	for(int i = 1; i <= m; i++)
	{
		int st, ed;
		cin >> st >> ed;
		int lca = LCA(st, ed);
		action(st, f[lca], 0, 0);
		action(ed, lca, dep[st] + dep[ed] - 2 * dep[lca], 1);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}