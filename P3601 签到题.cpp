#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 666623333;
int tot;
bool vis[N];
int prime[N];
inline void lineshai()
{
	vis[1] = 1;
	for(int i = 2; i <= N - 5; i++)
	{
		if(!vis[i]) prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= N - 5; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
long long l, r, ans;
long long phi[N], p[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	lineshai();
	for(int i = 1; i <= r - l + 1; i++)
		phi[i] = i + l - 1, p[i] = 1;
	for(int i = 1; i <= tot; i++)
	{
		long long x = ((l - 1) / prime[i] + 1) * prime[i];
		for(int j = x - l + 1; j <= r - l + 1; j += prime[i])
		{
			long long v = j + l - 1;
			while(v % prime[i] == 0)
				p[j] *= prime[i], v /= prime[i];
			phi[j] = phi[j] / prime[i] * (prime[i] - 1);
		}
	}
	for(int i = 1; i <= r - l + 1; i++)
	{
		long long x = i + l - 1;
		if(x / p[i] > 1)
			phi[i] = phi[i] / (x / p[i]) * (x / p[i] - 1);
		ans += x - phi[i];
		ans %= mod;
	}
	cout << ans;
	return 0;
}