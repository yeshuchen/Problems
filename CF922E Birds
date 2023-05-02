#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, w, b, x;
int c[10005], cost[10005], dp[1005][10005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> w >> b >> x;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> cost[i];
	memset(dp, -1, sizeof(dp));
	int sum = 0; dp[0][0] = w;
	for(int i = 1; i <= n; i++)
	{
		sum += c[i];
		for(int j = 0; j <= sum; j++)
			for(int k = 0; k <= c[i] && k <= j; k++)
			{
				if(dp[i - 1][j - k] == -1) continue;
				if(dp[i - 1][j - k] - k * cost[i] < 0) continue;
				dp[i][j] = max(dp[i][j], min(dp[i - 1][j - k] - k * cost[i] + x, w + j * b));
			}
	}
	int ans;
	for(int i = 0; i <= sum; i++)
		if(dp[n][i] != -1)
			ans = i;
	cout << ans;
	return 0;
}
