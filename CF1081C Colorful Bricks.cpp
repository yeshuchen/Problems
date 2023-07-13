#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n, m, k;
ll fac[10005], inv[10005];
inline int power(ll a, int b)
{
	ll base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return base;
}
inline int C(int n, int m)
{
	return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	for(int i = 1; i <= n; i++) inv[i] = power(fac[i], mod - 2);
	cout << 1ll * C(n - 1, k) * m % mod * power(m - 1, k) % mod;
	return 0;
}