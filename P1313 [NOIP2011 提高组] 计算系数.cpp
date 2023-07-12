#include<bits/stdc++.h>
#define int long long
const int mod = 10007;
using namespace std;
int a, b, k, n, m;
int f[1005][1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int base = 1;
	cin >> a >> b >> k >> n >> m;
	f[0][0] = 1;
	for(int i = 1; i <= k; f[i][0] = 1, i++)
		for(int j = 1; j <= i; j++)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
	for(int i = 1; i <= n; i++) base = base * a % mod;
	for(int i = 1; i <= m; i++) base = base * b % mod;
	cout << base * f[k][n] % mod;
	return 0;
}