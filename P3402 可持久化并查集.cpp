#include<bits/stdc++.h>
using namespace std;
const int N = 8e5 + 5;
int n, m, res;
struct node {
	int sz, val, ls, rs;
} t[N << 5];
int rt[N];
void build(int &p, int l, int r)
{
	p = ++res;
	if(l == r)
	{
		t[p].sz = 1;
		t[p].val = l;
		return;
	}
	int mid = l + r >> 1;
	build(t[p].ls, l, mid);
	build(t[p].rs, mid + 1, r);
}
node query(int p, int l, int r, int pos)
{
	if(l == r) return t[p];
	int mid = l + r >> 1;
	if(pos <= mid) return query(t[p].ls, l, mid, pos);
	else return query(t[p].rs, mid + 1, r, pos);
}
node find(int k, int id)
{
	node fa = query(rt[id], 1, n, k);
	if(fa.val == k) return fa;
	else return find(fa.val, id);
}
int change(int p, int l, int r, int pos, int sz, int fat)
{
	int np = ++res;
	t[np] = t[p];
	if(l == r)
	{
		t[np].sz = sz;
		t[np].val = fat;
		return np;
	}
	int mid = l + r >> 1;
	if(pos <= mid) t[np].ls = change(t[p].ls, l, mid, pos, sz, fat);
	else t[np].rs = change(t[p].rs, mid + 1, r, pos, sz, fat);
	return np;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	build(rt[0], 1, n);
	for(int i = 1; i <= m; i++)
	{
		int opt, x, y;
		cin >> opt >> x;
		if(opt == 1)
		{
			cin >> y;
			rt[i] = rt[i - 1];
			node fx = find(x, i), fy = find(y, i);
			if(fx.sz < fy.sz) swap(fx, fy);
			rt[i] = change(rt[i], 1, n, fx.val, fx.sz + fy.sz, fx.val);
			rt[i] = change(rt[i], 1, n, fy.val, 0, fx.val);
		}
		if(opt == 2) rt[i] = rt[x];
		if(opt == 3)
		{
			cin >> y;
			rt[i] = rt[i - 1];
			cout << (find(x, i).val == find(y, i).val) << '\n';
		}
	}
	return 0;
}