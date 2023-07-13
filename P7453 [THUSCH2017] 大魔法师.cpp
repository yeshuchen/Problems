#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int mod = 998244353;
struct matrix {
	int r, c;
	int a[5][5];
	inline void init() {memset(a, 0, sizeof(a));}
} d[10], t[1000005];
matrix operator * (const matrix &a, const matrix &b)
{
	matrix c;
	c.init();
	c.r = a.r; c.c = b.c;
	for(int i = 1; i <= c.r; i++)
		for(int j = 1; j <= c.c; j++)
			for(int k = 1; k <= a.c; k++)
				c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
	return c;
}
matrix operator + (const matrix &a, const matrix &b)
{
	matrix c;
	c.init();
	c.r = a.r; c.c = b.c;
	for(int i = 1; i <= c.c; i++)
		c.a[1][i] = (a.a[1][i] + b.a[1][i]) % mod;
	return c;
}
int n, m;
matrix tag[1000005];
inline void build(int p, int l, int r)
{
	t[p].r = 1; t[p].c = 4;
	t[p].init(); tag[p].init();
	tag[p].r = tag[p].c = 4;
	for(int i = 1; i <= 4; i++) tag[p].a[i][i] = 1;
	if(l == r)
	{
		cin >> t[p].a[1][1] >> t[p].a[1][2] >> t[p].a[1][3]; 
		t[p].a[1][4] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	t[p] = t[ls] + t[rs];
}
inline void pushdown(int p)
{
	t[ls] = t[ls] * tag[p];
	t[rs] = t[rs] * tag[p];
	tag[ls] = tag[ls] * tag[p];
	tag[rs] = tag[rs] * tag[p];
	tag[p].init();
	for(int i = 1; i <= 4; i++) tag[p].a[i][i] = 1;
}
inline void change(int p, int L, int R, int l, int r, int op)
{
	if(l <= L && R <= r)
	{
		t[p] = t[p] * d[op];
		tag[p] = tag[p] * d[op];
		return;
	}
	int mid = L + R >> 1;
	pushdown(p);
	if(l <= mid) change(ls, L, mid, l, r, op);
	if(r > mid) change(rs, mid + 1, R, l, r, op);
	t[p] = t[ls] + t[rs];
}
inline matrix ask(int p, int L, int R, int l, int r)
{
	if(l <= L && R <= r) return t[p];
	int mid = L + R >> 1;
	matrix val; val.init();
	val.r = 1; val.c = 4;
	pushdown(p);
	if(l <= mid) val = val + ask(ls, L, mid, l, r);
	if(r > mid) val = val + ask(rs, mid + 1, R, l, r);
	t[p] = t[ls] + t[rs];
	return val;
}
signed main()
{
	cin >> n;
	build(1, 1, n);
	cin >> m;
	for(int i = 1; i <= 6; i++)
	{
		d[i].init(); d[i].r = d[i].c = 4;
		for(int j = 1; j <= 4; j++)
			d[i].a[j][j] = 1;
	}
	d[1].a[2][1] = 1;
	d[2].a[3][2] = 1;
	d[3].a[1][3] = 1;
	d[6].a[3][3] = 0;
	for(int i = 1; i <= m; i++)
	{
		int op, l, r, v;
		cin >> op >> l >> r;
		if(op >= 4 && op <= 6)
		{
			cin >> v;
			if(op == 4) d[op].a[4][1] = v;
			if(op == 5) d[op].a[2][2] = v;
			if(op == 6) d[op].a[4][3] = v;
		}
		if(op < 7) change(1, 1, n, l, r, op);
		else
		{
			matrix ans = ask(1, 1, n, l, r);
			cout << ans.a[1][1] << ' ' << ans.a[1][2] << ' ' << ans.a[1][3] << '\n';
		}
	}
	return 0;
}