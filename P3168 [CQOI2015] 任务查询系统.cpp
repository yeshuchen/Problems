#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, res;
struct node {
	int l, r, opt;
} a[N];
int rt[N];
int tmp[N];
int ls[N << 5], rs[N << 5]; 
int cnt[N << 5], sum[N << 5];
vector<int> st[N], ed[N];
inline int build(int l, int r)
{
	int rt = ++res;
	if(l == r) return rt;
	int mid = l + r >> 1;
	ls[rt] = build(l, mid);
	rs[rt] = build(mid + 1, r);
	return res;
}
inline int change(int p, int l, int r, int x, int v)
{
	int nrt = ++res;
	cnt[nrt] = cnt[p] + v;
	sum[nrt] = sum[p] + v * tmp[x];
	if(l == r) return nrt;
	ls[nrt] = ls[p]; rs[nrt] = rs[p];
	int mid = l + r >> 1;
	if(x <= mid) ls[nrt] = change(ls[p], l, mid, x, v);
	else rs[nrt] = change(rs[p], mid + 1, r, x, v);
	return nrt;
}
inline int query(int p, int l, int r, int k)
{
	if(l == r) return min(k * tmp[l], sum[p]);
	int mid = l + r >> 1;
	if(cnt[ls[p]] < k) return sum[ls[p]] + query(rs[p], mid + 1, r, k - cnt[ls[p]]);
	else return query(ls[p], l, mid, k);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i].l >> a[i].r >> a[i].opt, tmp[i] = a[i].opt;
	sort(tmp + 1, tmp + n + 1);
	int len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for(int i = 1; i <= n; i++)
	{
		a[i].opt = lower_bound(tmp + 1, tmp + len + 1, a[i].opt) - tmp;
		st[a[i].l].push_back(a[i].opt);
		ed[a[i].r + 1].push_back(a[i].opt);
	}
	rt[0] = build(1, n);
	for(int i = 1; i <= m; i++)
	{
		rt[i] = rt[i - 1];
		for(int j = 0; j < st[i].size(); j++)
			rt[i] = change(rt[i], 1, n, st[i][j], 1);
		for(int j = 0; j < ed[i].size(); j++)
			rt[i] = change(rt[i], 1, n, ed[i][j], -1);
	}
	int lastans = 1;
	for(int i = 1; i <= m; i++)
	{
		int x, a, b, c;
		cin >> x >> a >> b >> c;
		int k = 1 + (a * lastans + b) % c;
		lastans = query(rt[x], 1, n, k);
		cout << lastans << '\n';
	}
	return 0;
}