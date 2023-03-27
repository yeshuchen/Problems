#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
long long f[5005][5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * (j - (i - 1) / m)) % mod;
	for(int i = 1; i <= n; i++)
		cout << f[n][i] << '\n';
	return 0;
}