#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, k;
int ans;
inline int power(int a, int b)
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	if(n == 1 || m == 1)
	{
		cout << power(k, n + m - 1);
		return 0;
	}
	for(int i = 1; i <= k; i++)
	{
		ans = ans + ((power(i, n) - power(i - 1, n)) % mod * power(k - i + 1, m) % mod + mod) % mod;
		ans %= mod;
	}
	cout << ans;
	return 0;
}