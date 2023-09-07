#include<bits/stdc++.h>
using namespace std;
int n, m, mx = 5e5;
int dp[500005];
int a[500005], b[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - b - 1;
	if(n == 1) {cout << 0 << '\n'; return 0;}
	memset(dp, -1, sizeof(dp));
	int gcd = a[1]; dp[1] = 0;
	for(int i = 1; i <= n; i++) gcd = __gcd(gcd, a[i]);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= mx / b[i]; j++)
		{
			if(dp[j] == -1) continue;
			if(dp[j * b[i]] == -1 || dp[j * b[i]] > dp[j] + 1)
				dp[j * b[i]] = dp[j] + 1;
		}
	}
	int ans = INT_MAX;
	for(int i = 1; i <= gcd; i++)
	{
		bool f = 0; int res = 0;
		if(gcd % i) continue;
		for(int j = 1; j <= n; j++)
		{
			if(dp[a[j] / i] == -1) f = 1;
			else res += dp[a[j] / i];
		}
		if(!f) ans = min(ans, res);
	}
	if(ans == INT_MAX) ans = -1;
	cout << ans;
	return 0;
}