#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, m, rt, cnt;
int ls[N], rs[N], sum[N], tag[N];
inline void change(int &root, int l, int r, int d, int w)
{
	if(!root) root = ++cnt;
	if(l == r)
	{
		sum[root] += w;
		tag[root] += w;
		return;
	}
	int mid = l + r >> 1;
	if(d <= mid) change(ls[root], l, mid, d, w);
	else change(rs[root], mid + 1, r, d, w);
	sum[root] = sum[ls[root]] + tag[ls[root]] * (r - mid) + sum[rs[root]];
	tag[root] = tag[ls[root]] + tag[rs[root]];
}
inline int query(int root, int l, int r, int L, int R)
{
	if(L <= l & r <= R) return tag[root] * (R - r) + sum[root];
	int mid = l + r >> 1, val = 0;
	if(L <= mid) val += query(ls[root], l, mid, L, R);
	if(R > mid) val += query(rs[root], mid + 1, r, L, R);
	return val;
}
signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x, w;
		cin >> x >> w;
		change(rt, 1, INT_MAX, x, w);
	}
	for(int i = 1; i <= m; i++)
	{
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 2) change(rt, 1, INT_MAX, l, r);
		else printf("%.4lf\n", 1.0 * (query(rt, 1, INT_MAX, 1, r) - query(rt, 1, INT_MAX, 1, l - 1)) / (r - l + 1));
	}
	return 0;
}