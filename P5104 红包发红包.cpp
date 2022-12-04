#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
inline int power(int a, int b)
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long w, n, k;
	cin >> w >> n >> k;
	k = power(2, k);
	cout << w * power(k, mod - 2) % mod;
	return 0;
}