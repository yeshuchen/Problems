#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
int n, ans, a[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] ^= a[i - 1];
	for(int w = 1; w <= (1 << 30); w <<= 1)
	{
		int res0 = 0, resw = 0, cnt0 = 1, cntw = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] & w) ans += (cnt0 * i - res0) % mod * w % mod, resw += i, cntw++;
			else ans += (cntw * i - resw) % mod * w % mod, res0 += i, cnt0++;
			ans %= mod;
		}
	}
	cout << ans << ' ';
	return 0;
}