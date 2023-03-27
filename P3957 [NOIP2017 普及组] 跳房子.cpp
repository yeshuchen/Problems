#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 5;
int n, d, k;
int x[N], s[N], q[N], f[N];
inline bool check(int dis)
{
	int h = 1, t = 0, pos = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = -1e18;
		int l = max(x[i] - d - dis, 0ll), r = min(x[i] - d + dis, x[i] - 1);
		while(h <= t && x[q[h]] < l) h++;
		while(x[pos] <= r)
		{
			if(x[pos] >= l)
			{
				while(h <= t && f[q[t]] < f[pos]) t--;
				q[++t] = pos; 
			}
			pos++;
		}
		if(h > t) continue;
		f[i] = f[q[h]] + s[i]; 
		if(f[i] >= k) return true;
	}
	return false;
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
	int l = 0, r = max(x[n], d), ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
} 