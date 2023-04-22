#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, q, tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int cnt;
int siz[N], dfn[N], ans[N];
inline void dfs(int x, int fa)	
{
	dfn[x] = ++cnt;
	siz[x] = 1; ans[x] = ans[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		siz[x] += siz[y];
	}
}
int c[N];
inline void Add(int x, int v)
{
	while(x <= n)
	{
		c[x] += v;
		x += (x & -x);
	}
}
inline int ask(int x)
{
	int res = 0;
	while(x)
	{
		res += c[x];
		x -= (x & -x);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	ans[0] = -1;
	dfs(1, 0);
	cin >> q;
	q = n + q - 1;
	while(q--)
	{
		char op;
		int x, y;
		cin >> op;
		if(op == 'W')
		{
			cin >> x;
			cout << ans[x] + ask(dfn[x]) << '\n';
		}
		else
		{
			cin >> x >> y;
			if(ans[x] > ans[y]) swap(x, y);
			Add(dfn[y], -1); Add(dfn[y] + siz[y], 1);
		}
	}
	return 0;
}