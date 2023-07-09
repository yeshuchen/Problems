#include<bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
int n, m, ans;
int p[100050];
int c[5005][5005];
signed main()
{
	cin >> n >> m;
	p[0] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = p[i - 1] * m % mod;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			c[i][j] = (c[i - 1][j] * (m - j) + p[i - 2]) % mod;
	int tot = p[n - 1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = (ans + tot - c[i][j] * p[n - i]) % mod;
	cout << (ans % mod + mod) % mod;
	return 0;
}