#include<bits/stdc++.h>
using namespace std;
inline int Phi(int x)
{
	int n = x;
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i != 0) continue;
		n = n / i * (i - 1);
		while(x % i == 0) x /= i;
	}
    if(x > 1) n = n / x * (x - 1);
	return n;
}
inline int power(int a, int b, int mod)
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
inline int solve(int x)
{
	if(x == 1) return 0;
	int phi = Phi(x);
	return power(2, solve(phi) + phi, phi);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int p;
		cin >> p;
		cout << solve(p) << '\n';
	}
	return 0;
}