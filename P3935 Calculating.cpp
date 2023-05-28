#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int l, r;
inline int solve(int n)
{
	int ans = 0;
	for(int x = 1, nx; x <= n; x = nx + 1)
	{
		nx = min(n / (n / x), n);
		ans += (nx - x + 1) * (n / x);
		ans %= mod;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	cout << ((solve(r) - solve(l - 1)) % mod + mod) % mod;
	return 0;
}