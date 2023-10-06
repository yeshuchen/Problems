#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, m, tot;
int rt[N], sz[N], dep[N];
int ver[N], nxt[N], head[N];
int s[N << 3], ls[N << 3], rs[N << 3];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int res, ans[N];
int p[N], k[N];
vector<int> v[N];
inline int merge(int x, int y)
{
	if(!x || !y) return x ^ y;
	s[x] += s[y];
	ls[x] = merge(ls[x], ls[y]);
	rs[x] = merge(rs[x], rs[y]);
	return x;
}
inline int change(int p, int l, int r, int pos, int v)
{
	s[p = ++res] = v;
	if(l == r) return p;
	int mid = l + r >> 1;
	if(pos <= mid) ls[p] = change(ls[p], l, mid, pos, v);
	else rs[p] = change(rs[p], mid + 1, r, pos, v);
	return p;
}
inline int query(int p, int l, int r, int L, int R)
{
	if(L > R || !p) return 0;
	if(L <= l && r <= R) return s[p];
	int mid = l + r >> 1, val = 0;
	if(L <= mid) val += query(ls[p], l, mid, L, R);
	if(R > mid) val += query(rs[p], mid + 1, r, L, R);
	return val;
}
inline void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1; sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x); sz[x] += sz[y];
	}
	rt[x] = change(rt[x], 1, n, dep[x], sz[x] - 1);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		rt[x] = merge(rt[x], rt[y]);
	}
	for(int i = 0; i < v[x].size(); i++)
		ans[v[x][i]] = query(rt[x], 1, n, dep[x] + 1, min(dep[x] + k[v[x][i]], n)) + min(dep[x] - 1, k[v[x][i]]) * (sz[x] - 1);
}
signed main()
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
	for(int i = 1; i <= m; i++)
	{
		cin >> p[i] >> k[i];
		v[p[i]].push_back(i);
	}
	dfs(1, 0);
	for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}