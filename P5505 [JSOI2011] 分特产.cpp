#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, m;
int a[2005];
long long c[2005][2005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	c[0][0] = 1;
	for(int i = 1; i <= 2000; i++)
		for(int j = 1; j <= 2000; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	long long ans = 0;
	for(int i = 0; i <= n - 1; i++)
	{
		int cnt = 1;
		for(int j = 1; j <= m; j++)
			cnt = 1ll * cnt * c[n + a[j] - i][n - i] % mod;
		if(i % 2) ans = (ans - 1ll * cnt * c[n + 1][i + 1] % mod + mod) % mod;
		else ans = (ans + 1ll * cnt * c[n + 1][i + 1]) % mod;
	}
	cout << ans;
	return 0;
}