#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long
#define mk(x, y) make_pair(x, y)
using namespace std;
const int N = 8e5 + 5;
int n, m;
int a[N], f[N], mx[N], tag[N];
vector< pair<int, int> > v[N];
void pushdown(int p, int l, int r)
{
	tag[ls] += tag[p];
	tag[rs] += tag[p];
	mx[ls] += tag[p];
	mx[rs] += tag[p];
	tag[p] = 0;
}
void change(int p, int l, int r, int L, int R, int v)
{
	if(L <= l && r <= R)
	{
		mx[p] += v;
		tag[p] += v;
		return;
	}
	int mid = l + r >> 1; pushdown(p, l, r);
	if(L <= mid) change(ls, l, mid, L, R, v);
	if(R > mid) change(rs, mid + 1, r, L, R, v);
	mx[p] = max(mx[ls], mx[rs]);
}
int query(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return mx[p];
	int mid = l + r >> 1, val = 0;
	pushdown(p, l, r);
	if(L <= mid) val = max(val, query(ls, l, mid, L, R));
	if(R > mid) val = max(val, query(rs, mid + 1, r, L, R));
	return val;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; n++;
	for(int i = 2; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		int l, r, x;
		cin >> l >> r >> x;
		v[r + 1].push_back(mk(l + 1, x));
	}
	for(int i = 2; i <= n; i++)
	{
		change(1, 1, n, 1, i - 1, -a[i]);
		for(auto x : v[i])
			change(1, 1, n, 1, x.first - 1, x.second);
		f[i] = max(f[i - 1], query(1, 1, n, 1, i - 1));
		change(1, 1, n, i, i, f[i]);
	}
	cout << f[n];
	return 0;
}