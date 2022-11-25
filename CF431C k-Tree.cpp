#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, k, d;
int f[105], c[105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> d;
	f[0] = c[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= min(i, k); j++)
			f[i] = (f[i] + f[i - j]) % mod;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= min(i, d - 1); j++)
			c[i] = (c[i] + c[i - j]) % mod;
	cout << ((f[n] - c[n]) % mod + mod) % mod;
	return 0;
}