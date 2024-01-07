#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m, P, q, qk;
int exgcd(int a, int b, int &x, int &y)
{
	if(a % b == 0) return x = 0, y = 1, b;
	int g = exgcd(b, a % b, x, y), z = x;
	x = y; y = z - a / b * y;
	return g;
}
int ksm(int a, int b, int mod)
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
int fac[N];
int inv(int a, int p) {int x; return exgcd(a, p, x, *new int), (x % p + p) % p;}
int num(int n) {int s = 0; while(n) s += (n /= q); return s;}
int calc(int n) {return n ? calc(n / qk) * fac[n % qk] % qk * ksm(fac[qk - 1], n / qk, qk) % qk : 1;}
int solve()
{
	for(int i = fac[0] = 1; i < qk; i++) fac[i] = fac[i - 1] * (i % q ? i : 1) % qk;
	int pw = num(n) - num(m) - num(n - m);
	int ans = calc(n) * inv(calc(m) * calc(n - m) % qk, qk) % qk;
	while(pw--) ans = ans * q % qk;
	return ans;
}
int exLucas()
{
	int MOD = 1, ans = 0;
	for(int i = 2; i * i <= P; i++)
	{
		if(P % i) continue;
		q = i; qk = 1;
		while(P % i == 0) qk *= i, P /= i;
		int w = ((solve() - ans) % qk + qk) % qk;
		ans = (ans + inv(MOD, qk) * w % qk * MOD); ans %= (MOD *= qk);
	}
	if(P > 1)
	{
		q = qk = P;
		int w = ((solve() - ans) % qk + qk) % qk;
		ans = (ans + inv(MOD, qk) * w % qk * MOD); ans %= (MOD *= qk);
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> P;
	cout << exLucas();
	return 0;
}