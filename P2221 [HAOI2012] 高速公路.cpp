#include<bits/stdc++.h>
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 1e5 + 5;

ll n, m;
struct node {
	ll s1, s2, s3, s4, tag, len;
	node () {s1 = s2 = s3 = s4 = tag = len = 0;}
	node operator + (const node &oth) const {
		node c;
		c.s4 = s4 + oth.s4;
		c.s2 = oth.s2 + oth.s4 * len + s2;
		c.s3 = s3 + s4 * oth.len + oth.s3;
		c.s1 = s1 + oth.s1 + s2 * oth.len + oth.s3 * len;
		c.len = oth.len + len;
		return c;
	}
} a[N << 2];
ll s[N];
void build(int p, int l, int r)
{
	a[p].len = (r - l + 1);
	if(l == r) return;
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}
void upd(int p, ll len, int val)
{
	a[p].s1 += (len * (len + 1) * (len + 1) / 2 - s[len]) * val;
	a[p].s2 += len * (len + 1) / 2 * val;
	a[p].s3 += len * (len + 1) / 2 * val;
	a[p].s4 += len * val;
	a[p].tag += val;
}
void pushdown(int p)
{
	if(!a[p].tag) return;
	upd(ls, a[ls].len, a[p].tag);
	upd(rs, a[rs].len, a[p].tag);
	a[p].tag = 0;
}
void change(int p, int l, int r, int L, int R, int val)
{
	if(L <= l && r <= R)
	{
		upd(p, a[p].len, val);
		return;
	}
	pushdown(p); int mid = l + r >> 1;
	if(L <= mid) change(ls, l, mid, L, R, val);
	if(R > mid) change(rs, mid + 1, r, L, R, val);
	a[p] = a[ls] + a[rs];
}
node query(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return a[p];
	node res; pushdown(p);
	int mid = l + r >> 1;
	if(L <= mid) res = res + query(ls, l, mid, L, R);
	if(R > mid) res = res + query(rs, mid + 1, r, L, R);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; n--;
	build(1, 1, n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + i * i;
	for(int i = 1; i <= m; i++)
	{
		char opt; int l, r, val;
		cin >> opt >> l >> r;
		if(opt == 'C')
		{
			cin >> val;
			if(l < r) change(1, 1, n, l, r - 1, val);
		}
		else
		{
			if(l == r) {cout << "0/1" << '\n'; continue;}
			ll ans = query(1, 1, n, l, r - 1).s1, cc = 1ll * (r - l) * (r - l + 1) / 2;
			ll g = __gcd(ans, cc);
			cout << ans / g << '/' << cc / g << '\n';
		}
	}
	return 0;
}