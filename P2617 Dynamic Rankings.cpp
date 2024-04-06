#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m;
struct que {
	int op, x, y, val;
} q[N];
int r1, r2, res, num;
int a[N], tmp[N];
int v1[N], v2[N];
int s[N * 40], rt[N], ls[N * 40], rs[N * 40];
int change(int p, int l, int r, int d, int v)
{
	if(!p) p = ++num;
	s[p] += v;
	if(l == r) return p;
	int mid = l + r >> 1;
	if(d <= mid) ls[p] = change(ls[p], l, mid, d, v);
	else rs[p] = change(rs[p], mid + 1, r, d, v);
	return p;  
}
void add(int x, int pos, int v)
{
	for(int i = x; i <= n; i += (i & -i))
		rt[i] = change(rt[i], 1, res, pos, v);
}
int query(int l, int r, int K)
{
	if(l == r) return l;
	int mid = l + r >> 1, ret = 0;
	for(int i = 1; i <= r1; i++) ret -= s[ls[v1[i]]];
	for(int i = 1; i <= r2; i++) ret += s[ls[v2[i]]];
	if(K <= ret)
	{
		for(int i = 1; i <= r1; i++) v1[i] = ls[v1[i]];
		for(int i = 1; i <= r2; i++) v2[i] = ls[v2[i]];
		return query(l, mid, K);
	}
	else
	{
		for(int i = 1; i <= r1; i++) v1[i] = rs[v1[i]];
		for(int i = 1; i <= r2; i++) v2[i] = rs[v2[i]];
		return query(mid + 1, r, K - ret);
	}
}
int ask(int l, int r, int K)
{
	r1 = r2 = 0;
	for(int i = l; i; i -= (i & -i)) v1[++r1] = rt[i];
	for(int i = r; i; i -= (i & -i)) v2[++r2] = rt[i];
 	return query(1, res, K);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], tmp[++res] = a[i];
	for(int i = 1; i <= m; i++) 
	{
		char op;
		cin >> op;
		cin >> q[i].x >> q[i].y;
		if(op == 'Q') cin >> q[i].val, q[i].op = 1;
		else tmp[++res] = q[i].y;
	}
	sort(tmp + 1, tmp + res + 1);
	res = unique(tmp + 1, tmp + res + 1) - tmp - 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(tmp + 1, tmp + res + 1, a[i]) - tmp;
		add(i, a[i], 1);
	}
	for(int i = 1; i <= m; i++)
	{
		if(q[i].op) cout << tmp[ask(q[i].x - 1, q[i].y, q[i].val)] << '\n';
		else
		{
			q[i].y = lower_bound(tmp + 1, tmp + res + 1, q[i].y) - tmp;
			add(q[i].x, a[q[i].x], -1);
			a[q[i].x] = q[i].y;
			add(q[i].x, a[q[i].x], 1);
		}
	}
	return 0;
}