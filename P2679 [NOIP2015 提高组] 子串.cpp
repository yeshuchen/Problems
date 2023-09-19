#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, m, k;
char s[1005], t[1005];
int f[1005][205][2];
int sum[1005][205], mat[1005][205];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++)
		f[i][0][0] = 1, sum[i][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= min(i, m); j++)
            sum[i][j] += sum[i - 1][j - 1], sum[i][j] %= mod;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= m; i++) cin >> t[i];
    s[0] = '@';
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= min(i, m); j++)
            while(s[i - mat[i][j]] == t[j - mat[i][j]])
                mat[i][j]++;
	for(int l = 1; l <= k; l++)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= min(i, m); j++)
			{
				f[i][j][1] = f[i - 1][j][1];
                if(min(i, j) <= mat[i][j]) f[i][j][1] += sum[i - 1][j - 1];
                else f[i][j][1] += sum[i - 1][j - 1] - sum[i - mat[i][j] - 1][j - mat[i][j] - 1] + mod;
                f[i][j][1] %= mod;
			}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= m; j++)
				f[i][j][0] = f[i][j][1], sum[i][j] = f[i][j][1];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                sum[i][j] += sum[i - 1][j - 1], sum[i][j] %= mod;
	}
	cout << f[n][m][0] % mod;
	return 0;
}