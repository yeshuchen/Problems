#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, tot;
int ver[N << 1], nxt[N << 1], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int ret;
int ls[N * 22], rs[N * 22];
int s[N * 22], dep[N], id[N * 22], rt[N];
inline void init(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		init(y, x);
	}
}
inline void insert(int &root, int d, int l = 1, int r = n)
{
	if(!root) root = ++ret;
	if(l == r) {s[root]++; id[root] = l; return;}
	int mid = l + r >> 1;
	if(d <= mid) insert(ls[root], d, l, mid);
	else insert(rs[root], d, mid + 1, r);
	if(s[ls[root]] >= s[rs[root]])
	{
		s[root] = s[ls[root]];
		id[root] = id[ls[root]];
	}
	else
	{
		s[root] = s[rs[root]];
		id[root] = id[rs[root]];
	}
}
inline int merge(int x,  int y, int l = 1, int r = n)
{
	if(!x || !y) return x ^ y;
	if(l == r)
	{
		s[x] += s[y];
		id[x] = l;
		return x;
	}
	int mid = l + r >> 1;
	ls[x] = merge(ls[x], ls[y], l, mid);
	rs[x] = merge(rs[x], rs[y], mid + 1, r);
	if(s[ls[x]] >= s[rs[x]]) s[x] = s[ls[x]], id[x] = id[ls[x]];
	else s[x] = s[rs[x]], id[x] = id[rs[x]];
	return x;
}
int ans[N];
inline void dfs(int x, int fa)
{
	insert(rt[x], dep[x]);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		rt[x] = merge(rt[x], rt[y]);
	}
	ans[x] = id[rt[x]] - dep[x];
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
	init(1, 0);
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}
