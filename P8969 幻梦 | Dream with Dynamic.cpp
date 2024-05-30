#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int V = 50, N = 3e5 + 5;
int n, m, a[N];
int f[N << 2][V];
int ex[N << 2], tag[N << 2];
void build(int p = 1, int l = 1, int r = n)
{
	for(int i = 0; i < V; i++) f[p][i] = i;
	if(l == r) {ex[p] = 1; tag[p] = a[l]; return;}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}
void calc(int x)
{
	for(int i = 0; i < V; i++)
		f[x][i] = __builtin_popcountll(f[x][i] + tag[x]);
	tag[x] = 0;
}
void pushdown(int p)
{
	if(ex[p])
	{
		for(int i = 0; i < V; i++)
		{
			f[ls][i] = f[p][f[ls][i]];
			f[rs][i] = f[p][f[rs][i]];
		}
		for(int i = 0; i < V; i++) f[p][i] = i;
		ex[ls] = ex[rs] = 1; ex[p] = 0;
	}
	if(tag[p]) tag[ls] += tag[p], tag[rs] += tag[p], tag[p] = 0;
}
void upd(int p, int l, int r)
{
	if(ex[p]) return calc(p);
	pushdown(p);
	int mid = l + r >> 1;
	upd(ls, l, mid); upd(rs, mid + 1, r);
}
void modify(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R) {upd(p, l, r); ex[p] = 1; return;}
	int mid = l + r >> 1; pushdown(p);
	if(L <= mid) modify(ls, l, mid, L, R);
	if(R > mid) modify(rs, mid + 1, r, L, R);
}
void change(int p, int l, int r, int L, int R, int x)
{
	if(L <= l && r <= R) return tag[p] += x, void();
	int mid = l + r >> 1; pushdown(p);
	if(L <= mid) change(ls, l, mid, L, R, x);
	if(R > mid) change(rs, mid + 1, r, L, R, x);
}
int query(int p, int l, int r, int pos)
{
	int mid = l + r >> 1;
	if(l == r) return f[p][0] + tag[p];
	if(pos <= mid)
	{
		if(ex[p]) return f[p][query(ls, l, mid, pos)] + tag[p];
		else return query(ls, l, mid, pos) + tag[p];
	}
	else
	{
		if(ex[p]) return f[p][query(rs, mid + 1, r, pos)] + tag[p];
		else return query(rs, mid + 1, r, pos) + tag[p];
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build();
	for(int i = 1; i <= m; i++)
	{
		char opt;
		int l, r, x;
		cin >> opt;
		if(opt == 'A') cin >> l >> r >> x, change(1, 1, n, l, r, x);
		if(opt == 'P') cin >> l >> r, modify(1, 1, n, l, r);
		if(opt == 'J') cin >> x, cout << query(1, 1, n, x) << '\n';
	}
	return 0;
}