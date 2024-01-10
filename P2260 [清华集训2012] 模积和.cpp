#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 19940417;
int n, m, res1, res2;
__int128 S(int x) {return (__int128)x * (x + 1) * (2 * x + 1) / 6;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int l = 1, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		res1 += (r - l + 1) * n - (n / l) * ((r - l + 1) * (l + r) / 2);
		res1 %= mod;
	}
	for(int l = 1, r; l <= m; l = r + 1)
	{
		r = m / (m / l);
		res2 += (r - l + 1) * m - (m / l) * ((r - l + 1) * (l + r) / 2);
		res2 %= mod;
	}
	int ans = res1 * res2 % mod;
	for(int l = 1, r; l <= min(n, m); l = r + 1)
	{
		r = min(n / (n / l), m / (m / l));
		int w = ((r - l + 1) * n % mod * m % mod - n * (m / l) % mod * ((r - l + 1) * (l + r) / 2 % mod) % mod) - m * (n / l) % mod * ((r - l + 1) * (l + r) / 2 % mod) % mod + (__int128)(n / l) * (m / l) % mod * (S(r) - S(l - 1)) % mod;
		ans = ((ans - w) % mod + mod) % mod;
		// cout << l << ' ' << r << ' ' << w << '\n';
	}
	// for(int i = 1; i <= min(n, m); i++) ans = ((ans - (n % i) * (m % i)) % mod + mod) % mod;
	cout << ans << '\n';
	return 0;
}