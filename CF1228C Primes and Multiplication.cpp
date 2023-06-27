#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int x, n, tot;
int p[1000005];
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
	cin >> x >> n;
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i != 0) continue;
		while(x % i == 0) x /= i;
		p[++tot] = i;
	}
	if(x > 1) p[++tot] = x;
	int ans = 1;
	for(int i = 1; i <= tot; i++)
		for(int w = n; w; w /= p[i])
			ans = ans * power(p[i], w / p[i]) % mod;
	cout << ans;
	return 0;
}