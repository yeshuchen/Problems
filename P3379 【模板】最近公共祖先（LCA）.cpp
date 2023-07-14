#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int res;
int top[N], dfn[N];
int f[N], sz[N], son[N], dep[N];
inline void dfs1(int x, int fa)
{
	f[x] = fa;
	sz[x] = 1;
	dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		if(sz[y] > sz[son[x]])
			son[x] = y;
	}
}
inline void dfs2(int x, int fa)
{
	top[x] = fa;
	dfn[x] = ++res;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == f[x]) continue;
		if(y == son[x]) dfs2(y, fa);
		else dfs2(y, y);
	}
}
inline int ask(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = f[top[x]];
	}
	if(dep[x] < dep[y]) return x;
	else return y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs1(k, 0);
	dfs2(k, k);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << ask(x, y) << '\n';
	}
	return 0;
}