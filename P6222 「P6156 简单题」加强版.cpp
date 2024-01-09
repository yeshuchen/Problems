#include<bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
int T, n, k, cnt;
int pr[N], vis[N];
unsigned f[N], g[N];
unsigned ksm(unsigned a, int b)
{
	unsigned base = 1;
	while(b)
	{
		if(b & 1) base = base * a;
		a = a * a;
		b >>= 1;
	}
	return base;
}
void sieve(int V = 2 * n)
{
	f[1] = 1; g[1] = 1;
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) pr[++cnt] = i, f[i] = i - 1, g[i] = ksm(i, k);
		for(int j = 1; j <= cnt && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1;
			f[i * pr[j]] = f[i] * f[pr[j]];
			g[i * pr[j]] = g[i] * g[pr[j]];
			if(i % pr[j] == 0)
			{
				if((i / pr[j]) % pr[j]) f[i * pr[j]] = (-f[i / pr[j]] * pr[j]);
				else f[i * pr[j]] = 0;
				break;
			}
		}
	}
	for(int i = 1; i <= V; i++) f[i] = f[i] * g[i], g[i] += g[i - 1];
	for(int i = 1; i <= V; i++) g[i] = (g[i] + g[i - 1]), f[i] += f[i - 1];
}
int G(int x) {return g[2 * x] - 2 * g[x];}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T >> n >> k;
	sieve();
	while(T--)
	{
		cin >> n; unsigned ans = 0;
		for(int l = 1, r; l <= n; l = r + 1)
		{
			r = n / (n / l);
			ans = ans + (f[r] - f[l - 1]) * G(n / l);
		}
		cout << ans << '\n';
	}
	return 0;
}