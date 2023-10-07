#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, tot, res;
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int f[N], sz[N], rk[N], dis[N], dep[N], dfn[N], son[N], top[N];
inline void dfs1(int x, int fa)
{
	sz[x] = 1; dfn[x] = ++res; rk[dfn[x]] = x;
	f[x] = fa; dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dis[y] = dis[x] + val[i];
		dfs1(y, x); sz[x] += sz[y];
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
inline int lca(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = f[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
inline int dist(int x, int y) {return dis[x] + dis[y] - 2 * dis[lca(x, y)];}
set<int> s;
bool vis[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for(int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		if(vis[x]) s.erase(s.lower_bound(dfn[x]));
		if(s.empty())
		{
			if(!vis[x]) s.insert(dfn[x]), vis[x] = 1;
			cout << (res = 0) << '\n';
			continue;
		}
		auto it = s.lower_bound(dfn[x]);
		auto IT = it;
		if(it == s.end()) IT = s.begin(), it--;
		else if(it == s.begin()) IT = it, it = s.end(), it--;
		else IT = it, it--;
		if(vis[x]) res -= (dist(x, rk[*IT]) + dist(x, rk[*it]) - dist(rk[*IT], rk[*it]));
		else
		{
			res += (dist(x, rk[*IT]) + dist(x, rk[*it]) - dist(rk[*IT], rk[*it]));
			s.insert(dfn[x]);
		}
		cout << res << '\n';
		vis[x] ^= 1;
	}
	return 0;
}