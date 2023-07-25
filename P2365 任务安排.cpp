#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, s;
ll t[100005], f[100005];
ll dp[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> f[i], t[i] += t[i - 1], f[i] += f[i - 1];
	for(int i = 1; i <= n; i++) dp[i] = LLONG_MAX;
	dp[0] = s * f[n];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[j - 1] + t[i] * (f[i] - f[j - 1]) + s * (f[n] - f[i]));
	cout << dp[n];
	return 0;
}