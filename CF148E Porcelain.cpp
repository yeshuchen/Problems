#include<bits/stdc++.h>
using namespace std;
int n, m;
int k[105][105], f[105][105], dp[105][10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int p[105], s[105];
		cin >> k[i][0];
		p[0] = 0; s[k[i][0] + 1] = 0;
		for(int j = 1; j <= k[i][0]; j++)
			cin >> k[i][j];
		int l = 1, r = k[i][0];
		for(int j = 1; j <= k[i][0]; j++) p[j] = p[j - 1] + k[i][j];
		for(int j = k[i][0]; j; j--) s[j] = s[j + 1] + k[i][j];
		for(int j = 1; j <= k[i][0]; j++)
			for(int l = 0; l <= j; l++)
				f[i][j] = max(p[l] + s[k[i][0] - j + l + 1], f[i][j]);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k[i][0]; j++)
			for(int k = m; k >= j; k--)
				dp[i][k] = max(dp[i][k], dp[i - 1][k - j] + f[i][j]);
	cout << dp[n][m];
	return 0;
}
