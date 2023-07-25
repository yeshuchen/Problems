#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 1e6 + 5;
int n, m, tot;
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
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
		if(sz[y] >= sz[son[x]]) son[x] = y;
	}
}
int res, rn[N], top[N], dfn[N];
inline void dfs2(int x, int t)
{
	top[x] = t;
	dfn[x] = ++res;
	rn[dfn[x]] = x;
	if(son[x]) dfs2(son[x], t);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == f[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}
int s[N << 2], tag[N << 2];
inline void pushdown(int p, int l, int r)
{
	int mid = l + r >> 1;
	s[ls] += tag[p] * (mid - l + 1);
	s[rs] += tag[p] * (r - mid);
	tag[ls] += tag[p];
	tag[rs] += tag[p];
	tag[p] = 0;
}
inline void change(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R)
	{
		s[p] += (r - l + 1);
		tag[p]++;
		return;
	}
	pushdown(p, l, r);
	int mid = l + r >> 1;
	if(L <= mid) change(ls, l, mid, L, R);
	if(R > mid) change(rs, mid + 1, r, L, R);
}
inline void cg(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		change(1, 1, n, dfn[top[x]], dfn[x]);
		x = f[top[x]];
	}
	if(x == y) return;
	if(dep[x] > dep[y]) swap(x, y);
	change(1, 1, n, dfn[x] + 1, dfn[y]);
}
inline int ask(int p, int l, int r, int d)
{
	if(l == r) {return s[p];}
	pushdown(p, l, r);
	int mid = l + r >> 1;
	if(d <= mid) return ask(ls, l, mid, d);
	else return ask(rs, mid + 1, r, d);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	// for(int i = 1; i <= n; i++) cout << dfn[i] << '\n';
	for(int i = 1; i <= m; i++)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;
		if(op == 'P') cg(x, y);
		else
		{
			if(f[x] != y) swap(x, y);
			cout << ask(1, 1, n, dfn[x]) << '\n';
		}
	}
	return 0;
}