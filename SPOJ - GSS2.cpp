#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 1e6 + 5;
struct node {
	int mx, hmx, t, tmx;
} a[N];
struct que {
	int l, r, id;
} t[N];
int n, q, c[N], Ans[N];
void pushup(int p)
{
	a[p].mx = max(a[ls].mx, a[rs].mx);
	a[p].hmx = max(a[ls].hmx, a[rs].hmx);
}
void pushdown(int p)
{
	if(a[p].tmx == -2e18) return;
	a[ls].hmx = max(a[ls].hmx, a[ls].mx + a[p].tmx);
	a[rs].hmx = max(a[rs].hmx, a[rs].mx + a[p].tmx);
	a[ls].mx += a[p].t;
	a[rs].mx += a[p].t;
	a[ls].tmx = max(a[ls].tmx, a[ls].t + a[p].tmx);
	a[rs].tmx = max(a[rs].tmx, a[rs].t + a[p].tmx);
	a[ls].t += a[p].t; a[rs].t += a[p].t;
	a[p].t = 0; a[p].tmx = -2e18;
}
void build(int p, int l, int r)
{
	a[p].tmx = -2e18;
	if(l == r)
	{
		cin >> c[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
void change(int p, int l, int r, int L, int R, int v)
{
	if(L <= l && r <= R)
	{
		a[p].mx += v;
		a[p].hmx = max(a[p].hmx, a[p].mx);
		a[p].t += v;
		a[p].tmx = max(a[p].tmx, a[p].t);
		return;
	}
	int mid = l + r >> 1; pushdown(p);
	if(L <= mid) change(ls, l, mid, L, R, v);
	if(R > mid) change(rs, mid + 1, r, L, R, v);
	pushup(p);
}
int query(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return a[p].hmx;
	int mid = l + r >> 1, val = LLONG_MIN; pushdown(p);
	if(L <= mid) val = max(val, query(ls, l, mid, L, R));
	if(R > mid) val = max(val, query(rs, mid + 1, r, L, R));
	return val;
}
map<int, int> pre;
bool cmp(que x, que y) {return x.r < y.r;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	build(1, 1, n);
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		t[i].id = i;
		cin >> t[i].l >> t[i].r;
	}
	sort(t + 1, t + q + 1, cmp);
	int posr = 0;
	for(int i = 1; i <= q; i++)
	{
		while(posr < t[i].r)
		{
			posr++;
			change(1, 1, n, pre[c[posr]] + 1, posr, c[posr]);
			pre[c[posr]] = posr;
		}
		Ans[t[i].id] = query(1, 1, n, t[i].l, t[i].r);
	}
	for(int i = 1; i <= q; i++) cout << Ans[i] << '\n';
	return 0;
} 