#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, tot;
int ver[N], nxt[N], head[N];
void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int res;
int f[N], sz[N], dfn[N], son[N], top[N], dis[N], dep[N];
void dfs1(int x, int fa)
{
	f[x] = fa; sz[x] = 1;
	dep[x] = dep[fa] + 1;
	dis[x] = dis[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}
void dfs2(int x, int t)
{
	top[x] = t; dfn[x] = ++res;
	if(son[x]) dfs2(son[x], t);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == son[x] || y == f[x]) continue;
		dfs2(y, y);
	}
}
int LCA(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = f[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int dist(int x, int y) {return dep[x] + dep[y] - 2 * dep[LCA(x, y)];}
int op[N], in[N], X[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int sz = sqrt(m);
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dis[0] = -1;
	dfs1(1, 0);
	dfs2(1, 1);
	vector<int> v;
	for(int i = 1; i <= m; i++)
		cin >> op[i] >> X[i], in[i] = i / sz + 1;
	for(int i = 1; i <= m; i++)
	{
		if(in[i] != in[i - 1])
		{
			queue<int> q;
			for(int x : v) q.push(x), dis[x] = 0;
			v.clear();
			while(!q.empty())
			{
				int x = q.front(); q.pop();
				for(int i = head[x]; i; i = nxt[i])
				{
					int y = ver[i];
					if(dis[y] >= dis[x] + 1)
					{
						dis[y] = dis[x] + 1;
						q.push(y);
					}
				}
			}

		}
		if(op[i] == 1) v.push_back(X[i]);
		else
		{
			int ans = dis[X[i]];
			for(int Y : v)
				ans = min(ans, dist(X[i], Y));
			cout << ans << '\n';
		}
	}
	return 0;
}