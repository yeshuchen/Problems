#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e6 + 5;
int n, q;
int a[N];
struct node {
	int hmx, mx;
	int vtag, adtag, t1, t2;
} tr[N];
void pushup(int p)
{
	tr[p].mx = max(tr[ls].mx, tr[rs].mx);
	tr[p].hmx = max(tr[ls].hmx, tr[rs].hmx);
}
void down(int p, int p2)
{
	tr[p2].hmx = max(tr[p2].hmx, max(tr[p2].mx + tr[p].t1, tr[p].t2));
	tr[p2].mx += tr[p].adtag;
	if(tr[p2].vtag != LLONG_MIN)
	{
		tr[p2].t2 = max(tr[p2].t2, tr[p2].vtag + tr[p].t1);
		tr[p2].vtag += tr[p].adtag;
		if(tr[p].vtag != LLONG_MIN) tr[p2].vtag = tr[p].vtag;
	}
	else
	{
		tr[p2].t1 = max(tr[p2].t1, tr[p2].adtag + tr[p].t1);
		tr[p2].adtag += tr[p].adtag;
		tr[p2].vtag = tr[p].vtag;
	}
	tr[p2].t2 = max(tr[p2].t2, tr[p].t2);
}
void pushdown(int p)
{
	down(p, ls); down(p, rs);
	if(tr[p].vtag != LLONG_MIN) tr[ls].mx = tr[rs].mx = tr[p].vtag;
	tr[p].t1 = tr[p].t2 = -2e18;
	tr[p].adtag = 0;
	tr[p].vtag = LLONG_MIN;
}
void build(int p, int l, int r)
{
	tr[p].vtag = LLONG_MIN;
	tr[p].t1 = tr[p].t2 = -2e18;
	if(l == r)
	{
		int x;
		cin >> x;
		tr[p].hmx = tr[p].mx = x;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
void change1(int p, int l, int r, int L, int R, int v)
{
	if(L <= l && r <= R)
	{
		tr[p].mx += v;
		if(tr[p].vtag != LLONG_MIN)
		{
			tr[p].vtag += v;
			tr[p].t2 = max(tr[p].t2, tr[p].vtag);
		}
		else
		{
			tr[p].adtag += v;
			tr[p].t1 = max(tr[p].t1, tr[p].adtag);
		}
		tr[p].hmx = max(tr[p].mx, tr[p].hmx);
		return;
	}
	int mid = l + r >> 1; pushdown(p);
	if(L <= mid) change1(ls, l, mid, L, R, v);
	if(R > mid) change1(rs, mid + 1, r, L, R, v);
	pushup(p);
}
void change2(int p, int l, int r, int L, int R, int v)
{
	if(L <= l && r <= R)
	{
		tr[p].mx = v;
		tr[p].vtag = v;
		tr[p].t2 = max(tr[p].t2, v);
		tr[p].hmx = max(tr[p].mx, tr[p].hmx);
		return;
	}
	int mid = l + r >> 1; pushdown(p);
	if(L <= mid) change2(ls, l, mid, L, R, v);
	if(R > mid) change2(rs, mid + 1, r, L, R, v);
	pushup(p);
}
int query(int p, int l, int r, int L, int R, int op)
{
	if(L <= l && r <= R) return !op ? tr[p].mx : tr[p].hmx;
	int mid = l + r >> 1, val = LLONG_MIN; pushdown(p);
	if(L <= mid) val = max(val, query(ls, l, mid, L, R, op));
	if(R > mid) val = max(val, query(rs, mid + 1, r, L, R, op));
	return val;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	build(1, 1, n);
	cin >> q;
	while(q--)
	{
		char op;
		int l, r, v;
		cin >> op >> l >> r;
		if(op == 'P')
		{
			cin >> v;
			change1(1, 1, n, l, r, v);
		}
		if(op == 'C')
		{
			cin >> v;
			change2(1, 1, n, l, r, v);
		}
		if(op == 'Q') cout << query(1, 1, n, l, r, 0) << '\n';
		if(op == 'A') cout << query(1, 1, n, l, r, 1) << '\n';
	}
	return 0;
}