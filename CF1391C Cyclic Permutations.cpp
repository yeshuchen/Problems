#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int fac[1000005], f[1000005];
signed main()
{
	cin >> n;
	fac[1] = 1;
	fac[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i % mod;
		f[i] = (i - 2) * fac[i - 1] % mod + 2 * f[i - 1];
		f[i] %= mod;
	}
	cout << f[n];
	return 0;
}