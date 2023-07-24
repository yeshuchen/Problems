#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 8e6 + 5;
int n, mod;
int f[N], sum[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	f[n] = sum[n] = 1;
	for(int i = n - 1; i; i--)
	{
		f[i] = sum[i + 1];
		for(int j = 2; i * j <= n; j++)
			f[i] = (f[i] + sum[i * j] - sum[i * j + j]) % mod;
		sum[i] = (f[i] + sum[i + 1]) % mod;
	}
	cout << f[1];
	return 0;
}