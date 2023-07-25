#include<bits/stdc++.h>
using namespace std;
int n, m;
int d[1000005];
int dp[1000005][3][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1, x; i <= n; i++)
		cin >> x, d[x]++;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				for(int l = 0; l < 3; l++)
				{
					if(d[i] < j + k + l) continue;
					dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] +(d[i] - j - k - l) / 3 + l);
				}
	cout << dp[m][0][0];
	return 0;
}