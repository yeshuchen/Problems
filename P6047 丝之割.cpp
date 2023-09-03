#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long
using namespace std;
const int N = 4e6 + 5;
int n, m, cnt, len;
int a[N], b[N];
struct node {
	int a, b;
} t[N], p[N];
int s[N], dp[N];
struct line {
	int k, b;
} ln[N];
inline bool cmp(node x, node y) {return (x.a == y.a ? x.b > y.b : x.a < y.a);}
inline bool cal(int u, int v, int x)
{
	int pu = ln[u].k * x + ln[u].b, pv = ln[v].k * x + ln[v].b;
	return pu < pv;
}
inline void update(int p, int l = 1, int r = 1e6, int u = len)
{
	int &v = s[p], mid = l + r >> 1;
	if(cal(u, v, mid)) swap(u, v);
	if(cal(u, v, l)) update(ls, l, mid, u);
	if(cal(u, v, r)) update(rs, mid + 1, r, u);
}
inline int query(int p, int l, int r, int x)
{
	int mid = l + r >> 1, res = ln[s[p]].k * x + ln[s[p]].b;
	if(l == r) return res;
	if(x <= mid) return min(res, query(ls, l, mid, x));
	else return min(res, query(rs, mid + 1, r, x));
}
signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= m; i++) cin >> t[i].a >> t[i].b;
	sort(t + 1, t + m + 1, cmp);
	for(int i = 1, mx = 0; i <= m; i++)
	{
		if(t[i].b <= mx) continue;
		p[++cnt] = t[i]; mx = max(mx, t[i].b);
	}
	a[0] = b[n + 1] = LLONG_MAX;
	for(int i = 1; i <= n; i++)
		a[i] = min(a[i], a[i - 1]);
	for(int i = n; i; i--)
		b[i] = min(b[i], b[i + 1]);
	ln[0] = {0, LLONG_MAX};
	ln[++len] = {a[p[1].a - 1], dp[0]};
	update(1);
	for(int i = 1; i <= cnt; i++)
	{
		dp[i] = query(1, 1, 1000000, b[p[i].b + 1]);
		ln[++len] = {a[p[i + 1].a - 1], dp[i]};
		update(1);
	}
	cout << dp[cnt];
	return 0;
}