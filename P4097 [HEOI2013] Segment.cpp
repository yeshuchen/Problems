#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
int n, cnt;
const double eps = 1e-9;
const int mod1 = 39989, mod2 = 1e9 + 7, N = 2e5 + 5;
struct line {
	double k, b;
} p[N];
struct node {
	double x;
	int id;
};
inline void add(int x, int y, int xx, int yy)
{
	cnt++;
	if(x == xx) p[cnt].k = 0, p[cnt].b = max(y, yy);
	else
	{
		p[cnt].k = 1.0 * (yy - y) / (xx - x);
		p[cnt].b = (y - p[cnt].k * x);
	}
}
int s[N << 2];
inline double cal(int id, int x) {return p[id].k * x + p[id].b;}
inline int cmp(double x, double y)
{
	if(y - x > eps) return 1;
	if(x - y > eps) return -1;
	return 0;
}
inline void upd(int p, int l, int r, int id)
{
	int &v = s[p], mid = (l + r) >> 1;
	int flag = cmp(cal(v, mid), cal(id, mid));
	if(flag == 1 || (!flag && id < v)) swap(v, id);
	int L = cmp(cal(v, l), cal(id, l)), R = cmp(cal(v, r), cal(id, r));
	if(L == 1 || (!L && id < v)) upd(ls, l, mid, id);
	if(R == 1 || (!R && id < v)) upd(rs, mid + 1, r, id);
}
inline void update(int p, int l, int r, int L, int R, int id)
{
	if(L <= l && r <= R)
	{
		upd(p, l, r, id);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid) update(ls, l, mid, L, R, id);
	if(R > mid) update(rs, mid + 1, r, L, R, id);
}
node MAX(node a, node b)
{
	if(cmp(a.x, b.x) == 1) return b;
	if(cmp(a.x, b.x) == -1) return a;
	return a.id < b.id ? a : b;
}
node query(int p, int l, int r, int d)
{
	int mid = l + r >> 1;
	double res = cal(s[p], d);
	if(l == r) return {res, s[p]};
	if(d <= mid) return MAX({res, s[p]}, query(ls, l, mid, d));
	else return MAX({res, s[p]}, query(rs, mid + 1, r, d));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int last = 0;
	for(int i = 1; i <= n; i++)
	{
		int op, x1, y1, x2, y2, k;
		cin >> op;
		if(op == 1) 
		{
			cin >> x1 >> y1 >> x2 >> y2;
			x1 = (x1 + last - 1) % mod1 + 1;
			x2 = (x2 + last - 1) % mod1 + 1;
			y1 = (y1 + last - 1) % mod2 + 1;
			y2 = (y2 + last - 1) % mod2 + 1;
			if(x1 > x2) swap(x1, x2), swap(y1, y2);
			add(x1, y1, x2, y2);
			update(1, 1, mod1, x1, x2, cnt);
		}
		else
		{
			cin >> k;
			k = (k + last - 1) % mod1 + 1;
			cout << (last = query(1, 1, mod1, k).id) << '\n';
		}
	}
	return 0;
}