#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int dp[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		for(int j = m; j >= w; j--)
			dp[j] = max(dp[j], dp[j - w] + v);
	}
	cout << dp[m];
	return 0;
}