#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, S, cnt, eps, len;
int t[N], f[N], dp[N], tmp[N];
struct line {
	int k, b;
} c[N];
int s[N << 2];
inline int cmp(int x, int y) {return x < y;}
inline int cal(int id, int x) {return c[id].k * (tmp[x] - eps) + c[id].b;}
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
	cin >> n >> S;
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> f[i], t[i] += t[i - 1], f[i] += f[i - 1], tmp[i] = t[i];
	sort(tmp + 1, tmp + n + 1);
	len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for(int i = 1; i <= n; i++) t[i] = lower_bound(tmp + 1, tmp + len + 1, t[i]) - tmp;
	c[0] = {0, LLONG_MAX};
	c[++cnt] = {0, 0};
	update(1, 1, len, cnt);
	for(int i = 1; i <= n; i++)
	{
		int j = query(1, 1, len, t[i]).id - 1;
		dp[i] = dp[j] + tmp[t[i]] * (f[i] - f[j]) + S * (f[n] - f[j]);
		c[++cnt] = {-f[i], dp[i] - S * f[i]};
		update(1, 1, len, cnt);
	}
	cout << dp[n];
	return 0;
}