#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, s;
int a[N], mx[N][20], mn[N][20];
inline int query(int l, int r)
{
	if(l > r) return 0;
	int k = log2(r - l + 1);
	return max(mx[l][k], mx[r - (1 << k) + 1][k]) - min(mn[l][k], mn[r - (1 << k)  + 1][k]);
}
int dp[N], q[N], t[N];
inline void update(int p, int l, int r, int d, int v)
{
	if(l == r)
	{
		t[p] = v;
		return;
	}
	int mid = l + r >> 1;
	if(d <= mid) update(ls, l, mid, d, v);
	else update(rs, mid + 1, r, d, v);
	t[p] = min(t[ls], t[rs]);
}
inline int ask(int p, int l, int r, int L, int R)
{
	if(L > R) return INT_MAX;
	if(L <= l && r <= R) return t[p];
	int mid = l + r >> 1, v = INT_MAX;
	if(L <= mid) v = min(v, ask(ls, l, mid, L, R));
	if(R > mid) v = min(v, ask(rs, mid + 1, r, L, R));
	return v;
}
signed main()
{
	cin >> n >> m >> s;
	if(s > n) {cout << -1; return 0;}
	for(int i = 1; i <= n; i++)
		cin >> a[i], mx[i][0] = mn[i][0] = a[i];
	for(int i = 1; i <= 19; i++)
		for(int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			mx[j][i] = max(mx[j][i - 1], mx[j + (1 << i - 1)][i - 1]);
			mn[j][i] = min(mn[j][i - 1], mn[j + (1 << i - 1)][i - 1]);
		}
	for(int i = 1; i <= n; i++) dp[i] = INT_MAX, update(1, 1, n, i, dp[i]);
	if(query(1, s) > m) {cout << -1; return 0;}
	for(int i = 1; i <= n; i++)
	{
		if(query(1, i) <= m) dp[i] = 1;
		else break;
		update(1, 1, n, i, 1);
	}
	for(int i = 1; i <= n; i++)
	{
		if(dp[i] != INT_MAX) continue;
		int l = 1, r = i, pos;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(query(mid, i) > m) l = mid + 1;
			else r = (pos = mid) - 1;
		}
		pos = r;
		if(pos <= i - s) dp[i] = ask(1, 1, n, pos, i - s) + 1;
		update(1, 1, n, i, dp[i]);
	}
	if(dp[n] >= INT_MAX) cout << -1;
	else cout << dp[n];
	return 0;
}