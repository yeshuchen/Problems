#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int qpow(int a, int b)
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
map<int, int> mp;
int solve(int x)
{
	int res = qpow(2, x - 1);
	if(x == 1) return 1;
	if(mp[x]) return mp[x];
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i) continue;
		res = res - solve(x / i);
		if(i != x / i) res = res - solve(i);
		res = (res % mod + mod) % mod;
	}
	res = res - solve(1);
	res = (res % mod + mod) % mod;
	mp[x] = res;
	return mp[x];
}
signed main()
{
	int x, y;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> x >> y;
	if(y % x) {cout << 0; return 0;}
	cout << solve(y / x);
	return 0;
}