#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5, mod = 19930726;
char t[N];
int n, p[N];
ll k, d[N];
int ksm(int a, int b)
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
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> t[2 * i];
	for(int i = 1; i <= 2 * n + 1; i += 2) t[i] = '#';
	n = 2 * n + 1; int mx = 0;
	t[0] = '@'; t[n + 1] = '&';
	for(int i = 1; i <= n; i++)
	{
		if(i < mx + p[mx]) p[i] = min(p[2 * mx - i], mx + p[mx] - i);
		while(t[i + p[i]] == t[i - p[i]]) p[i]++;
		if(i + p[i] > mx + p[mx]) mx = i;
	}
	for(int i = 1; i <= n; i++)
	{
		if(p[i] % 2 == 0)
			d[p[i] + 1]--, d[1]++;
	}
	for(int i = 3; i <= n; i += 2)
		d[i] += d[i - 2];
	ll ans = 1;
	for(int i = n; i >= 1; i -= 2)
	{
		ans = ans * ksm(i, min(k, d[i])) % mod;
		k -= min(k, d[i]);
	}
	if(k) ans = -1;
	cout << ans;
	return 0;
}