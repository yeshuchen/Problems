#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 5;
int n, len;
int c[2][N];
int op[N], k[N], x[N], y[N], w[N], t[N];
inline void add(int kind, int pos, int val) {
	for(int i = pos; i <= len; i += (i & -i))
		c[kind][i] += val;
}
inline int query(int kind, int x)
{
	int res = 0;
	while(x)
	{
		res += c[kind][x];
		x -= (x & -x);
	}
	return res;
}
inline void solve()
{
	int p1 = 0, p2, ans = 0, sum_fire = query(1, len), sum_ice = 0;
	for(int i = 20; i >= 0; i--)
	{
		if(p1 + (1 << i) > len) continue;
		if(sum_ice + c[0][p1 + (1 << i)] <= sum_fire - c[1][p1 + (1 << i)] + w[p1 + (1 << i)])
		{
			p1 += (1 << i);
			sum_ice += c[0][p1];
			sum_fire -= c[1][p1];
		}
	}
	bool f = 0;
	if(min(sum_ice, sum_fire + c[1][p1]) == 0) f = 1;
	ans = 2 * min(sum_ice, sum_fire + c[1][p1]);
	int val = sum_fire; p2 = 0; sum_fire = query(1, len); sum_ice = 0;
	for(int i = 20; i >= 0; i--)
	{
		if(p2 + (1 << i) > len) continue;
		if(sum_fire - c[1][p2 + (1 << i)] + w[p2 + (1 << i)] >= val)
			p2 = p2 + (1 << i), sum_fire -= c[1][p2], sum_ice += c[1][p2];
	}
	if(f && min(sum_ice, sum_fire + c[1][p2]) == 0) {cout << "Peace\n"; return;}
	if(2 * val >= ans) ans = 2 * val, p1 = p2;
	cout << t[p1] << ' ' << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> op[i] >> k[i];
		if(op[i] == 1) {
			cin >> x[i] >> y[i];
			t[++len] = x[i];
		}
	}
	sort(t + 1, t + len + 1);
	len = unique(t + 1, t + len + 1) - t - 1;
	for(int i = 1; i <= n; i++)
		if(op[i] == 1)
		{
			x[i] = lower_bound(t + 1, t + len + 1, x[i]) - t;
		}
	for(int i = 1; i <= n; i++)
	{
		if(op[i] == 1) {
			if(k[i] == 1) w[x[i]] += y[i];
			add(k[i], x[i], y[i]);
		}
		else
		{
			if(k[k[i]] == 1) w[x[k[i]]] -= y[k[i]];
			add(k[k[i]], x[k[i]], -y[k[i]]);
		}
		solve();
	}
	return 0;
}