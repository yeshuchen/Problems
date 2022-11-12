#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 1e6 + 5;
int n, m;
double s[N], st[N], tag[N];
inline void pushup(int p)
{
	s[p] = s[ls] + s[rs];
	st[p] = st[ls] + st[rs];
}
inline void pushdown(int p, int l, int r)
{
	int mid = l + r >> 1;
	st[ls] += (mid - l + 1) * tag[p] * tag[p] + 2 * s[ls] * tag[p];
	s[ls] += (mid - l + 1) * tag[p];
	st[rs] += (r - mid) * tag[p] * tag[p] + 2 * s[rs] * tag[p];
	s[rs] += (r - mid) * tag[p];
	tag[ls] += tag[p]; tag[rs] += tag[p];
	tag[p] = 0;
}
inline void build(int p, int l, int r)
{
	if(l == r)
	{
		cin >> s[p];
		st[p] = s[p] * s[p];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
inline void change(int p, int l, int r, int L, int R, double x)
{
	if(L <= l && r <= R)
	{
		st[p] += (r - l + 1) * x * x + 2 * s[p] * x;
		s[p] += (r - l + 1) * x;	
		tag[p] += x;
		return;
	}
	pushdown(p, l, r);
	int mid = l + r >> 1;
	if(L <= mid) change(ls, l, mid, L, R, x);
	if(R > mid) change(rs, mid + 1, r, L, R, x);
	pushup(p);
}
inline double askd(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return s[p];
	int mid = l + r >> 1; double val = 0;
	pushdown(p, l, r);
	if(L <= mid) val += askd(ls, l, mid, L, R);
	if(R > mid) val += askd(rs, mid + 1, r, L, R);
	return val;
}
inline double askf(int p, int l, int r, int L, int R, double jz)
{
	if(L <= l && r <= R) return st[p] - 2 * s[p] * jz + (r - l + 1) * jz * jz;
	int mid = l + r >> 1; double val = 0;
	pushdown(p, l, r);
	if(L <= mid) val += askf(ls, l, mid, L, R, jz);
	if(R > mid) val += askf(rs, mid + 1, r, L, R, jz);
	return val;
}
int main()
{
	cin >> n >> m;
	build(1, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1)
		{
			double x;
			cin >> x;
			change(1, 1, n, l, r, x);
		}
		if(op == 2)
			printf("%.4lf\n", askd(1, 1, n, l, r) / (r - l + 1));
		if(op == 3)
			printf("%.4lf\n", askf(1, 1, n, l, r, askd(1, 1, n, l, r) / (r - l + 1)) / (r - l + 1));
	}
	return 0;	
}