#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, a[N];
int f[N][N], dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], dp[i][i] = a[i], f[i][i] = 1;
	for(int len = 2; len <= n; len++)
		for(int i = 1; i <= n; i++)
		{
			int j = i + len - 1;
			if(j > n) break;
			f[i][j] = INT_MAX;
			for(int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
				if(f[i][k] == 1 && f[k + 1][j] == 1 && dp[i][k] == dp[k + 1][j])
					f[i][j] = 1, dp[i][j] = dp[i][k] + 1;
			}
		}
	cout << f[1][n];
	return 0;
}