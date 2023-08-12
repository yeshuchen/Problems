#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 2147483647;
int n, m, len, res;
int a[N << 6], t[N << 6];
struct que {
	int a, b, c, d;
} q[N << 2];
int rt[N];
int s[N << 3], ls[N << 3], rs[N << 3];
inline void change(int &root, int l, int r, int d, int val)
{
	if(!root) root = ++res;
	if(l == r) {s[root] += val; return;}
	int mid = l + r >> 1;
	if(d <= mid) change(ls[root], l, mid, d, val);
	else change(rs[root], mid + 1, r, d, val);
	s[root] = s[ls[root]] + s[rs[root]];
}
inline void add(int x, int y)
{
	int pos = a[x];
	while(x <= n)
	{
		change(rt[x], 1, len, pos, y);
		x += (x & -x);
	}
}
int cntl, cntr;
int tl[N << 2], tr[N << 2];
inline int query_rnk(int l, int r, int k)
{
	int mid = l + r >> 1, sum = 0;
	if(l == r) return 0;
	if(k <= mid)
	{
		for(int i = 1; i <= cntl; i++) tl[i] = ls[tl[i]];
		for(int i = 1; i <= cntr; i++) tr[i] = ls[tr[i]];
		return query_rnk(l, mid, k);
	}
	else
	{
		for(int i = 1; i <= cntl; i++) sum -= s[ls[tl[i]]], tl[i] = rs[tl[i]];
		for(int i = 1; i <= cntr; i++) sum += s[ls[tr[i]]], tr[i] = rs[tr[i]];
		// cout << sum << ' ' << l << ' ' << r << '\n';
		return sum + query_rnk(mid + 1, r, k);
	}
}
inline int query_kth(int l, int r, int k)
{
	int mid = l + r >> 1, sum = 0;
	if(l == r) return l;
	for(int i = 1; i <= cntl; i++) sum -= s[ls[tl[i]]];
	for(int i = 1; i <= cntr; i++) sum += s[ls[tr[i]]];
	if(k <= sum)
	{
		for(int i = 1; i <= cntl; i++) tl[i] = ls[tl[i]];
		for(int i = 1; i <= cntr; i++) tr[i] = ls[tr[i]];
		return query_kth(l, mid, k);
	}
	else
	{
		for(int i = 1; i <= cntl; i++) tl[i] = rs[tl[i]];
		for(int i = 1; i <= cntr; i++) tr[i] = rs[tr[i]];
		return query_kth(mid + 1, r, k - sum);
	}
}
inline int find_rnk(int l, int r, int k)
{
	cntl = cntr = 0;
	// cout << l << ' ' << r << '\n';
	while(l) {tl[++cntl] = rt[l]; l -= (l & -l);}
	while(r) {tr[++cntr] = rt[r]; r -= (r & -r);}
	// for(int i = 1; i <= cntl; i++) cout << tl[i] << ' ';
	// cout << '\n';
	// for(int i = 1; i <= cntr; i++) cout << tr[i] << ' ';
	// cout << '\n';
	return query_rnk(1, len, k) + 1;
}
inline int find_kth(int l, int r, int k)
{
	cntl = cntr = 0;
	while(l) {tl[++cntl] = rt[l]; l -= (l & -l);}
	while(r) {tr[++cntr] = rt[r]; r -= (r & -r);}
	return query_kth(1, len, k);
}
inline int find_pre(int l, int r, int k)
{
	int rk = find_rnk(l - 1, r, k) - 1;
	// cout << k << ' ' << rk << '\n';
	// cout << rk << '\n';
	if(!rk) return 0;
	return find_kth(l - 1, r, rk);
}
inline int find_nxt(int l, int r, int k)
{
	if(k == len) return len + 1;
	int rk = find_rnk(l - 1, r, k + 1);
	if(rk == r - l + 2) return len + 1;
	return find_kth(l - 1, r, rk);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], t[++len] = a[i];
	for(int i = 1; i <= m; i++)
	{
		cin >> q[i].a >> q[i].b >> q[i].c;
		if(q[i].a != 3) cin >> q[i].d;
		else t[++len] = q[i].c;
		if(q[i].a == 4 || q[i].a == 5) t[++len] = q[i].d;
	}
	sort(t + 1, t + len + 1);
	len = unique(t + 1, t + len + 1) - t - 1;
	t[0] = -inf, t[len + 1] = inf;
	for(int i = 1; i <= n; i++) a[i] = lower_bound(t + 1, t + len + 1, a[i]) - t;
	for(int i = 1; i <= n; i++)
		add(i, 1);
	for(int i = 1; i <= m; i++)
	{
		if(q[i].a == 1)
		{
			q[i].d = lower_bound(t + 1, t + len + 1, q[i].d) - t;
			cout << find_rnk(q[i].b - 1, q[i].c, q[i].d) << '\n';
		}
		if(q[i].a == 2)
			cout << t[find_kth(q[i].b - 1, q[i].c, q[i].d)] << '\n';
		if(q[i].a == 3)
		{
			add(q[i].b, -1);
			a[q[i].b] = lower_bound(t + 1, t + len + 1, q[i].c) - t;
			add(q[i].b, 1);
		}
		if(q[i].a == 4)
		{
			q[i].d = lower_bound(t + 1, t + len + 1, q[i].d) - t;
			cout << t[find_pre(q[i].b, q[i].c, q[i].d)] << '\n';
		}
		if(q[i].a == 5)
		{
			q[i].d = lower_bound(t + 1, t + len + 1, q[i].d) - t;
			cout << t[find_nxt(q[i].b, q[i].c, q[i].d)] << '\n';
		}
	}
	return 0;
}