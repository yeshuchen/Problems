#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 1;
int n, END;
bool vis[N];
int line[N];
int g[N], f[20][5000], dp[20][5000];
inline void con(int x)
{
	f[1][1] = x;
	for(int i = 1; i <= 17; i++)
	{
		if(i > 1) f[i][1] = f[i - 1][1] * 2;
		if(f[i][1] > n) break;
		END = i; line[i] = 1;
		vis[f[i][1]] = 1;
		for(int j = 2; j <= 11; j++)
		{
			f[i][j] = f[i][j - 1] * 3;
			if(f[i][j] > n) break;
			line[i] = j; vis[f[i][j]] = 1;
		}
		line[i] = (1 << line[i]);
	}
}
inline int solve()
{
	int res = 0;
	for(int i = 0; i < line[1]; i++)
		dp[1][i] = g[i];
	for(int i = 2; i <= END; i++)
		for(int j = 0; j < line[i]; j++)
		{
			if(!g[j]) continue;
			dp[i][j] = 0;
			for(int k = 0; k < line[i - 1]; k++)
				if(g[k] && !(j & k))
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
		}
	for(int i = 0; i < line[END]; i++)
		res += dp[END][i], res %= mod;
	return res;
}
inline bool check(int x)
{
	for(int i = 1; i < 11; i++)
		if((x & 1 << i) && (x & 1 << i - 1))
			return false;
	return true;
}
signed main()
{
	long long ans = 1;
	cin >> n;
	for(int i = 0; i < (1 << 11); i++)
		if(check(i))
			g[i] = 1;
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			con(i);
			ans = ans * solve() % mod;
		}
	cout << ans << '\n';
	return 0;
}