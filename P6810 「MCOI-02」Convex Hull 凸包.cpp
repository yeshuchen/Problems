#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, mod, cnt;
int a[N], b[N];
int T[N], e[N], pr[N], vis[N];
void sieve(int V = 2e6)
{
	T[1] = 1;
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) T[i] = 2, e[i] = 1, pr[++cnt] = i;
		for(int j = 1; j <= cnt && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1; e[i * pr[j]] = 1;
			T[i * pr[j]] = T[i] << 1;
			if(i % pr[j] == 0)
			{
				T[i * pr[j]] = T[i] / (e[i] + 1) * (e[i] + 2);
				e[i * pr[j]] = e[i] + 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int ans = 0; sieve();
	cin >> n >> m >> mod;
	if(n > m) swap(n, m);
	for(int i = 1; i <= n; i++) a[i] = T[i];
	for(int i = 1; i <= m; i++) b[i] = T[i];
	for(int i = 1; i <= cnt; i++)
		for(int j = n / pr[i]; j; j--) a[j] = (a[j] + a[j * pr[i]]) % mod;
	for(int i = 1; i <= cnt; i++)
		for(int j = m / pr[i]; j; j--) b[j] = (b[j] + b[j * pr[i]]) % mod;
	for(int i = 1; i <= n; i++)
		ans = (ans + 1ll * a[i] * b[i] % mod) % mod;
	cout << ans;
	return 0;
}