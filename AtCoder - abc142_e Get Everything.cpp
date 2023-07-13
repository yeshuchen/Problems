#include<bits/stdc++.h>
using namespace std;
const int inf = 2e9;
int n, m;
int dp[10005];
int w[1005], f[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int c;
		cin >> w[i] >> c;
		for(int j = 1; j <= c; j++)
		{
			int x;
			cin >> x;
			f[i] |= (1 << x - 1);
		}
	}
	for(int i = 1; i < (1 << n); i++)
		dp[i] = inf;
	for(int i = 0; i < (1 << n); i++)
	{
		if(dp[i] == inf) continue;
		for(int j = 1; j <= m; j++)
			dp[i | f[j]] = min(dp[i | f[j]], dp[i] + w[j]);
	}
	if(dp[(1 << n) - 1] == inf) cout << -1;
	else cout << dp[(1 << n) - 1];
	return 0;
}