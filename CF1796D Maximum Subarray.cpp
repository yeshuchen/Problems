#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n, k, x;
int a[200005];
int dp[200005][21];
signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> k >> x;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= k; j++)
				dp[i][j] = -1000000000000000;
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++)
		{
			dp[i][0] = max(dp[i - 1][0] + a[i] - x, 0ll);
			for(int j = 1; j <= min(i, k); j++)
				dp[i][j] = max(max(dp[i - 1][j] + a[i] - x, dp[i - 1][j - 1] + a[i] + x), 0ll);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = max(0ll, k - n + i); j <= k; j++)
			ans = max(ans, dp[i][j]);
		cout << ans << '\n';
	}
	return 0;
}