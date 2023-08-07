#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, res;
int a[N], t[N];
int ver[N << 1], nxt[N << 1], head[N];
inline void add(int x, int y)
{
	ver[++res] = y;
	nxt[res] = head[x];
	head[x] = res;
}
int rt[N];
int tot, len;
int f[N][25], dep[N];
int ls[N * 20], rs[N * 20], sum[N * 20];
inline int build(int l, int r)
{
	int root = ++tot;
	if(l == r) return root;
	int mid = l + r >> 1;
	ls[root] = build(l, mid);
	rs[root] = build(mid + 1, r);
	return root;
}
inline int update(int root, int k, int l, int r)
{
	int nrt = ++tot;
	ls[nrt] = ls[root]; rs[nrt] = rs[root]; sum[nrt] = sum[root] + 1;
	if(l == r) return nrt;
	int mid = l + r >> 1;
	if(k <= mid) ls[nrt] = update(ls[root], k, l, mid);
	else rs[nrt] = update(rs[root], k, mid + 1, r);
	return nrt;
}
inline void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	a[x] = lower_bound(t + 1, t + len + 1, a[x]) - t;
	f[x][0] = fa; rt[x] = update(rt[fa], a[x], 1, len);
	for(int i = 1; i < 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];	
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
	}
}
inline int LCA(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y];
	for(int i = 0; i < 20; i++)
		if(tmp & (1 << i))
			x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline int query(int r1, int r2, int r3, int r4, int l, int r, int k)
{
	if(l == r) return l;
	int mid = l + r >> 1, suml = sum[ls[r1]] + sum[ls[r2]] - sum[ls[r3]] - sum[ls[r4]];
	if(k > suml) return query(rs[r1], rs[r2], rs[r3], rs[r4], mid + 1, r, k - suml);
	else return query(ls[r1], ls[r2], ls[r3], ls[r4], l, mid, k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], t[i] = a[i];
	sort(t + 1, t + n + 1);
	len = unique(t + 1, t + n + 1) - t - 1;
	rt[0] = build(1, len);
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	int last = 0;
	for(int i = 1; i <= m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		x ^= last;
		int lca = LCA(x, y);
		cout << (last = t[query(rt[x], rt[y], rt[lca], rt[f[lca][0]], 1, len, k)]) << '\n';
	}
	return 0;
}