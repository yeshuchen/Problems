#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, k;
int f[5005][5005];
int x[5005], y[5005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> x[i] >> y[i];
	f[0][1] = 1;
	for(int i = 1; i <= k; i++)
	{
		int sum = 0;
		for(int j = 1; j <= n; j++)
			sum += f[i - 1][j];
		for(int j = 1; j <= n; j++)
			f[i][j] = sum - f[i - 1][j];
		for(int j = 1; j <= m; j++)
			f[i][x[j]] -= f[i - 1][y[j]], f[i][y[j]] -= f[i - 1][x[j]];
		for(int j = 1; j <= n; j++)
			f[i][j] %= mod;
	}
	cout << f[k][1];
	return 0;
}