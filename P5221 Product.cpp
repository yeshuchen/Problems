#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, mod = 104857601;
int T, n, tot, ans;
bool vis[maxn];
int phi[maxn], prime[maxn];
inline int power(int a, int b)
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
inline void lineshai()
{
	phi[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) prime[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] <= n; j++)
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
	for(int i = 1; i <= n; i++)
		phi[i] = (2 * phi[i] + phi[i - 1]) % (mod - 1);
	ans = 1;
	for(int i = 1; i <= n; i++)
		ans = 1ll * ans * i % mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	lineshai();
	ans = power(ans, 2 * n);
	int ans2 = 1;
	for(int i = 2; i <= n; i++)
		ans2 = 1ll * ans2 * power(i, phi[n / i] - 1) % mod;
	cout << 1ll * ans * power(1ll * ans2 * ans2 % mod, mod - 2) % mod << '\n';
	return 0;
}