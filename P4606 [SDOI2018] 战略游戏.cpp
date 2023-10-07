#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int T, n, m, ret, TOP;
int low[N], dfn[N], stk[N];
struct Graph
{
	int tot;
	int ver[N], nxt[N], head[N];
	inline void init()
	{
		tot = 0;
		memset(head, 0, sizeof(head));
	}
	inline void add(int x, int y)
	{
		ver[++tot] = y;
		nxt[tot] = head[x];
		head[x] = tot;
	}
} E, e;
int cnt;
int f[N], sz[N], dep[N], dis[N], son[N], top[N];
inline void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(top, 0, sizeof(top));
}
inline void dfs1(int x, int fa)
{
	dfn[x] = ++ret;
	sz[x] = 1; dep[x] = dep[f[x] = fa] + 1;
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
		if(y == fa) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		if(sz[son[x]] < sz[y]) son[x] = y;
	}
}
inline void dfs2(int x, int t)
{
	top[x] = t;
	if(son[x]) dfs2(son[x], t);
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
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
inline void tarjan(int x, int fa)
{
	low[x] = dfn[x] = ++ret; stk[++TOP] = x;
	for(int i = E.head[x]; i; i = E.nxt[i])
	{
		int y = E.ver[i];
		if(!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if(low[y] >= dfn[x])
			{
				cnt++;
				e.add(cnt, x);
				e.add(x, cnt);
				while(stk[TOP + 1] != y)
				{
					e.add(stk[TOP], cnt);
					e.add(cnt, stk[TOP]);
					TOP--;
				}
			}
		}
		else if(y != fa) low[x] = min(low[x], dfn[y]);
	}
}
int a[N], tmp[N];
inline bool cmp(int x, int y) {return dfn[x] < dfn[y];}
inline void dfs3(int x, int fa)
{
	dis[x] = dis[fa] + (x <= n);
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
		if(y == fa) continue;
		dfs3(y, x);
	}
}
int main()
{
	cin >> T;
	while(T--)
	{
		e.init(); E.init();
		init();
		cin >> n >> m; ret = 0;
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			E.add(x, y);
			E.add(y, x);
		}
		cnt = n;
		tarjan(1, 1);
		for(int i = 1; i <= cnt; i++)
			dfn[i] = f[i] = son[i] = 0;
		ret = 0;
		dfs1(1, 0);
		dfs2(1, 1);
		dfs3(1, 0);
		int q, k;
		cin >> q;
		while(q--)
		{
			cin >> k;
			int len = 0;
			for(int i = 1; i <= k; i++)
				cin >> a[i];
			int res = -k;
			sort(a + 1, a + k + 1, cmp);
			for(int i = 1; i < k; i++)
			{
				tmp[++len] = a[i];
				tmp[++len] = LCA(a[i], a[i + 1]);
			}
			tmp[++len] = a[k];
			sort(tmp + 1, tmp + len + 1, cmp);
			len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
 			for(int i = 1; i < len; i++)
			{
				int lca = LCA(tmp[i], tmp[i + 1]);
				res += dis[f[tmp[i + 1]]] - dis[lca];
			}
			for(int i = 1; i <= len; i++) res += (tmp[i] <= n);
			cout << res << '\n'; 	
		}
	}
	return 0;
}