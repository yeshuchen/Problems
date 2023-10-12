#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, tot;
int ver[N << 1], nxt[N << 1], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int cnt, scc[N];
int dfn[N], low[N], stk[N], res, top;
inline void tarjan(int x, int fa)
{
	dfn[x] = low[x] = ++res; stk[++top] = x;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
		else if(y != fa) low[x] = min(low[x], dfn[y]);
	}
	if(dfn[x] == low[x])
	{
		++cnt;
		while(stk[top + 1] != x)
		{
			scc[stk[top]] = cnt;
			--top;
		}
	}
}
int rt, dep[N];
vector<int> g[N];
inline void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	if(dep[x] > dep[rt]) rt = x;
	for(int y : g[x])
	{
		if(y == fa) continue;
		dfs(y, x);
	}
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
		add(x, y);
		add(y, x);
	}
	tarjan(1, 0);
	for(int i = 1; i <= n; i++)
		for(int j = head[i]; j; j = nxt[j])
			if(scc[i] != scc[ver[j]])
				g[scc[i]].push_back(scc[ver[j]]);
	dfs(1, 0);
	dfs(rt, 0);
	cout << dep[rt] - 1;
	return 0;
}