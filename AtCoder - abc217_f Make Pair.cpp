#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, dp[405][405];
int a[405], b[405], c[405][405], f[405][405];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		f[a][b] = f[b][a] = 1;
	}
	c[0][0] = 1;
	for(int i = 1; i <= (n << 1); i++)
		for(int j = 0; j <= i; j++)
		{
			if(!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	for(int i = 1; i <= (n << 1) + 1; i++)
		dp[i][i - 1] = 1;
	for(int len = 2; len <= (n << 1); len += 2)
		for(int l = 1; l + len - 1 <= (n << 1); l++)
		{
			int r = l + len - 1;
			for(int k = l + 1; k <= r; k += 2)
				if(f[l][k])
					dp[l][r] = (dp[l][r] + dp[l + 1][k - 1] * dp[k + 1][r] % mod * c[len / 2][(r - k + 1) / 2] % mod) % mod;
		}
	cout << dp[1][n << 1];
	return 0;
}