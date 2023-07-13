#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n, m, p;
int fac[200005];
inline int power(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return base;
}
inline int C(int m, int n)
{
	if(m > n) return 0;
	return fac[n] * power(fac[n - m], p - 2) % p * power(fac[m], p - 2) % p;
}
inline int Lucas(int m, int n)
{
	if(!m) return 1;
	return Lucas(m / p, n / p) * C(m % p, n % p) % p;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		fac[0] = 1;
		cin >> n >> m >> p;
		for(int i = 1; i <= n + m; i++) fac[i] = fac[i - 1] * i % p;
		cout << Lucas(n, n + m) << '\n';
	}
	return 0;
}