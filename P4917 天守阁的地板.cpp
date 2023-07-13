#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5, mod = 19260817;
int T, n, tot;
ll fac[maxn];
ll vis[maxn], phi[maxn], prime[maxn];
inline int power(ll a, ll b)
{
	ll base = 1;
	while(b)
	{
		if(b & 1) base = 1ll * base * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return base;
}
inline void lineshai()
{
	phi[1] = 1;
	for(int i = 2; i <= maxn - 5; i++)
	{
		if(!vis[i]) prime[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] <= maxn - 5; j++)
		{
			vis[i * prime[j]] = 1;
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			if(i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	for(int i = 1; i <= maxn - 5; i++)
		phi[i] = (phi[i] + phi[i - 1]) % (mod - 1);
	fac[0] = 1;
	for(int i = 1; i <= maxn - 5; i++)
		fac[i] = fac[i - 1] * i % mod;
}
inline ll get(int x)
{
	ll res = 1;
	for(int l = 1, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		res = 1ll * res * power(fac[r] * power(fac[l - 1], mod - 2) % mod, phi[n / r]) % mod;
	}
	return res;
}
int main()
{                                                                                                                                                                                                                                                                                                                      
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	lineshai();
	while(T--)
	{
		cin >> n;
		ll ans = power(fac[n], 2 * n + 2);
		ans = 1ll * ans * power(get(n), mod - 5) % mod;
		cout << ((ans % mod) + mod) % mod << '\n';
	}
	return 0;
}