#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int cnt, pr[N], mu[N], vis[N];
long long g[N];
void sieve(int V = 5e4)
{
	mu[1] = 1;
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) pr[++cnt] = i, mu[i] = -1;
		for(int j = 1; j <= cnt && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1; mu[i * pr[j]] = -mu[i];
			if(i % pr[j] == 0) {mu[i * pr[j]] = 0; break;}
		}
	}
	for(int i = 1; i <= V; i++)
	{
		mu[i] += mu[i - 1];
		for(int l = 1, r; l <= i; l = r + 1)
		{
			r = min(i, i / (i / l));
			g[i] += (r - l + 1) * (i / l);
		}
	}
}
int main()
{
	int T, n, m;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T; sieve();
	while(T--)
	{
		long long ans = 0;
		cin >> n >> m;
		for(int l = 1, r; l <= min(n, m); l = r + 1)
		{
			r = min(n / (n / l), m / (m / l));
			ans += 1ll * (mu[r] - mu[l - 1]) * g[n / l] * g[m / l];
		}
		cout << ans << '\n';
	}
	return 0;
}