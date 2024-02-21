#include<bits/stdc++.h>
using namespace std;
int T, n, m;
int a[105];
int f[105][105][105];
int g[105][105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		memset(f, 0x3f, sizeof(f));
		memset(g, 0x3f, sizeof(g));
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			for(int j = 1; j <= m; j++)
			{
				f[i][i][j] = (!(j == a[i]));
				g[i][i][j] = (j == a[i]);
			}
		}
		for(int len = 2; len <= n; len++)
		{
			for(int i = 1; i <= n; i++)
			{
				int j = i + len - 1;
				if(j > n) break;
				for(int k = 1; k <= m; k++)
				{
					for(int l = i; l < j; l++)
					{
						g[i][j][k] = min(g[i][j][k], g[i][l][k] + g[l + 1][j][k]);
						f[i][j][k] = min(f[i][j][k], f[i][l][k] + f[l + 1][j][k]);
					}
					
				}
				for(int k = 1; k <= m; k++)
				{
					for(int l = 1; l <= m; l++)
						g[i][j][k] = min(g[i][j][k], g[i][j][l] + 1);
					f[i][j][k] = min(g[i][j][k] + 1, f[i][j][k]);
				}
			}
		}
		int ans = INT_MAX;
		for(int i = 1; i <= m; i++) ans = min(ans, f[1][n][i]);
		cout << ans << '\n';
	}
	return 0;
}