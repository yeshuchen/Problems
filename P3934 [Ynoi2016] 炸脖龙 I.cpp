#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e7 + 5;
int n, m, tot;
bool vis[N];
int prime[N], phi[N];
ll a[N], c[N];
inline void add(ll x, ll k){while(x <= n) c[x] += k, x += (x & -x);}
inline ll ask(ll x)
{
	ll res = 0;
	while(x) res += c[x], x -= (x & -x);
	return res;
}
inline ll power(ll a, ll b, ll mod)
{
	ll base = 1, flag = 0;
	a %= mod;
	while(b)
	{
		if(b & 1)
		{
			base = base * a;
			if(base > mod) flag = 1, base %= mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return base + flag * mod;
}
inline ll solve(ll l, ll r, ll mod)
{
	if(l == r + 1 || mod == 1) return 1;
	ll t = solve(l + 1, r, phi[mod]);
	return power(a[l] + ask(l), t, mod);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	phi[1] = 1;
	n = N - 5;
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) prime[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && prime[j] * i <= n; j++)
		{
			vis[i * prime[j]] = 1; phi[i * prime[j]] = (phi[i] * (prime[j] - 1));
			if(i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		ll op, l, r, x;
		cin >> op >> l >> r >> x;
		if(op == 1)
		{
			add(l, x);
			add(r + 1, -x);
		}
		else
			cout << solve(l, r, x) % x << '\n';
	}
	return 0;
}