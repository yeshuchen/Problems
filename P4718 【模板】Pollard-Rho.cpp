#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937 rnd;
int rd(int l, int r) {return rnd() % (r - l + 1) + l;}
int ksm(int a, int b, int mod)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = (__int128) base * a % mod;
		a = (__int128) a * a % mod;
		b >>= 1;
	}
	return base;
}
bool Miller(int n)
{
	if(n < 3 || n % 2 == 0) return n == 2;
	int d = n - 1, r = 0;
	while(d & 1 ^ 1) d >>= 1, r++;
	for(int _i = 1; _i <= 10; _i++)
	{
		int a = rd(2, n - 1), v = ksm(a, d, n);
		if(v == 1) continue;
		for(int i = 0; i <= r; i++)
		{
			if(i == r) return false;
			if(v == n - 1) break;
			v = (__int128)v * v % n;
		}
	}
	return true;
}
int Pollard(int n) {
	int c = rd(1, n - 1), s = c, t = 0;
	auto f = [&](int x) {return ((__int128) x * x + c) % n;};
	int acc = 0, prod = 1, d, limit = 1;
	while(s != t) {
		if((d = __gcd(abs(s - t), n)) > 1) return d;
    	s = f(f(s)), t = f(t);
  	}
  	if((d = __gcd(prod, n)) > 1) return d;
  	return n;
}
int mxd(int n)
{
	if(Miller(n)) return n;
	if(n == 1) return 1;
	int d = Pollard(n);
	while(n % d == 0) n /= d;
	return max(mxd(n), mxd(d));
}
int T, n;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(Miller(n)) cout << "Prime\n";
		else cout << mxd(n) << '\n';
	}
	return 0;
}