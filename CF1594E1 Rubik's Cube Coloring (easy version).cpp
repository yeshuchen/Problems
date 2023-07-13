#include<bits/stdc++.h>
const int mod = 1e9 + 7;
#define int long long
using namespace std;
inline int power(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return base;
}
int n;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cout << 6 * power(4, (1ll << n) - 2) % mod;
	return 0;
}