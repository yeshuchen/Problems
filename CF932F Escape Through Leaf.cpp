#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, tot, a[N], b[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int cnt, len, res;
int f[N], s[N], t[N];
struct line {
	int k, b;
} q[N];
int ls[N], rs[N], rt[N];
inline bool cmp(int u, int v, int x)
{
	int pu = q[u].k * t[x] + q[u].b, pv = q[v].k * t[x] + q[v].b;
	return pu < pv;
}
inline int query(int &p, int l, int r, int x, int u)
{
	if(!p) p = ++res, s[p] = u;
	int mid = l + r >> 1, res = q[s[p]].k * t[x] + q[s[p]].b;
	if(l == r) return res;
	if(x <= mid) return min(res, query(ls[p], l, mid, x, s[p]));
	else return min(res, query(rs[p], mid + 1, r, x, s[p])); 
}
inline void update(int &p, int l, int r, int u)
{
	if(!p) p = ++res, s[p] = u;
	int mid = l + r >> 1, &v = s[p];
	if(cmp(u, v, mid)) swap(u, v);
	if(cmp(u, v, l)) update(ls[p], l, mid, u);
	if(cmp(u, v, r)) update(rs[p], mid + 1, r, u);
}
inline int merge(int x, int y, int l, int r)
{
	if(!x || !y) return x ^ y;
	if(l == r) return x;
	update(x, l, r, s[y]);
	int mid = l + r >> 1;
	ls[x] = merge(ls[x], ls[y], l, mid);
	rs[x] = merge(rs[x], rs[y], mid + 1, r);
	return x;
}
inline void dfs(int x, int fa)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		rt[x] = merge(rt[x], rt[y], 1, len);
	}
	if(!rt[x]) f[x] = 0;
	else f[x] = query(rt[x], 1, len, a[x], s[rt[x]]);
	q[++cnt] = {b[x], f[x]};
	update(rt[x], 1, len, cnt);
	// cout << x << ' ' << f[x] << ' ' << rt[x] << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], t[++len] = a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	q[0] = {0, INT_MAX};
	sort(t + 1, t + len + 1);
	len = unique(t + 1, t + len + 1) - t - 1;
	for(int i = 1; i <= n; i++) a[i] = lower_bound(t + 1, t + len + 1, a[i]) - t;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	// for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	// cout << '\n';
	dfs(1, 0);
	for(int i = 1; i <= n; i++) cout << f[i] << ' ';
	return 0;
}