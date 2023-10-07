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
int res;
int f[N], sz[N], dep[N], son[N], dfn[N], top[N];
inline void dfs1(int x, int fa)
{
	f[x] = fa; dep[x] = dep[fa] + 1; sz[x] = 1;
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
		if(y == son[x] || y == f[x]) continue;
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
inline int dist(int x, int y) {return dep[x] + dep[y] - 2 * dep[LCA(x, y)];}
struct node {
	int x, y, len;
	node () {x = y = len = 0;}
	node (int _x, int _y)
	{
		x = _x; y = _y;
		len = dist(x, y);
	}
} tmp[7], t[N << 2];
inline node merge(node x, node y)
{
	if(!x.x) return y;
	if(!y.x) return x;
	tmp[1] = x; tmp[2] = y;
	tmp[3] = node(x.x, y.x); tmp[4] = node(x.x, y.y);
	tmp[5] = node(x.y, y.x); tmp[6] = node(x.y, y.y);
	node res;
	for(int i = 1; i <= 6; i++)
		if(res.len < tmp[i].len)
			res = tmp[i];
	return res;
}
inline void build(int p, int l, int r)
{
	if(l == r)
	{
		t[p].x = t[p].y = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	t[p] = merge(t[ls], t[rs]);
}
inline void change(int p, int l, int r, int pos)
{
	if(l == r)
	{
		t[p].x ^= l;
		t[p].y ^= l;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid) change(ls, l, mid, pos);
	else change(rs, mid + 1, r, pos);
	t[p] = merge(t[ls], t[rs]);
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
	cin >> m;
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	for(int i = 1; i <= m; i++)
	{
		char ch;
		cin >> ch;
		if(ch == 'G') cout << (!t[1].x ? -1 : t[1].len) << '\n';
		else
		{
			int x;
			cin >> x;
			change(1, 1, n, x);
		}
	}
	return 0;
}