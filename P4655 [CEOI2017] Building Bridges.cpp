#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, cnt;
int f[N], h[N], w[N];
struct line {
	int k, b;
} c[N];
int s[N << 2];
inline int cmp(int x, int y) {return x < y;}
inline int cal(int id, int x) {return c[id].k * x + c[id].b;}
inline void update(int p, int l, int r, int id)
{
	int mid = l + r >> 1, &v = s[p];
	int flag = cmp(cal(id, mid), cal(v, mid));
	if(flag) swap(id, v);
	if(cmp(cal(id, l), cal(v, l))) update(ls, l, mid, id);
	if(cmp(cal(id, r), cal(v, r))) update(rs, mid + 1, r, id);
}
struct node {
	int minn, id;
};
node MIN(node a, node b)
{
	if(a.minn <= b.minn) return a;
	else return b;
}
inline node query(int p, int l, int r, int d)
{
	int mid = l + r >> 1, res = cal(s[p], d);
	if(l == r) return {res, s[p]};
	if(d <= mid) return MIN({res, s[p]}, query(ls, l, mid, d));
	else return MIN({res, s[p]}, query(rs, mid + 1, r, d));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i<= n; i++) cin >> h[i];
	for(int i = 1; i <= n; i++) cin >> w[i], f[1] += w[i];
	f[1] -= w[1];
	c[0] = {0, LONG_LONG_MAX};
	c[++cnt] = {-2 * h[1], f[1] + h[1] * h[1]};
	update(1, 1, N, cnt);
	for(int i = 2; i <= n; i++)
	{
		int j = query(1, 1, N, h[i]).id;
		f[i] = f[j] + (h[i] - h[j]) * (h[i] - h[j]) - w[i];
		c[++cnt] = {-2 * h[i], f[i] + h[i] * h[i]};
		update(1, 1, N, cnt);
	}
	cout << f[n];
	return 0;
}