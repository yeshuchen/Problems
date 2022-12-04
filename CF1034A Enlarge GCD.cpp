#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, maxn = 4000;
int n, tot, GCD;
bool vis[maxn];
int a[N], d[N * 10], prime[N];
inline void lineshai()
{
	for(int i = 2; i <= maxn; i++)
	{
		if(!vis[i]) prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	lineshai();
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	GCD = a[1];
	for(int i = 1; i <= n; i++)
		GCD = __gcd(GCD, a[i]);
	bool f = 0;
	for(int i = 2; i <= n; i++)
		if(a[i] != a[i - 1])
			f = 1;
	if(!f) {cout << -1; return 0;}
	int MAX = 0;
	for(int i = 1; i <= n; i++)
	{
		a[i] /= GCD;
		MAX = max(MAX, a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= tot; j++)
		{
			if(a[i] % prime[j] != 0) continue;
			while (a[i] % prime[j] == 0)
				a[i] /= prime[j];
			d[prime[j]]++;
		}
		if(a[i] > 1) d[a[i]]++;
	}
	int ans = INT_MAX;
	for(int i = 2; i <= MAX; i++)
		ans = min(ans, n - d[i]);
	cout << ans;
	return 0;
}