#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 5;
int n, d, k;
int x[N], s[N], q[N], f[N];
inline bool check(int dis)
{
	int h = 1, t = 0, maxn = 0;
	f[1] = s[1]; q[++t] = 1;
	for(int i = 2; i <= n; i++) f[i] = 0;
	for(int i = 2; i <= n; i++)
	{
		int l = max(x[i] - d - dis, 1ll), r = min(x[i] - d + dis, x[i]);
		l = lower_bound(x + 1, x + n + 1, l) - x;
		r = upper_bound(x + 1, x + n + 1, r) - x - 1;
		if(l > r) break;
		while(h <= t && q[h] < l) h++;
		while(h <= t && f[q[t]] <= f[r]) t--;
		q[++t] = r;
		f[i] = f[q[h]] + s[i]; 
		maxn = max(maxn, f[i]);
	}
	return (maxn >= k);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> d >> k;
	int res = 0;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> s[i], res += max(s[i], 0ll);
	if(res < k) {cout << -1 << '\n'; return 0;}
	int l = 0, r = x[n], ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
} 