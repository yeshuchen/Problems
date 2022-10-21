#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int tot;
int vis[N], phi[N], prime[N];
bool v[2 * N];
inline void lineshai()
{
	phi[1] = 1;
	for(int i = 2; i <= 1000000; i++)
	{
		if(!vis[i]) prime[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] <= 1000000; j++)
		{
			vis[i * prime[j]] = 1; phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			if(i % prime[j] == 0) {phi[i * prime[j]] = phi[i] * prime[j]; break;}
		}
	}
	v[2] = 1;
	v[4] = 1;
	for(int i = 2; i <= tot; i++)
	{
		long long base = 1;
		for(int j = 1; base * prime[i] <= 1000000; j++)
			base *= prime[i], v[base] = v[2 * base] = 1;
	}
}
inline int power(int a, int b, int mod)
{
	long long base = 1;
	while(b)
	{
		if(b & 1) base = base * a % mod;
		b >>= 1;
		a = 1ll * a * a % mod;
	}
	return base;
}
int res;
int p[N];
inline void shai(int x)
{
	res = 0;
	for(int i = 1; 1ll * prime[i] * prime[i] <= x; i++)
	{
		if(x % prime[i] != 0) continue;
		while(x % prime[i] == 0)
			x /= prime[i];
		p[++res] = prime[i];
	}
	if(x > 1) p[++res] = x;
}
int T;
int ans[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	lineshai();
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		long long n, d, ming;
		cin >> n >> d;
		if(!v[n]) {cout << 0 << '\n' << '\n'; continue;}
		shai(phi[n]);
		for(int i = 1; i < n; i++)
		{
			bool flag = 1;
			if(__gcd(1ll * i, n) != 1) continue;
			for(int j = 1; j <= res; j++)
			{
				if(power(i, phi[n] / p[j], n) == 1)
				{
					flag = 0;
					break;
				}
			}
			if(flag) {ming = i; break;}
		}
		long long base = 1;
		for(int i = 1; i <= phi[n]; i++)
		{
			base = base * ming % n;
			if(__gcd(i, phi[n]) != 1) continue;
			ans[++cnt] = base;
		}
		sort(ans + 1, ans + cnt + 1);
		cout << cnt << '\n';
		for(int i = d; i <= cnt; i += d)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}