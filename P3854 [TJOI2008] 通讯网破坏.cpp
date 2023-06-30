#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, q;
struct Edge {
	int tot, ver[N], nxt[N], head[N];
	inline void add(int x, int y)
	{
		ver[++tot] = y;
		nxt[tot] = head[x];
		head[x] = tot;
	}
} e, E;
int res, top, node;
int dfn[N], low[N], stk[N];
inline void tarjan(int x)
{
	dfn[x] = low[x] = ++res;
	stk[++top] = x;
	for(int i = e.head[x]; i; i = e.nxt[i])
	{
		int y = e.ver[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if(low[y] >= dfn[x])
			{
				node++; 
				while(stk[top + 1] != y)
				{
					E.add(stk[top], node);
					E.add(node, stk[top]);
					top--;
				}
				E.add(node, x);
				E.add(x, node);
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}
int f[200005][20], dep[N];
inline void DFS(int x, int fa)
{
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for(int i = 1; i < 19; i++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(int i = E.head[x]; i; i = E.nxt[i])
	{
		int y = E.ver[i];
		if(y == fa) continue;
		DFS(y, x);
	}
}
inline int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y];
	for(int i = 18; i >= 0; i--)
		if(tmp & (1 << i))
			x = f[x][i];
	if(x == y) return x;
	for(int i = 18; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];	
}
inline int ask(int x, int y)
{
	int lca = LCA(x, y);
	return dep[x] + dep[y] - 2 * dep[lca];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		e.add(x, y);
		e.add(y, x);
	}
	node = n;
	tarjan(1);
	DFS(1, 0);
	cin >> q;
	while(q--)
	{
		int s, t, d;
		cin >> s >> t >> d;
		if(ask(s, t) == ask(s, d) + ask(d, t)) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}