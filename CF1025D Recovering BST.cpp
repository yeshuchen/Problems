#include<bits/stdc++.h>
using namespace std;
const int N = 705;
int n, a[N], b[N][N];
int dp[N][N][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], dp[i][i][0] = dp[i][i][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < n; j++)
			b[i][j] = __gcd(a[i], a[j]) > 1;
	for(int len = 2; len <= n; len++)
		for(int i = 1, j = len; j <= n; i++, j++)
		{
			for(int k = i; k < j; k++)
				if(dp[i][k][0] && dp[k + 1][j][1])
				{
					dp[i][j][0] |= b[j][k];
					dp[i][j][1] |= b[k + 1][i];
				}
		}
	for(int i = 1; i <= n; i++)
		if(dp[1][i][1] & dp[i][n][0])
		{
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
}