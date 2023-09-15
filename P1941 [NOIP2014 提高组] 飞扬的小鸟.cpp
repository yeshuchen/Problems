#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, k;
int x[N], y[N];
int down[N], up[N];
int dp[10005][1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= k; i++)
	{
		int p, l, h;
		cin >> p >> l >> h;
		down[p + 1] = l; up[p + 1] = h;
	}
	for(int i = 1; i <= n + 1; i++)
		for(int j = 0; j <= m; j++)
			dp[i][j] = INT_MAX;
	for(int i = 1; i <= m; i++) dp[1][i] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(dp[i][j] == INT_MAX) continue;
			dp[i + 1][min(j + x[i], m)] = min(dp[i][j] + 1, dp[i + 1][min(j + x[i], m)]);
		}
		for(int j = 1; j <= m; j++)
			dp[i + 1][min(j + x[i], m)] = min(dp[i + 1][min(j + x[i], m)], dp[i + 1][j] + 1);
		for(int j = 1; j <= m - y[i]; j++)
		{
			if(down[i + 1] && j <= down[i + 1] || up[i + 1] && j >= up[i + 1]) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j + y[i]]);
		}
		for(int j = 1; j <= m; j++)
		{
			if(j <= down[i + 1] || up[i + 1] && j >= up[i + 1]) dp[i + 1][j] = INT_MAX;
		}
	}
	int ans = INT_MAX;
	for(int i = 1; i <= m; i++)
		ans = min(ans, dp[n + 1][i]);
	if(ans != INT_MAX) {cout << 1 << '\n' << ans; return 0;}
	else
	{
		int res = 0, cnt = 0;
		cout << 0 << '\n';
		for(int i = 2; i <= n; i++)
		{
			if(down[i] || up[i]) cnt++;
			for(int j = 1; j <= m; j++)
				if(dp[i][j] != INT_MAX)
					res = max(res, cnt);
		}
		cout << res;
	}
	return 0;
}