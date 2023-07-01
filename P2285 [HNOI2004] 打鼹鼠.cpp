#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int dp[100005];
int t[100005], x[100005], y[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> t[i] >> x[i] >> y[i];
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < i; j++)
			if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]) || !j)
				dp[i] = max(dp[i], dp[j] + 1);
	for(int i = 1; i <= m; i++) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}