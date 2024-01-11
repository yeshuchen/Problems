#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, K, p[10005];
int ksm(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
int f[12][10005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> K >> m; K = n - K + 1;
	for(int i = 1; i <= m; i++) cin >> p[i];
	for(int i = 1; i <= K; i++) f[i][0] = -1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = m; j >= p[i]; j--)
			for(int k = K; k; k--)
				f[k][j] = (f[k][j] + f[k - 1][j - p[i]] - f[k][j - p[i]] + mod) % mod;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		ans = (ans + f[K][i] * m % mod * ksm(i, mod - 2) % mod) % mod;
	cout << ans;
	return 0;
}