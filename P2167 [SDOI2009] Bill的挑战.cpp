#include<bits/stdc++.h>
using namespace std;
const int mod = 1000003;
int T, n, k;
int dp[60][1 << 16], f[60][255];
char s[20][55];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> s[i] + 1;
		int len = strlen(s[1] + 1);
		memset(dp, 0, sizeof(dp));
		dp[0][(1 << n) - 1] = 1;
		for(int i = 1; i <= len; i++)
			for(char ch = 'a'; ch <= 'z'; ch++)
			{
				int res = 0;
				for(int j = 1; j <= n; j++)
					{
						if(s[j][i] == '?' || s[j][i] == ch)
							res |= (1 << j - 1);
					}
				f[i][ch] = res;
			}
		for(int i = 1; i <= len; i++)
			for(int k = 1; k < (1 << n); k++)
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					int res = f[i][ch] & k;
					dp[i][res] += dp[i - 1][k];
					if(dp[i][res] >= mod) dp[i][res] -= mod;
				}
		long long ans = 0;
		for(int i = 1; i < (1 << n); i++)
		{
			int res = 0;
			for(int j = 1; j <= n; j++)
				res += (bool)(i & (1 << j - 1));
			if(res == k)
			{
				ans += dp[len][i];
				if(ans >= mod) ans %= mod;
			}
		}
		cout << ans % mod << '\n';
	}
	return 0;
}