#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int T;
int d[N], fac[N], inv[N];
inline int C(int n, int m) {return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;}
inline int qpow(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = 1ll * base * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return base;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= 1000000; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
	for(int i = 1; i <= 1000000; i++) inv[i] = qpow(fac[i], mod - 2);
	d[0] = 1; d[1] = 0;
	for(int i = 2; i <= 1000000; i++) d[i] = 1ll * (i - 1) * (d[i - 1] + d[i - 2]) % mod;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		cout << 1ll * C(n, m) * d[n - m] % mod << '\n';
	}
	return 0;
}