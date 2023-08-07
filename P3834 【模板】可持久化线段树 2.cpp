#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, tot, root;
int a[N], t[N], rt[N];
int ls[N << 5], rs[N << 5], sum[N << 5]; 
inline int build(int l, int r)
{
	int root = ++tot;
	if(l == r) return tot;
	int mid = l + r >> 1;
	ls[root] = build(l, mid);
	rs[root] = build(mid + 1, r);
	return root;
}
inline int update(int root, int k, int l, int r)
{
	int new_root = ++tot;
	ls[new_root] = ls[root]; rs[new_root] = rs[root]; sum[new_root] = sum[root] + 1;
	if(l == r) return new_root;
	int mid = l + r >> 1;
	if(k <= mid) ls[new_root] = update(ls[root], k, l, mid);
	else rs[new_root] = update(rs[root], k, mid + 1, r);
	return new_root;
}
inline int query(int rtr, int rtl, int l, int r, int k)
{
	if(l == r) return l;
	int mid = l + r >> 1;
	int suml = sum[ls[rtr]] - sum[ls[rtl]];
	if(k > suml) return query(rs[rtr], rs[rtl], mid + 1, r, k - suml);
	else return query(ls[rtr], ls[rtl], l, mid, k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], t[i] = a[i];
	sort(t + 1, t + n + 1);
	int len = unique(t + 1, t + n + 1) - t - 1;
	rt[0] = build(1, n);
	for(int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(t + 1, t + len + 1, a[i]) - t;
		rt[i] = update(rt[i - 1], a[i], 1, len);
	}
	for(int i = 1; i <= m; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << t[query(rt[r], rt[l - 1], 1, len, k)] << '\n';
	}
	return 0;
}