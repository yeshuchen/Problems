#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e6 + 5;
int n, e, opt, tot;
int ver[N], nxt[N], head[N];
int c[N], d[N], id[N], take[N];
int s[N], p[N], q[N], l[N];
int top, pnt, f[N];
struct line {
	int k, b;
} t[N];
int ln[N], rn[N], rt[N];
bool cmp(int u, int v, int x) {return t[u].k * x + t[u].b < t[v].k * x + t[v].b;}
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void pre(int x)
{
	for(int i = head[x]; i; i = nxt[i])
		pre(ver[i]);
	id[x] = ++e;
}
inline void upd(int &p, int l, int r, int u)
{
	if(p)
	{
		int &v = take[p], mid = l + r >> 1;
		if(cmp(u, v, mid)) swap(u, v);
		if(cmp(u, v, l)) upd(ln[p], l, mid, u);
		if(cmp(u, v, r)) upd(rn[p], mid + 1, r, u);
	}
	else take[p = ++pnt] = u;
}
inline void update(int p, int l, int r, int pos, int cnt)
{
	upd(rt[p], 0, 1e6, cnt);
	if(l == r) return;
	int mid = l + r >> 1;
	if(pos <= mid) update(ls, l, mid, pos, cnt);
	else update(rs, mid + 1, r, pos, cnt);
}
inline int ask(int p, int l, int r, int pos)
{
	if(!p) return 1e18;
	int mid = l + r >> 1, res = t[take[p]].k * pos + t[take[p]].b;
	if(l == r) return res;
	if(pos <= mid) return min(res, ask(ln[p], l, mid, pos));
	else return min(res, ask(rn[p], mid + 1, r, pos));
}
inline int query(int p, int l, int r, int L, int R, int pos)
{
	if(L <= l && r <= R) return ask(rt[p], 0, 1e6, pos);
	int mid = l + r >> 1, res = LLONG_MAX;
	if(L <= mid) res = min(res, query(ls, l, mid, L, R, pos));
	if(R > mid) res = min(res, query(rs, mid + 1, r, L, R, pos));
	return res;
}
inline void dfs(int x)
{
	int L, R;
	t[x] = {-d[top], f[x]};
	L = id[R = c[top] = x];
	update(1, 1, n, L, R);
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i]; top++;
		d[top] = d[top - 1] + s[y];
		L = id[y]; R = id[c[lower_bound(d, d + top, d[top] - l[y]) - d]];
		f[y] = query(1, 1, n, L, R, p[y]) + d[top] * p[y] + q[y];
		dfs(y); top--;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> opt;
	for(int i = 2; i <= n; i++)
	{
		int father;
		cin >> father >> s[i] >> p[i] >> q[i] >> l[i];
		add(father, i);
	}
	pre(1); dfs(1); 
	for(int i = 2; i <= n; i++) cout << f[i] << '\n';
	return 0;
}