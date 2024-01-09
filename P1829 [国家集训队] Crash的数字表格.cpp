#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5, mod = 20101009;
int n, m, cnt;
bool vis[N];
int pr[N];
int f[N];
void sieve(int V = 1e7)
{
	f[1] = 1;
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) pr[++cnt] = i, f[i] = 1 - i;
		for(int j = 1; j <= cnt && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1; f[i * pr[j]] = f[i] * (1 - pr[j]);
			if(i % pr[j] == 0) {f[i * pr[j]] = f[i]; break;}
		}
	}
	for(int i = 1; i <= V; i++) f[i] = f[i] * i;
}
int S(int n, int m) {return ((n + 1) * n / 2) % mod * ((m + 1) * m / 2 % mod) % mod;}
void write(__int128 x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
signed main()
{
	sieve();
	cin >> n >> m; __int128 ans = 0;
	for(int i = 1; i <= min(n, m); i++)
		ans = ((ans + (__int128)S(n / i, m / i) * f[i]) % mod + mod) % mod;
	write(ans % mod);
	return 0;
}