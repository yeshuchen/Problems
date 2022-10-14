#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int a[N], b[N], c[N];
int maxn[N], dp[6005][6005];
vector<int> g[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i], maxn[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		maxn[y] = max(x, maxn[y]);
	}
	for(int i = 1; i <= n; i++)
		g[maxn[i]].push_back(i);
	for(int i = 0; i <= k; i++) dp[0][i] = 0;
	for(int i = 0; i <= 5000; i++)
		for(int j = 0; j <= 5000; j++)
			dp[i][j] = INT_MIN;
	for(int i = 0; i <= k; i++)
		dp[0][i] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(k < a[i])
		{
			cout << -1;
			return 0;
		}
		k += b[i];
		for(int t = a[i]; t + b[i] <= 5000; t++)
			dp[i][t + b[i]] = max(dp[i][t + b[i]], dp[i - 1][t]);
		for(int j = 0; j < g[i].size(); j++)
			for(int k = 0; k < 5000; k++)
				dp[i][k] = max(dp[i][k], dp[i][k + 1] + c[g[i][j]]);
	}
	int ans = 0;
	for(int i = 0; i <= 5000; i++)
		ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
}